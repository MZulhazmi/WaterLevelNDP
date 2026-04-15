#include <HardwareSerial.h>

/* ================= CONFIG ================= */
#define RXD2 16
#define TXD2 17
#define RS485_DIR_PIN 13
#define SLAVE_ID 0x01
#define SCALED_REG 0x0025      // ModScan 40038
#define READ_INTERVAL 1000     // ms
#define RESPONSE_TIMEOUT 80    // ms
/* ========================================== */

#define TX_ENABLE() digitalWrite(RS485_DIR_PIN, HIGH)
#define RX_ENABLE() digitalWrite(RS485_DIR_PIN, LOW)

HardwareSerial modbus(2);
unsigned long lastReadTime = 0;

 float rawLevel;


/* ============== CRC16 (Modbus RTU) ================= */
uint16_t modbusCRC(uint8_t *buf, uint8_t len) {
  uint16_t crc = 0xFFFF;
  for (uint8_t pos = 0; pos < len; pos++) {
    crc ^= buf[pos];
    for (uint8_t i = 0; i < 8; i++) {
      if (crc & 0x0001) {
        crc >>= 1;
        crc ^= 0xA001;
      } else {
        crc >>= 1;
      }
    }
  }
  return crc;
}

/* ============== HEX PRINT ================= */
void printHex(const char *tag, uint8_t *buf, uint8_t len) {
  Serial.print(tag);
  for (uint8_t i = 0; i < len; i++) {
    if (buf[i] < 0x10) Serial.print("0");
    Serial.print(buf[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

/* ============== READ SCALED FLOAT ================= */
bool readScaledFloat(float &value) {

  /* ---- BUILD TX FRAME ---- */
  uint8_t tx[8] = {
    SLAVE_ID, 0x03,
    uint8_t(SCALED_REG >> 8), uint8_t(SCALED_REG & 0xFF),
    0x00, 0x02,
    0, 0
  };

  uint16_t crc = modbusCRC(tx, 6);
  tx[6] = crc & 0xFF;
  tx[7] = crc >> 8;

  printHex("TX → ", tx, 8);

  /* ---- SEND ---- */
  TX_ENABLE();
  delayMicroseconds(20);
  modbus.write(tx, 8);
  modbus.flush();
  delayMicroseconds(50);
  RX_ENABLE();

  /* ---- WAIT RESPONSE ---- */
  unsigned long start = millis();
  while (modbus.available() < 9) {
    if (millis() - start > RESPONSE_TIMEOUT) {
      Serial.println("RX ← ERR: no response");
      while (modbus.available()) modbus.read();
      return false;
    }
  }

  /* ---- READ RX FRAME ---- */
  uint8_t rx[9];
  for (uint8_t i = 0; i < 9; i++) rx[i] = modbus.read();

  printHex("RX ← ", rx, 9);

  /* ---- FLOAT CONVERSION ---- */
  union {
    uint8_t b[4];
    float f;
  } data;

  // Modbus big-endian → ESP32 little-endian
  data.b[3] = rx[3];
  data.b[2] = rx[4];
  data.b[1] = rx[5];
  data.b[0] = rx[6];

  value = data.f;
  return true;
}

/* ===================== SETUP ======================== */
void vInitRS485() {
  modbus.begin(9600, SERIAL_8N1, RXD2, TXD2);

  pinMode(RS485_DIR_PIN, OUTPUT);
  RX_ENABLE();      // default receive

  Serial.println("SLS Modbus Scaled Reader (Auto)");
  Serial.println("--------------------------------");
  lastReadTime = 0;
}

/* ===================== LOOP ========================= */
void vAmbilData() {
  if (readScaledFloat(rawLevel)) {
    Serial.print("rawLevel = ");
    Serial.println(rawLevel, 1);
  }

  WaterLevel = calibM * rawLevel + calibC;

    Serial.print("Water Level = ");
    Serial.println(WaterLevel, 1);


  Serial.println();
}