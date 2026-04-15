/*************************************************
 * ESP32 + SIM800L
 * RX=21 TX=22
 * Auto Send + RTC Internal + Debug HTTP
 *************************************************/

#define TINY_GSM_MODEM_SIM800
#define TINY_GSM_USE_GPRS true

#include <TinyGsmClient.h>
#include <Arduino.h>
#include <time.h>

// ================= SERIAL =================
#define SerialMon Serial
#define SerialAT  Serial1

// ================= MODEM ==================
TinyGsm modem(SerialAT);
TinyGsmClient client(modem);

// ================= APN ====================
const char apn[]  = "internet";
const char user[] = "";
const char pass[] = "";

// ================= API ====================
const char host[] = "bot.ndpteknologi.com";
const int  port   = 80;

extern char tenantId[];
extern char deviceId[];

// ================= INTERVAL ===============
// Default 15 menit (global di file utama)
extern unsigned long SEND_INTERVAL;

// ================= SENSOR =================
// WaterLevel dan iSignal dideklarasikan sebagai extern (global di file utama)
extern float WaterLevel;
extern int iSignal;

// ================= RTC ====================
extern bool timeSynced;


// =================================================
// MODEM
// =================================================
void setupModem() {

  SerialMon.println("Init Modem...");

  SerialAT.begin(9600, SERIAL_8N1, 21, 22);
  vTaskDelay(1000 / portTICK_PERIOD_MS);

  modem.restart();
  vTaskDelay(1000 / portTICK_PERIOD_MS);

  if (!modem.waitForNetwork(60000L)) {
    SerialMon.println("Network FAIL!");
    return;
  }

  SerialMon.println("Network OK");
}


// =================================================
// GPRS
// =================================================
bool setupGPRS() {

  SerialMon.println("Connect GPRS...");

  if (!modem.gprsConnect(apn, user, pass)) {
    SerialMon.println("GPRS FAIL!");
    return false;
  }

  SerialMon.println("GPRS OK");
  return true;
}


// =================================================
// RSSI
// =================================================
void getRSSI() {

  int r = modem.getSignalQuality();

  if (r >= 0 && r <= 31) iSignal = r;
  else iSignal = 99;

  SerialMon.print("RSSI: ");
  SerialMon.println(iSignal);
}


// =================================================
// PARSE DATE HEADER
// =================================================
time_t parseDate(String d) {

  int day, year, h, m, s;
  char mon[4];

  sscanf(d.c_str(),
        "%*3s, %d %3s %d %d:%d:%d",
        &day, mon, &year, &h, &m, &s);

  int month = 0;
  const char* mlist = "JanFebMarAprMayJunJulAugSepOctNovDec";

  char* p = strstr(mlist, mon);
  if (p) month = (p - mlist) / 3 + 1;

  struct tm t;

  t.tm_year = year - 1900;
  t.tm_mon  = month - 1;
  t.tm_mday = day;
  t.tm_hour = h;
  t.tm_min  = m;
  t.tm_sec  = s;

  return mktime(&t);
}


// =================================================
// SYNC RTC ESP32
// =================================================
void syncRTC(time_t srv) {

  if (srv < 1700000000) return;

  struct timeval tv;

  tv.tv_sec  = srv + (7 * 3600); // WIB
  tv.tv_usec = 0;

  settimeofday(&tv, NULL);

  timeSynced = true;

  SerialMon.println("RTC Synced");
}


// =================================================
// SEND DATA + PRINT RESPONSE
// =================================================
bool sendData() {

  getRSSI();

  SerialMon.println("\n>>> Connect Server");

  if (!client.connect(host, port)) {
    SerialMon.println("Server FAIL!");
    return false;
  }

  // ================= URL DENGAN PARAM =================
  char url[256];

  snprintf(url, sizeof(url),
          "/api/v1/telemetry?tenantId=%s&deviceId=%s&wl=%.2f&rssi=%d",
          tenantId,
          deviceId,
          WaterLevel,
          iSignal);

  SerialMon.println("POST URL:");
  SerialMon.println(url);


  // ================= SEND POST =================
  client.print(String("POST ") + url + " HTTP/1.1\r\n");
  client.print(String("Host: ") + host + "\r\n");
  client.print("User-Agent: ESP32-SIM800L\r\n");
  client.print("Connection: close\r\n\r\n");


  // ================= HEADER =================
  SerialMon.println("\n---- HTTP HEADER ----");

  String dateHeader = "";
  int httpStatus = 0;

  unsigned long timeout = millis() + 10000;

  while (millis() < timeout) {

    if (!client.available()) continue;

    String line = client.readStringUntil('\n');

    SerialMon.print(line);

    if (line.startsWith("HTTP/")) {
      httpStatus = line.substring(9,12).toInt();

      SerialMon.print(">> STATUS = ");
      SerialMon.println(httpStatus);
    }

    if (line.startsWith("Date:")) {
      dateHeader = line.substring(6);
      dateHeader.trim();
    }

    if (line == "\r") break;
  }


  // ================= BODY =================
  SerialMon.println("---- HTTP BODY ----");

  String body = "";

  timeout = millis() + 6000;

  while (millis() < timeout) {
    while (client.available()) {
      body += (char)client.read();
    }
  }

  SerialMon.println(body);

  client.stop();

  SerialMon.println("---------------------");


  // ================= SYNC RTC =================
  if (dateHeader.length()) {

    time_t srv = parseDate(dateHeader);

    if (srv > 0) syncRTC(srv);
  }


  // ================= RESULT =================
  if (httpStatus >= 200 && httpStatus < 300) {

    SerialMon.print("** SUCCESS! STATUS=");
    SerialMon.println(httpStatus);

    return true;
  }

  SerialMon.print("** FAILED! STATUS=");
  SerialMon.println(httpStatus);

  return false;
}



// =================================================
// SCHEDULE - Kirim setiap kelipatan 15 menit (00, 15, 30, 45)
// =================================================
bool timeToSend() {

  time_t now;
  time(&now);
  
  // Cek apakah waktu valid (tidak tahun 1970 = belum sync)
  if (now < 1700000000) {
    return false;  // RTC belum sync, tunggu dulu
  }

  static time_t lastTrigger = 0;

  if (SEND_INTERVAL < 60) {
    return false;
  }

  if ((now % SEND_INTERVAL) == 0 && now != lastTrigger) {
    lastTrigger = now;
    return true;
  }

  return false;
}

