#include <ArduinoJson.h>
#include "loginpage.h"
#include "menu.h"
#include "relay.h"
#include <WiFi.h>
#include <WebServer.h>
TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;
int check;

void Task1code( void * pvParameters ) {
  
  pinMode(PRESS, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
 for (;;) {
        menu(page);
        Serial.println(uxTaskGetStackHighWaterMark(NULL));  
        delay(450);
  }
}

void Task2code( void * pvParameters ) {
   logpage();
   for(;;){
      server.handleClient();
      if(config.ssid !="isempty"){
        saveConfiguration(filename,config);
        ESP.restart();
    }
    delay(500);
   }
}
void Task3code( void * pvParameters ) {
pinMode(FAN, OUTPUT);
pinMode(MOISTURE, OUTPUT);
pinMode(HUMID,OUTPUT);
for(;;){
relay_fan();
relay_moisture();
relay_humidity();
delay(3000);
}
}

void setup() {
  SPIFFS.begin();
  Serial.begin(9600);
  loadConfiguration(filename, config);
  if (config.ssid == "isempty"){
   
    xTaskCreatePinnedToCore(
    Task2code, /* Task function. */
    "Task2",   /* name of task. */
    10000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    &Task2,    /* Task handle to keep track of created task */
    1);        /* pin task to core 2 */
}

else{
  dht.begin();
   xTaskCreatePinnedToCore(
    Task3code, /* Task function. */
    "Task3",   /* name of task. */
    10000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    &Task3,    /* Task handle to keep track of created task */
    0);        /* pin task to core 1 */
  
  xTaskCreatePinnedToCore(
    Task1code, /* Task function. */
    "Task1",   /* name of task. */
    10000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    &Task1,    /* Task handle to keep track of created task */
    1);        /* pin task to core 1 */
}
}
 


void loop() {
}
