
#include "DefineBitmap.h"
#include "WebServer.h"
#include <WiFi.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Preferences.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#ifndef DEVICE_ID
#define DEVICE_ID "D01"
#endif

// ========================================
// MENU DEFINITIONS
// ========================================
#define MENU_HOME1 1
#define MENU_SETTING 2

#define TFT_WIDTH 480 
#define TFT_HEIGHT 320

// ========================================
// TASK HANDLES
// ========================================
TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;
TaskHandle_t Task4;
TaskHandle_t Task5;

// ========================================
// GLOBAL VARIABLES - TOUCH & MENU
// ========================================
uint16_t t_x = 0, t_y = 0;
int Menu;
int Last_Menu;
bool pressed;
bool Last_pressed;
bool PressSettingBT;
bool Last_PressSettingBT;
bool PressHomeBT;
bool Last_PressHomeBT;
int Counter1s;

char WL_Text [20];
char Last_WL_Text [20];
char CalibM_Text[20];
char Last_CalibM_Text[20];
char CalibC_Text[20];
char Last_CalibC_Text[20];
char Interval_Text[20];
char Last_Interval_Text[20];
char LastSendLine1_Text[20];
char Last_LastSendLine1_Text[20];
char LastSendLine2_Text[32];
char Last_LastSendLine2_Text[32];
char Ap_Text[24];
char Last_Ap_Text[24];
char Rssi_Text[20];
char Last_Rssi_Text[20];
// Format float → string 1 digit desimal
// ========================================
// GLOBAL VARIABLES - DISPLAY DATA
// ========================================
// float waterLevel = 125.0;  // cm
float Last_waterLevel = 999.9;  // cm
float WaterLevel;
float calibM = 1.0f;
float calibC = 0.0f;
int intervalMinute = 15;
int webServerTimeoutMinute = 5;
unsigned long SEND_INTERVAL = 15 * 60;
char tenantId[24] = "001";
char deviceId[24] = "D01";
char locationName[32] = "";
bool wifiConnected = false;
int iSignal = 0;  // RSSI signal quality (global variable)
bool homeFirstDraw = true;
bool lastApActive = false;

unsigned long webServerStartMillis = 0;
unsigned long webServerStopAtMillis = 0;
unsigned long webServerTimeoutMs = 5UL * 60UL * 1000UL;

// ========================================
// WIFI ACCESS POINT CONFIGURATION
// ========================================
const char* ssidAP = "Water Level NDP";
const char* passwordAP = "password123";

// ========================================
// WEB SERVER CONFIGURATION
// ========================================
AsyncWebServer server(80);
bool webServerActive = false;
bool webServerStartRequested = false;
bool webServerStopRequested = false;

// ========================================
// PREFERENCES CONFIGURATION
// ========================================
Preferences preferences;
// ================= RTC =====================
RTC_DATA_ATTR time_t lastSendTime = 0;
RTC_DATA_ATTR bool   timeSynced   = false;

// ========================================
// MAC ADDRESS VERIFICATION
// ========================================
#define NUMBER_OF_DEVICE_RESGISTERED 1 
char MergedMacAddress[13];
const char allowedMACAddress[NUMBER_OF_DEVICE_RESGISTERED][13]={
  "2043A8641380"
};
void vPrepareID(){
  unsigned char mac[6];
  WiFi.macAddress(mac);
  sprintf(MergedMacAddress, "%02X%02X%02X%02X%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  Serial.print("MergedMacAddress:  ");
  Serial.println(String(MergedMacAddress));
}
void vCheckMACAddress(){
  vPrepareID();
  bool notFound=1;
  for (int i=0; i<NUMBER_OF_DEVICE_RESGISTERED&&notFound;i++){
    if(strcmp(MergedMacAddress,allowedMACAddress[i])==0){
      notFound=0;
      Serial.println("MAC Found");
    }
  }
  if (notFound){
    Serial.println("GAGAL ");
    vHomeUpload();
    while(1); 
  }
}

// ========================================
// FUNGSI DISPLAY SETUP
// ========================================
void vDisplaySetup(){
  Serial.println("Display Setup");
  uint16_t calData[5] = { 236, 3589, 264, 3519, 6 };
  tft.init();
  tft.setRotation(1);
  tft.setTouch(calData);
  tft.fillScreen(TFT_BLACK);
}
// ========================================
// BUTTON CONFIGURATION
// ========================================
//SETTING BUTTON
#define SETTING_BT_X 438
#define SETTING_BT_Y 270
#define SETTING_BT_W 45
#define SETTING_BT_H 95
//HOME BUTTON
#define HOME_BT_X 0
#define HOME_BT_Y 270
#define HOME_BT_W 48
#define HOME_BT_H 95

// ========================================
// FUNGSI MENU TOUCH HANDLING
// ========================================
void vHomeMenu1Touch(){
  vSettingBT();
}
void vSettingMenu2Touch(){
  vHomeBT();
  vSettingBT();
}
// ========================================
// FUNGSI HOME BUTTON
// ========================================
void vPressedHomeBT(){
  if (pressed && t_x>HOME_BT_X && t_x<(HOME_BT_X+HOME_BT_W) && t_y>HOME_BT_Y && t_y<(HOME_BT_Y+HOME_BT_H)){
    PressHomeBT = 1;
  } else{
    PressHomeBT = 0;
  }
}
void vHomeBT(){
  vPressedHomeBT();
  if (Last_PressHomeBT != PressHomeBT){
    Last_PressHomeBT = PressHomeBT;
    if (PressHomeBT == 1){
      Menu = MENU_HOME1;
    }
  }
}
// ========================================
// FUNGSI SETTING BUTTON
// ========================================
void vPressedSettingBT(){
  if (pressed && t_x>SETTING_BT_X && t_x<(SETTING_BT_X+SETTING_BT_W) && t_y>SETTING_BT_Y && t_y<(SETTING_BT_Y+SETTING_BT_H)){
    PressSettingBT = 1;
  } else{
    PressSettingBT = 0;
  }
}
void vSettingBT(){
  vPressedSettingBT();
  if (Last_PressSettingBT != PressSettingBT){
    Last_PressSettingBT = PressSettingBT;
    if (PressSettingBT == 1){
      if(Menu == MENU_HOME1){
        Menu = MENU_SETTING;
      }
      else if(Menu == MENU_SETTING){
        Serial.println("Starting Web Server for Configuration");
        webServerStartRequested = true;
        if (WiFi.status() != WL_CONNECTED){
          Serial.println("WiFi not connected to network");
        }
        else{
          Serial.println("WiFi connected to network");
        }
      }
    }
  }
}

// ========================================
// FUNGSI TOUCHSCREEN INPUT
// ==
void vPressedTouchscreen(){
  pressed = tft.getTouch(&t_x, &t_y);
}
void vCekPressTouch(){
  if (Menu == MENU_HOME1){
    vHomeMenu1Touch();
  }
  else if (Menu == MENU_SETTING){
    vSettingMenu2Touch();
  }
}

// ========================================
// FUNGSI MENU MANAGEMENT WITH SMOOTH TRANSITION
// ========================================
void vCekMenuDisplay(){
  if (Last_Menu != Menu){
    Last_Menu = Menu;
    if (Menu == MENU_HOME1){
      vHome1BG();
      homeFirstDraw = true;
      Last_LastSendLine1_Text[0] = '\0';
      Last_LastSendLine2_Text[0] = '\0';
      Last_Rssi_Text[0] = '\0';
      webServerStartRequested = false;
      webServerStopRequested = false;
      vStopWebServer();
      vHome1Realtime();
    }
    else if (Menu == MENU_SETTING){
      vSettingMenu2();
      Last_CalibM_Text[0] = '\0';
      Last_CalibC_Text[0] = '\0';
      Last_Interval_Text[0] = '\0';
      Last_Ap_Text[0] = '\0';
      lastApActive = !webServerActive;
      vSettingMenu2Realtime();
    }
  }
}

void vCekDisplayRealtime(){
  if (Menu == MENU_HOME1){
    vHome1Realtime();
  }
  else if (Menu == MENU_SETTING){
    vSettingMenu2Realtime();
  }
}

// ========================================
// RGB565 COLOR HELPER MACRO
// ========================================
#define RGB565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

// ========================================
// THEME COLOR DEFINITIONS - BLUE THEME
// ========================================
// Primary Colors (Blue Theme)
#define COLOR_PRIMARY_DARK      RGB565(11, 67, 122)      // Dark blue
#define COLOR_PRIMARY_MEDIUM    RGB565(70, 130, 180)     // Steel blue
#define COLOR_PRIMARY_LIGHT     RGB565(146, 213, 240)    // Sky blue
#define COLOR_BG_MAIN           RGB565(208, 238, 247)    // Light blue background

// Secondary Colors
#define COLOR_ACCENT_ORANGE     RGB565(255, 210, 32)     // Bright orange
#define COLOR_ACCENT_GREEN      RGB565(0, 255, 0)        // Bright green
#define COLOR_ACCENT_RED        RGB565(248, 0, 0)        // Bright red

// Text Colors
#define COLOR_TEXT_WHITE        RGB565(255, 255, 255)    // White
#define COLOR_TEXT_BLACK        RGB565(0, 0, 0)          // Black
#define COLOR_TEXT_GRAY         RGB565(189, 247, 187)    // Light gray
#define COLOR_TEXT_DARK_GRAY    RGB565(100, 150, 100)    // Dark gray

// Legacy Definitions (for compatibility)
#define COLOR_BG_DARK           RGB565(0, 0, 0)          // Black
#define COLOR_HEADER            RGB565(49, 129, 131)     // Dark teal/blue
#define COLOR_BUTTON            RGB565(41, 69, 85)       // Dark blue button
#define COLOR_TEXT              RGB565(255, 255, 255)    // White
#define COLOR_VALUE             RGB565(255, 224, 0)      // Yellow
#define COLOR_ACCENT            RGB565(0, 255, 0)        // Green



// ========================================
// TRANSITION VARIABLES
// ========================================
unsigned long transitionStartTime = 0;
const unsigned long transitionDuration = 300;  // 300ms transition time

// ========================================
// FUNGSI PREFERENCES
// ========================================
void vUpdateSendInterval() {
  if (intervalMinute < 1) intervalMinute = 1;
  SEND_INTERVAL = (unsigned long)intervalMinute * 60UL;
  if (SEND_INTERVAL < 60UL) SEND_INTERVAL = 60UL;
}

void vUpdateWebServerTimeout() {
  if (webServerTimeoutMinute < 1) webServerTimeoutMinute = 1;
  webServerTimeoutMs = (unsigned long)webServerTimeoutMinute * 60UL * 1000UL;
}

void vPreferences_LoadSettings(){
  preferences.begin("waterLevel", true);  // true = read-only mode
  calibM = preferences.getFloat("calibM", 1.0f);
  calibC = preferences.getFloat("calibC", 0.0f);
  intervalMinute = preferences.getInt("interval", 15);
  webServerTimeoutMinute = preferences.getInt("web_on", 5);
  String tenantStr = preferences.getString("tenantId", "001");
  String deviceStr = preferences.getString("deviceId", "D01");
  String locationStr = preferences.getString("location", "");
  preferences.end();

  tenantStr.toCharArray(tenantId, sizeof(tenantId));
  deviceStr.toCharArray(deviceId, sizeof(deviceId));
  locationStr.toCharArray(locationName, sizeof(locationName));

  vUpdateSendInterval();
  vUpdateWebServerTimeout();
  
  Serial.println("Settings loaded from Preferences");
  Serial.printf("M: %.2f, C: %.2f, Interval: %d, WebTimeout: %d\n",
                calibM, calibC, intervalMinute, webServerTimeoutMinute);
}

void vPreferences_SaveSettings(){
  preferences.begin("waterLevel", false);  // false = read-write mode
  preferences.putFloat("calibM", calibM);
  preferences.putFloat("calibC", calibC);
  preferences.putInt("interval", intervalMinute);
  preferences.putInt("web_on", webServerTimeoutMinute);
  preferences.putString("tenantId", tenantId);
  preferences.putString("deviceId", deviceId);
  preferences.putString("location", locationName);
  preferences.end();
  
  Serial.println("Settings saved to Preferences");
}

// ========================================
// FUNGSI WEB SERVER ASYNCHRONOUS
// ========================================

void vSetupWebServer(){
  setupWebServerRoutes(server);
  server.begin();
  webServerActive = true;
  Serial.println("Web Server started on http://192.168.4.1");
}

void vStartWebServer(){
  if(!webServerActive){
    WiFi.softAP(ssidAP, passwordAP);
    Serial.println("AP Mode activated");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());
    webServerStartMillis = millis();
    webServerStopAtMillis = webServerStartMillis + webServerTimeoutMs;
    vSetupWebServer();
  }
}

void vStopWebServer(){
  if(webServerActive){
    server.end();
    WiFi.softAPdisconnect(true);
    webServerActive = false;
    webServerStartMillis = 0;
    webServerStopAtMillis = 0;
    Serial.println("Web Server stopped");
  }
}

// ========================================
// FUNGSI DISPLAY HOME MENU 1
// ========================================


void vHome1BG() {
    tft.fillScreen(0xDFFF);
    tft.fillRoundRect(54, 3, 372, 56, 15, 0x2C);
    tft.fillRoundRect(57, 5, 366, 52, 15, 0x7EBE);
    tft.fillRoundRect(17, 71, 447, 178, 12, 0x2C);
    tft.fillRoundRect(20, 74, 440, 171, 12, 0x7EBE);
    tft.setTextColor(0x2C);
    tft.setTextSize(1);
    tft.setFreeFont(&FreeMonoBold18pt7b);
    tft.drawString("WATER LEVEL", 125, 16);
    // tft.setTextSize(3);
    // tft.setFreeFont(&FreeSansBold24pt7b);
    // tft.drawString("300", 122, 88);
    tft.setTextSize(1);
    tft.setFreeFont(&FreeMonoBold12pt7b);
    tft.drawString("METER", 205, 224);
    tft.fillRoundRect(428, 268, 52, 52, 10, 0x2C);
    tft.fillRoundRect(431, 270, 46, 47, 10, 0x7EBE);
    tft.drawBitmap(441, 279, image_menu_tools_bits, 28, 32, 0x2C);
}

int getWLPosX(float val) {

  if (val >= 100.0) {
    return 66;     // 3 digit
  }
  else if (val >= 10.0) {
    return 105;    // 2 digit
  }
  else {
    return 144;    // 1 digit
  }

}

int getCenteredX(const char *text, int boxX, int boxW) {
  int w = tft.textWidth(text);
  int x = boxX + (boxW - w) / 2;
  if (x < boxX) x = boxX;
  return x;
}

void vUpdateTextCentered(const char *newText,
                         char *lastText,
                         size_t lastTextSize,
                         int boxX,
                         int boxY,
                         int boxW,
                         uint16_t bgColor,
                         uint16_t textColor,
                         const GFXfont *font) {
  if (strcmp(newText, lastText) == 0) return;

  tft.setTextSize(1);
  tft.setFreeFont(font);

  if (lastText[0] != '\0') {
    int posX_last = getCenteredX(lastText, boxX, boxW);
    tft.setTextColor(bgColor);
    tft.drawString(lastText, posX_last, boxY);
  }

  if (newText[0] != '\0') {
    int posX_new = getCenteredX(newText, boxX, boxW);
    tft.setTextColor(textColor);
    tft.drawString(newText, posX_new, boxY);
  }

  if (lastTextSize == 0) return;
  strncpy(lastText, newText, lastTextSize - 1);
  lastText[lastTextSize - 1] = '\0';
}

void vUpdateSettingValue(const char *newText, char *lastText, int boxX, int boxY, int boxW) {
  vUpdateTextCentered(newText, lastText, 20, boxX, boxY, boxW, 0xDFFF, 0x2C, &FreeMonoBold12pt7b);
}

void vHome1Realtime() {
  // WaterLevel sudah diambil dari RS485 di task AmbilData
  if (homeFirstDraw || Last_waterLevel != WaterLevel) {

    // Format float -> string
    snprintf(WL_Text, sizeof(WL_Text), "%.1f", WaterLevel);

    // Hitung posisi X masing-masing
    int posX_new  = getWLPosX(WaterLevel);

    tft.setFreeFont(&FreeSansBold24pt7b);
    tft.setTextSize(3);

    if (!homeFirstDraw) {
      snprintf(Last_WL_Text, sizeof(Last_WL_Text), "%.1f", Last_waterLevel);
      int posX_last = getWLPosX(Last_waterLevel);
      // Hapus teks lama (pakai posisi lama)
      tft.setTextColor(0x7EBE);
      tft.drawString(Last_WL_Text, posX_last, 88);
    }

    // Tulis teks baru (pakai posisi baru)
    tft.setTextColor(0x002C);
    tft.drawString(WL_Text, posX_new, 88);

    Last_waterLevel = WaterLevel;
    homeFirstDraw = false;
  }

  // Update last send time display (2 baris)
  if (lastSendTime >= 1700000000) {
    snprintf(LastSendLine1_Text, sizeof(LastSendLine1_Text), "Last Send");
    struct tm timeinfo;
    localtime_r(&lastSendTime, &timeinfo);
    strftime(LastSendLine2_Text, sizeof(LastSendLine2_Text), "%Y-%m-%d %H:%M:%S", &timeinfo);
  } else {
    LastSendLine1_Text[0] = '\0';
    LastSendLine2_Text[0] = '\0';
  }

  vUpdateTextCentered(LastSendLine1_Text, Last_LastSendLine1_Text, sizeof(Last_LastSendLine1_Text),
                      25, 252, 380, 0xDFFF, 0x2C, &FreeMonoBold12pt7b);
  vUpdateTextCentered(LastSendLine2_Text, Last_LastSendLine2_Text, sizeof(Last_LastSendLine2_Text),
                      25, 270, 380, 0xDFFF, 0x2C, &FreeMonoBold12pt7b);

  // Update Signal (RSSI) display under Last Send
  snprintf(Rssi_Text, sizeof(Rssi_Text), "Signal : %d", iSignal);
  vUpdateTextCentered(Rssi_Text, Last_Rssi_Text, sizeof(Last_Rssi_Text),
                      25, 295, 380, 0xDFFF, 0x2C, &FreeMonoBold12pt7b);
}

void vSettingMenu2() {
    tft.fillScreen(0xDFFF);
    tft.fillRoundRect(54, 3, 372, 56, 15, 0x2C);
    tft.fillRoundRect(57, 5, 366, 52, 15, 0x7EBE);
    tft.fillRoundRect(17, 71, 447, 178, 12, 0x2C);
    tft.fillRoundRect(20, 74, 440, 171, 12, 0x7EBE);
    tft.fillRoundRect(-2, 269, 53, 53, 10, 0x2C);
    tft.fillRoundRect(2, 271, 46, 47, 10, 0x7EBE);
    tft.setTextColor(0x2C);
    tft.setTextSize(1);
    tft.setFreeFont(&FreeMonoBold18pt7b);
    tft.drawString("SETTING", 167, 14);
    tft.fillRoundRect(427, 267, 53, 53, 10, 0x2C);
    tft.fillRoundRect(430, 270, 46, 47, 10, 0x7EBE);
    tft.fillRoundRect(234, 87, 211, 38, 12, 0xDFFF);
    tft.setFreeFont(&FreeMonoBold12pt7b);
    tft.drawString("Multipler (M):", 32, 94);
    tft.drawString("Costanta  (C):", 32, 143);
    tft.drawString("Interval(Min):", 32, 194);
    tft.fillRoundRect(234, 136, 211, 40, 12, 0xDFFF);
    tft.fillRoundRect(233, 185, 212, 40, 12, 0xDFFF);
    // nilai akan diisi realtime dari Preferences
    tft.drawBitmap(9, 281, image_ArrowDownFilled_bits, 30, 28, 0x2C);
    tft.fillRoundRect(90, 269, 300, 49, 10, 0x2C);
    tft.fillRoundRect(94, 273, 292, 41, 10, 0x7EBE);
    // IP akan ditampilkan saat AP aktif
    // tft.drawBitmap(434, 279, image_wifi_full_bits, 38, 32, 0x2C);
    tft.drawBitmap(434, 279, image_wifi_not_connected_bits, 38, 32, 0x2C);
}

void vSettingMenu2Realtime(){
  snprintf(CalibM_Text, sizeof(CalibM_Text), "%.2f", calibM);
  snprintf(CalibC_Text, sizeof(CalibC_Text), "%.2f", calibC);
  snprintf(Interval_Text, sizeof(Interval_Text), "%d", intervalMinute);

  vUpdateSettingValue(CalibM_Text, Last_CalibM_Text, 234, 96, 211);
  vUpdateSettingValue(CalibC_Text, Last_CalibC_Text, 234, 147, 211);
  vUpdateSettingValue(Interval_Text, Last_Interval_Text, 234, 195, 211);

  bool apActive = webServerActive;

  if (apActive != lastApActive) {
    tft.fillRoundRect(427, 267, 53, 53, 10, 0x2C);
    tft.fillRoundRect(430, 270, 46, 47, 10, 0x7EBE);
    if (apActive) {
      tft.drawBitmap(434, 279, image_wifi_full_bits, 38, 32, 0x2C);
    } else {
      tft.drawBitmap(434, 279, image_wifi_not_connected_bits, 38, 32, 0x2C);
    }
    lastApActive = apActive;
  }

  if (apActive) {
    String ip = WiFi.softAPIP().toString();
    snprintf(Ap_Text, sizeof(Ap_Text), "AP: ON | %s", ip.c_str());
  } else {
    snprintf(Ap_Text, sizeof(Ap_Text), "AP: OFF");
  }

  vUpdateTextCentered(Ap_Text, Last_Ap_Text, sizeof(Last_Ap_Text),
                      94, 283, 292, 0x7EBE, 0x2C, &FreeMonoBold12pt7b);

  tft.drawBitmap(9, 281, image_ArrowDownFilled_bits, 30, 28, 0x2C);
}



bool vParseJsonNumber(const String &body, const char *key, double &outValue) {
  String pattern = String("\"") + key + "\"";
  int keyIndex = body.indexOf(pattern);
  if (keyIndex < 0) return false;

  int colonIndex = body.indexOf(':', keyIndex + pattern.length());
  if (colonIndex < 0) return false;

  const char *p = body.c_str() + colonIndex + 1;
  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') p++;

  char *endPtr = nullptr;
  outValue = strtod(p, &endPtr);
  return endPtr != p;
}

bool vParseJsonString(const String &body, const char *key, char *outValue, size_t outSize) {
  if (outSize == 0) return false;
  String pattern = String("\"") + key + "\"";
  int keyIndex = body.indexOf(pattern);
  if (keyIndex < 0) return false;

  int colonIndex = body.indexOf(':', keyIndex + pattern.length());
  if (colonIndex < 0) return false;

  const char *p = body.c_str() + colonIndex + 1;
  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') p++;

  if (*p != '"') return false;
  p++;

  const char *end = strchr(p, '"');
  if (!end) return false;

  size_t len = (size_t)(end - p);
  if (len >= outSize) len = outSize - 1;
  strncpy(outValue, p, len);
  outValue[len] = '\0';
  return true;
}

void setupWebServerRoutes(AsyncWebServer &server) {
  // 1. Root page - Menampilkan Halaman Realtime
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", main_page_html);
  });

  // 2. Settings page
  server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", setting_page_html);
  });

  // 3. Realtime API
  server.on("/api/realtime", HTTP_GET, [](AsyncWebServerRequest *request) {
    char lastSentStr[24] = "";
    if (lastSendTime >= 1700000000) {
      struct tm timeinfo;
      localtime_r(&lastSendTime, &timeinfo);
      strftime(lastSentStr, sizeof(lastSentStr), "%Y-%m-%d %H:%M:%S", &timeinfo);
    }

    AsyncResponseStream *response = request->beginResponseStream("application/json");
    response->print("{");
    response->printf("\"water_level\":%.2f,", WaterLevel);
    response->printf("\"rssi\":%d,", iSignal);
    response->printf("\"device_id\":\"%s\",", deviceId);
    response->printf("\"location\":\"%s\",", locationName);
    response->printf("\"last_sent\":%ld,", (long)lastSendTime);
    response->printf("\"last_sent_str\":\"%s\"", lastSentStr);
    response->print("}");
    request->send(response);
  });

  // 4. Settings API (GET)
  server.on("/api/settings", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncResponseStream *response = request->beginResponseStream("application/json");
    response->print("{");
    response->printf("\"press_m\":%.2f,", calibM);
    response->printf("\"press_c\":%.2f,", calibC);
    response->printf("\"report_min\":%d,", intervalMinute);
    response->printf("\"web_on\":%d,", webServerTimeoutMinute);
    response->printf("\"tenant_id\":\"%s\",", tenantId);
    response->printf("\"device_id\":\"%s\",", deviceId);
    response->printf("\"location\":\"%s\"", locationName);
    response->print("}");
    request->send(response);
  });

  // 5. Settings API (POST)
  server.on("/api/settings", HTTP_POST,
    [](AsyncWebServerRequest *request) {
      String body = "";
      if (request->_tempObject) {
        body = *((String *)request->_tempObject);
        delete (String *)request->_tempObject;
        request->_tempObject = nullptr;
      }

      if (body.length() == 0 && request->hasParam("plain", true)) {
        body = request->getParam("plain", true)->value();
      }

      double value = 0.0;
      char textValue[24];
      if (vParseJsonNumber(body, "press_m", value)) {
        calibM = (float)value;
      }
      if (vParseJsonNumber(body, "press_c", value)) {
        calibC = (float)value;
      }
      if (vParseJsonNumber(body, "report_min", value)) {
        intervalMinute = (int)value;
      }
      if (vParseJsonNumber(body, "web_on", value)) {
        webServerTimeoutMinute = (int)value;
      }
      if (vParseJsonString(body, "tenant_id", textValue, sizeof(textValue))) {
        if (textValue[0] != '\0') {
          strncpy(tenantId, textValue, sizeof(tenantId) - 1);
          tenantId[sizeof(tenantId) - 1] = '\0';
        }
      }
      if (vParseJsonString(body, "device_id", textValue, sizeof(textValue))) {
        if (textValue[0] != '\0') {
          strncpy(deviceId, textValue, sizeof(deviceId) - 1);
          deviceId[sizeof(deviceId) - 1] = '\0';
        }
      }
      if (vParseJsonString(body, "location", textValue, sizeof(textValue))) {
        strncpy(locationName, textValue, sizeof(locationName) - 1);
        locationName[sizeof(locationName) - 1] = '\0';
      }

      vUpdateSendInterval();
      vUpdateWebServerTimeout();
      vPreferences_SaveSettings();
      if (webServerActive) {
        webServerStopAtMillis = millis() + webServerTimeoutMs;
      }

      Serial.printf("Settings updated - M: %.2f, C: %.2f, Interval: %d, WebTimeout: %d\n",
                    calibM, calibC, intervalMinute, webServerTimeoutMinute);

      AsyncResponseStream *response = request->beginResponseStream("application/json");
      response->print("{\"status\":\"ok\",\"message\":\"Settings saved\"}");
      request->send(response);
    },
    NULL,
    [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {
      if (!request->_tempObject) {
        request->_tempObject = new String();
        ((String *)request->_tempObject)->reserve(total);
      }
      String *body = (String *)request->_tempObject;
      body->concat((char *)data, len);
    }
  );

  // 6. Web server timeout countdown
  server.on("/api/webserver-timeout", HTTP_GET, [](AsyncWebServerRequest *request) {
    long remainingSeconds = 0;
    if (webServerActive && webServerStopAtMillis != 0) {
      int32_t diff = (int32_t)(webServerStopAtMillis - millis());
      if (diff > 0) remainingSeconds = diff / 1000;
    }
    AsyncResponseStream *response = request->beginResponseStream("application/json");
    response->printf("{\"remaining_seconds\":%ld}", remainingSeconds);
    request->send(response);
  });

  // 7. Close web server (stop AP)
  server.on("/api/webserver-close", HTTP_POST, [](AsyncWebServerRequest *request) {
    webServerStopRequested = true;
    AsyncResponseStream *response = request->beginResponseStream("application/json");
    response->print("{\"status\":\"ok\",\"message\":\"Web server closing\"}");
    request->send(response);
  });

  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
  });
}

// ========================================
// SETUP & LOOP FUNCTIONS
// ========================================

void setup() {
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println("Alat ON");
  setenv("TZ", "WIB-7", 1);
  tzset();
  vDisplaySetup(); 
  vPreferences_LoadSettings();
  vCheckMACAddress();
  Menu = MENU_HOME1;

  xTaskCreatePinnedToCore(
    TouchScreen,   /* Task function. */
    "TouchScreen",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    3,           /* priority of the task */
    &Task1,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */   

  xTaskCreatePinnedToCore(
    AmbilData,   /* Task function. */
    "AmbilData",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    2,           /* priority of the task */
    &Task2,      /* Task handle to keep track of created task */
    0);          /* pin task to core 1 */

  xTaskCreatePinnedToCore(
    WifiManagementTask,    // Task function
    "WifiManagement",      // Task name
    30000,                 // Stack size (bytes)
    NULL,                  // Parameter
    3,                     // Priority
    &Task3,                // Task handle
    1);                     // Core number (0 or 1)
  
  xTaskCreatePinnedToCore(
    SendDataSim800LTask,    // Task function
    "SendDataSim800L",      // Task name
    30000,                 // Stack size (bytes)
    NULL,                  // Parameter
    1,                     // Priority
    &Task3,                // Task handle
    1);                     // Core number (0 or 1)
  
}

void loop() {
  // Main logic dijalankan melalui FreeRTOS tasks
}

// ========================================
// CORE TASKS (FreeRTOS)
// ========================================
void TouchScreen( void * pvParameters ){
  (void) pvParameters;
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 100/ portTICK_PERIOD_MS;
  xLastWakeTime = xTaskGetTickCount ();
  // snprintf(WL_Text, sizeof(WL_Text), "%.1f", 0);
  // snprintf(Last_WL_Text, sizeof(WL_Text), "%.1f", 999.9);
  for(;;){
    vPressedTouchscreen();
    if (Last_pressed != pressed) {
      Last_pressed=pressed;
      vCekPressTouch();
    }
    Counter1s++;
    vCekMenuDisplay();
    if (Counter1s >= 10){
      vCekDisplayRealtime();
      Counter1s = 0;
    }
    vTaskDelayUntil( &xLastWakeTime, xFrequency );
  }
}

void AmbilData( void * pvParameters ){
  (void) pvParameters;
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 1000/ portTICK_PERIOD_MS;
  xLastWakeTime = xTaskGetTickCount ();
  vInitRS485();
  for(;;){
    vAmbilData();
    vTaskDelayUntil( &xLastWakeTime, xFrequency );
  }
}

void WifiManagementTask(void *pvParameters) {
  (void)pvParameters;
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 1000 / portTICK_PERIOD_MS;
  xLastWakeTime = xTaskGetTickCount();
  for (;;) {
    // Handle web server start request
    if (webServerStartRequested){
      webServerStartRequested = false;
      vStartWebServer();
    }

    if (webServerActive) {
      if (webServerStopRequested) {
        webServerStopRequested = false;
        vStopWebServer();
      } else if (webServerStopAtMillis != 0) {
        int32_t diff = (int32_t)(webServerStopAtMillis - millis());
        if (diff <= 0) {
          vStopWebServer();
        }
      }
    }
    
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}


void SendDataSim800LTask(void *pvParameters) {
  (void)pvParameters;
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 1000 / portTICK_PERIOD_MS;
  xLastWakeTime = xTaskGetTickCount();
  
  unsigned long lastMinutePrint = 0;
  int lastPrintedMinute = -1;
  
  // Set timezone ke GMT+7 (WIB)
  // Format: "WIB-7" berarti WIB adalah 7 jam di depan UTC
  setenv("TZ", "WIB-7", 1);
  tzset();
  
  setupModem();
  if (!setupGPRS()) return;
  
  // Kirim data pertama kali saat alat baru nyala
  // Tujuannya: dapat jam dari server (sync RTC) dan langsung tahu kapan lagi harus kirim
  Serial.println("\n>>> KIRIM DATA PERTAMA KALI (SAAT ALAT NYALA)...");
  Serial.println(">>> Tujuan: Sync RTC dari server dan tentukan jadwal kirim berikutnya");
  
  if (sendData()) {
    Serial.println(">>> KIRIM PERTAMA BERHASIL - RTC sudah di-sync dari server");
    
    // Tunggu sebentar untuk memastikan RTC sudah di-sync
    vTaskDelay(500 / portTICK_PERIOD_MS);
    
    // Tampilkan waktu saat ini setelah sync
    time_t now;
    time(&now);
    
    // Cek apakah RTC sudah valid (tidak tahun 1970)
    if (now >= 1700000000) {
      lastSendTime = now;
      struct tm timeinfo;
      localtime_r(&now, &timeinfo);
      char timeStr[20];
      strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);
      Serial.print(">>> Waktu saat ini (WIB): ");
      Serial.println(timeStr);
      
      // Hitung kapan kirim berikutnya (berdasarkan SEND_INTERVAL)
      time_t nextSendTime = ((now / SEND_INTERVAL) + 1) * SEND_INTERVAL;
      struct tm nextTimeinfo;
      localtime_r(&nextSendTime, &nextTimeinfo);
      char nextTimeStr[20];
      strftime(nextTimeStr, sizeof(nextTimeStr), "%H:%M:%S", &nextTimeinfo);
      Serial.print(">>> Kirim berikutnya pada: ");
      Serial.println(nextTimeStr);
    } else {
      Serial.println(">>> RTC belum valid - akan sync saat kirim berikutnya");
    }
  } else {
    Serial.println(">>> KIRIM PERTAMA GAGAL - Akan coba lagi saat kelipatan 15 menit");
  }
  
  for (;;) {
    time_t now;
    time(&now);
    struct tm timeinfo;
    localtime_r(&now, &timeinfo);
    
    // Print jam setiap 1 menit sekali
    if (timeinfo.tm_min != lastPrintedMinute) {
      lastPrintedMinute = timeinfo.tm_min;
      char timeStr[20];
      strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);
      Serial.print("[RTC] ");
      Serial.println(timeStr);
    }
    
    // Cek apakah waktunya mengirim (kelipatan 15 menit)
    if (timeToSend()) {
      char timeStr[20];
      strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);
      Serial.print("\n>>> WAKTU KIRIM: ");
      Serial.println(timeStr);
      Serial.println(">>> MENGIRIM DATA KE SERVER...");
      
      if (setupGPRS()) {
        if (sendData()) {
          lastSendTime = now;
          Serial.print(">>> PENGIRIMAN BERHASIL pada ");
          Serial.println(timeStr);
        } else {
          Serial.print(">>> PENGIRIMAN GAGAL pada ");
          Serial.println(timeStr);
        }
      } else {
        Serial.println(">>> GAGAL KONEKSI GPRS");
      }
    }
    
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}
