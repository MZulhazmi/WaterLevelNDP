
#include "DefineBitmap.h"
#include "WebServer.h"
#include <WiFi.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Preferences.h>

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

// ========================================
// PREFERENCES CONFIGURATION
// ========================================
Preferences preferences;

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
    }
    else if (Menu == MENU_SETTING){
      vSettingMenu2();
    }
  }
}

void vCekDisplayRealtime(){
  if (Menu == MENU_HOME1){
    // vHome1Realtime();
  }
  else if (Menu == MENU_SETTING){
    // vSettingMenu2Realtime();
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
// GLOBAL VARIABLES - DISPLAY DATA
// ========================================
// float waterLevel = 125.0;  // cm
float Last_waterLevel = -9999;  // cm
float WaterLevel;
int calibM = 1;
int calibC = 0;
int intervalMinute = 15;
bool wifiConnected = false;
unsigned long lastRandomUpdate = 0;
const unsigned long randomUpdateInterval = 1000;  // Update random every 1 second

// ========================================
// TRANSITION VARIABLES
// ========================================
unsigned long transitionStartTime = 0;
const unsigned long transitionDuration = 300;  // 300ms transition time

// ========================================
// FUNGSI PREFERENCES
// ========================================
void vPreferences_LoadSettings(){
  preferences.begin("waterLevel", true);  // true = read-only mode
  calibM = preferences.getInt("calibM", 1);
  calibC = preferences.getInt("calibC", 0);
  intervalMinute = preferences.getInt("interval", 15);
  preferences.end();
  
  Serial.println("Settings loaded from Preferences");
  Serial.printf("M: %d, C: %d, Interval: %d\n", calibM, calibC, intervalMinute);
}

void vPreferences_SaveSettings(){
  preferences.begin("waterLevel", false);  // false = read-write mode
  preferences.putInt("calibM", calibM);
  preferences.putInt("calibC", calibC);
  preferences.putInt("interval", intervalMinute);
  preferences.end();
  
  Serial.println("Settings saved to Preferences");
}

// ========================================
// FUNGSI WEB SERVER ASYNCHRONOUS
// ========================================

void vSetupWebServer(){
  setupWebServerRoutes(server, calibM, calibC, intervalMinute, vPreferences_SaveSettings);
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
    vSetupWebServer();
  }
}

void vStopWebServer(){
  if(webServerActive){
    server.end();
    WiFi.softAPdisconnect(true);
    webServerActive = false;
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
    tft.setTextSize(3);
    tft.setFreeFont(&FreeSansBold24pt7b);
    tft.drawString("300", 122, 88);
    tft.setTextSize(1);
    tft.setFreeFont(&FreeMonoBold12pt7b);
    tft.drawString("METER", 205, 224);
    tft.fillRoundRect(428, 268, 52, 52, 10, 0x2C);
    tft.fillRoundRect(431, 270, 46, 47, 10, 0x7EBE);
    tft.drawBitmap(441, 279, image_menu_tools_bits, 28, 32, 0x2C);
}

void vHome1BG_Backup(){
  // Clear screen with blue background
  tft.fillScreen(COLOR_BG_MAIN);
  
  // ===== HEADER SECTION =====
  tft.fillRoundRect(20, 10, 440, 70, 15, COLOR_PRIMARY_LIGHT);  // Sky blue header
  tft.drawRoundRect(20, 10, 440, 70, 15, COLOR_PRIMARY_MEDIUM); // Steel blue border
  tft.setTextColor(COLOR_PRIMARY_DARK, COLOR_PRIMARY_LIGHT);    // Dark blue text
  tft.setTextSize(4);
  tft.setCursor(110, 28);
  tft.println("WATER LEVEL");

  // ===== MAIN CONTENT AREA =====
  // Large background box untuk water level value
  tft.fillRoundRect(60, 110, 360, 110, 12, COLOR_BG_MAIN);      // Light blue box
  tft.drawRoundRect(60, 110, 360, 110, 12, COLOR_PRIMARY_MEDIUM); // Steel blue border

  // Unit indicator (CM)
  tft.setTextColor(COLOR_PRIMARY_DARK, COLOR_BG_MAIN);
  tft.setTextSize(2);
  tft.setCursor(215, 200);
  tft.println("CM");

  // ===== NAVIGATION BUTTONS =====
  // Home button (left side) - Blue theme
  tft.fillRect(0, 270, 48, 50, COLOR_PRIMARY_LIGHT);
  tft.drawRect(0, 270, 48, 50, COLOR_PRIMARY_DARK);
  tft.setTextColor(COLOR_PRIMARY_DARK, COLOR_PRIMARY_LIGHT);
  tft.setTextSize(3);
  tft.setCursor(10, 283);
  tft.println("<");

  // Setting button (right side) - Blue theme
  tft.fillRect(432, 270, 48, 50, COLOR_PRIMARY_LIGHT);
  tft.drawRect(432, 270, 48, 50, COLOR_PRIMARY_DARK);
  tft.setTextColor(COLOR_PRIMARY_DARK, COLOR_PRIMARY_LIGHT);
  tft.setTextSize(3);
  tft.setCursor(443, 283);
  tft.println(">");
}

void vHome1Realtime(){
  // Generate random water level untuk demo
  unsigned long currentTime = millis();
  if (currentTime - lastRandomUpdate >= randomUpdateInterval) {
    lastRandomUpdate = currentTime;
    // Random value antara 80-150 cm
    WaterLevel = random(800, 15000) / 10.0;
  }
  
  // Only update if value changed
  if(Last_waterLevel != WaterLevel){
    // Clear area with background color
    tft.fillRect(50, 110, 300, 90, COLOR_BG_MAIN);
    
    // Display nilai baru - SANGAT BESAR & ORANGE
    tft.setTextColor(COLOR_ACCENT_ORANGE, COLOR_BG_MAIN);
    tft.setTextSize(7);
    tft.setCursor(80, 120);
    tft.printf("%6.1f", WaterLevel);
    
    Last_waterLevel = WaterLevel;
  }
}

// ========================================
// FUNGSI DISPLAY SETTING MENU 2
// ========================================

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
    tft.drawString("1", 248, 96);
    tft.drawString("0", 248, 147);
    tft.drawString("15", 248, 195);
    tft.drawBitmap(9, 281, image_ArrowDownFilled_bits, 30, 28, 0x2C);
    tft.fillRoundRect(90, 269, 300, 49, 10, 0x2C);
    tft.fillRoundRect(94, 273, 292, 41, 10, 0x7EBE);
    tft.drawString("192.168.4.1", 163, 283);
    // tft.drawBitmap(434, 279, image_wifi_full_bits, 38, 32, 0x2C);
    tft.drawBitmap(434, 279, image_wifi_not_connected_bits, 38, 32, 0x2C);
}

void vSettingMenu2_backup(){
  // Clear screen dengan blue background
  tft.fillScreen(COLOR_BG_MAIN);
  
  // ===== HEADER BAR - SAMA SEPERTI HOME =====
  tft.fillRect(0, 0, 480, 60, COLOR_PRIMARY_LIGHT);
  tft.drawRect(0, 0, 480, 60, COLOR_PRIMARY_MEDIUM);
  tft.setTextColor(COLOR_PRIMARY_DARK, COLOR_PRIMARY_LIGHT);
  tft.setTextSize(3);
  tft.setCursor(150, 12);
  tft.println("KONFIGURASI");

  // Divider line
  tft.drawLine(0, 60, 480, 60, COLOR_PRIMARY_MEDIUM);
  
  // ===== SETTING CALIBRATE SECTION =====
  // Label M (Multiplier)
  tft.setTextColor(COLOR_TEXT_DARK_GRAY, COLOR_BG_MAIN);
  tft.setTextSize(2);
  tft.setCursor(40, 65);
  tft.println("Multiplier (M):");
  
  // Input box M
  tft.fillRect(40, 90, 150, 40, COLOR_PRIMARY_MEDIUM);
  tft.drawRect(40, 90, 150, 40, COLOR_ACCENT_GREEN);
  
  // Label C (Constant)
  tft.setTextColor(COLOR_TEXT_DARK_GRAY, COLOR_BG_MAIN);
  tft.setCursor(250, 65);
  tft.println("Konstanta (C):");
  
  // Input box C
  tft.fillRect(250, 90, 150, 40, COLOR_PRIMARY_MEDIUM);
  tft.drawRect(250, 90, 150, 40, COLOR_ACCENT_GREEN);
  
  // Label Interval
  tft.setTextColor(COLOR_TEXT_DARK_GRAY, COLOR_BG_MAIN);
  tft.setCursor(40, 165);
  tft.println("Waktu Update (menit):");
  
  // Input box Interval
  tft.fillRect(40, 190, 350, 40, COLOR_PRIMARY_MEDIUM);
  tft.drawRect(40, 190, 350, 40, COLOR_ACCENT_GREEN);
  
  // ===== NAVIGATION BUTTONS =====
  // Home button (left side) - Blue theme
  tft.fillRect(0, 270, 48, 50, COLOR_PRIMARY_LIGHT);
  tft.drawRect(0, 270, 48, 50, COLOR_PRIMARY_DARK);
  tft.setTextColor(COLOR_PRIMARY_DARK, COLOR_PRIMARY_LIGHT);
  tft.setTextSize(3);
  tft.setCursor(8, 280);
  tft.println("<");
  
  // Save/OK button (right side) - Blue theme
  tft.fillRect(432, 270, 48, 50, COLOR_PRIMARY_LIGHT);
  tft.drawRect(432, 270, 48, 50, COLOR_PRIMARY_DARK);
  tft.setTextColor(COLOR_PRIMARY_DARK, COLOR_PRIMARY_LIGHT);
  tft.setTextSize(3);
  tft.setCursor(438, 280);
  tft.println("OK");
}

void vSettingMenu2Realtime(){
  // Update M value
  tft.fillRect(45, 95, 140, 30, COLOR_PRIMARY_MEDIUM);
  tft.setTextColor(COLOR_ACCENT_ORANGE, COLOR_PRIMARY_MEDIUM);
  tft.setTextSize(3);
  tft.setCursor(60, 102);
  tft.printf("%d", calibM);
  
  // Update C value
  tft.fillRect(255, 95, 140, 30, COLOR_PRIMARY_MEDIUM);
  tft.setTextColor(COLOR_ACCENT_ORANGE, COLOR_PRIMARY_MEDIUM);
  tft.setTextSize(3);
  tft.setCursor(270, 102);
  tft.printf("%d", calibC);
  
  // Update Interval value
  tft.fillRect(45, 195, 340, 30, COLOR_PRIMARY_MEDIUM);
  tft.setTextColor(COLOR_ACCENT_ORANGE, COLOR_PRIMARY_MEDIUM);
  tft.setTextSize(3);
  tft.setCursor(60, 202);
  tft.printf("%d", intervalMinute);
}

void setupWebServerRoutes(AsyncWebServer &server, int &calibM, int &calibC, int &intervalMinute, void (*saveSettings)()) {
  // Handle root request
  // 1. Root page - Menampilkan Halaman Realtime
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", main_page_html);
  });
  // Handle settings save
  server.on("/savesettings", HTTP_POST, [&calibM, &calibC, &intervalMinute, saveSettings](AsyncWebServerRequest *request){
    if(request->hasParam("calibM", true)) {
      calibM = request->getParam("calibM", true)->value().toInt();
    }
    if(request->hasParam("calibC", true)) {
      calibC = request->getParam("calibC", true)->value().toInt();
    }
    if(request->hasParam("interval", true)) {
      intervalMinute = request->getParam("interval", true)->value().toInt();
    }
    saveSettings();
    Serial.printf("Settings updated - M: %d, C: %d, Interval: %d\n", calibM, calibC, intervalMinute);
    request->send(200, "text/plain", "success");
  });
}

// ========================================
// SETUP & LOOP FUNCTIONS
// ========================================

void setup() {
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println("Alat ON");
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
    if(webServerStartRequested){
      webServerStartRequested = false;
      vStartWebServer();
      // Keep web server running for 5 minutes or until signal to stop
      vTaskDelay(300000 / portTICK_PERIOD_MS);  // 5 minutes
      vStopWebServer();
    }
    
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}
