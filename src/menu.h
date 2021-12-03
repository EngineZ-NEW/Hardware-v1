#pragma once
#include "Interface.h"
#include "TempHumid.h"
#include "SoilMoisture.h"
#include "intToString.h"
#include "sleeping.h"
#include "postData.h"
int oldpage= 0;
char buf[30];
void menu(int page) {
 if(sleep_check()){
 if ((page != oldpage) || (!digitalRead(PRESS)) || (analogRead(X)< 1300) || (analogRead(X)> 2400)){
    if(page == 1)
      {
        lcd.clear();
        char* message = "MENU temp: ";
        strcpy(buf, message);
        strcat(buf, int2str(temperature()));
        lcd.setCursor(0, 0);
        lcd.print(buf);
        message = "Humidity:";
        strcpy(buf, message);
        strcat(buf, int2str(humidity()));
        lcd.setCursor(0, 1);
        lcd.print(buf);
        oldpage = 1;
      }
      if(page == 2)
      { lcd.clear();
        char* message = "Soil moisture ";
        lcd.setCursor(0, 0);
        lcd.print(message);
        message = int2str(soil_moisture());
        strcpy(buf, message);
        strcat(buf, "%");
        lcd.setCursor(0, 1);
        lcd.print(buf);
        oldpage = 2;
        }
      if(page == 3){
        lcd.clear();
        char* message = "Selected Moisute";
        lcd.setCursor(0, 0);
        lcd.print(message);
        message = int2str(config.moisture);
        strcpy(buf, message);
        strcat(buf, " %");
        lcd.setCursor(0, 1);
        lcd.print(buf);
        oldpage = 3;
        }
      if(page == 4)
      {
        lcd.clear();
        char* message = "Selected Temp:";
        strcpy(buf, message);
        strcat(buf, int2str(config.temperature));
        lcd.setCursor(0, 0);
        lcd.print(buf);
        message = "Humidity:";
        strcpy(buf, message);
        strcat(buf, int2str(config.humidity));
        lcd.setCursor(0, 1);
        lcd.print(buf);
        oldpage = 4; 
      }
      if(page == 5)
      {
        lcd.clear();
        if (!digitalRead(PRESS))
          saveConfiguration(filename, config);
        if (analogRead(X)> 2400)
          config.temperature++;  
        else if (analogRead(X)< 1300)
          config.temperature--;  
        char* message = "Adjust Temp:";
        strcpy(buf, message);
        strcat(buf, int2str(config.temperature));
        lcd.setCursor(0, 0);
        lcd.print(buf);
        message = "Press to save";
        lcd.setCursor(0, 1);
        lcd.print(message);
        oldpage = 5;
      }
      if(page == 6)
      {     lcd.clear();
           if (!digitalRead(PRESS))
          saveConfiguration(filename, config);
        if (analogRead(X)>2400)
          config.humidity++;  
        else if (analogRead(X)<1300)
          config.humidity--;  
        char* message = "Adjust Humid:";
        strcpy(buf, message);
        strcat(buf, int2str(config.humidity));
        lcd.setCursor(0, 0);
        lcd.print(buf);
        message = "Press to save";
        lcd.setCursor(0, 1);
        lcd.print(message);
        oldpage = 6;
      }
      if(page == 7)
      {     lcd.clear();
           if (!digitalRead(PRESS))
          saveConfiguration(filename, config);
        if (analogRead(X)>2400)
          config.moisture++;  
        else if (analogRead(X)<1300)
          config.moisture--;  
        char* message = "Adjust Moisture:";
        strcpy(buf, message);
        strcat(buf, int2str(config.humidity));
        lcd.setCursor(0, 0);
        lcd.print(buf);
        message = "Press to save";
        lcd.setCursor(0, 1);
        lcd.print(message);
        oldpage = 7;
      }
      if(page == 8)
      {
        lcd.clear();
        if (!digitalRead(PRESS)){
          ESP.restart();
        }
        char* message = "press button to";
        lcd.setCursor(0, 0);
        lcd.print(message);
        message = "restart device";
        lcd.setCursor(0, 1);
        lcd.print(message);
        oldpage = 8;
        }
        if(page == 9)
        {
          lcd.clear();
          if(!digitalRead(PRESS)){
            
             lcd.setCursor(0, 0);
        lcd.print("login on  ip");
             lcd.setCursor(0, 1);
        lcd.print("192.168.4.1");
            SPIFFS.remove(filename);
            ESP.restart();
            }
        char* message = "press button to";
        lcd.setCursor(0, 0);
        lcd.print(message);
        message = "reset settings";
        lcd.setCursor(0, 1);
        lcd.print(message);
        oldpage = 9;
        }
        if(page == 10){
          lcd.clear();
          if(!digitalRead(PRESS)){
            lcd.setCursor(0, 0);
            lcd.print("data sent:");
            lcd.setCursor(0, 1);
            lcd.print("TEMP");
            postData("https://greenhouse-v2.herokuapp.com/sensors/air-sensor");
              }
          char* message = "press button to";
          lcd.setCursor(0, 0);
          lcd.print(message);
          message = "send data";
          lcd.setCursor(0, 1);
          lcd.print(message);
          oldpage = 10;
        }
}
}
}
