#pragma once
#include "TempHumid.h"
#include "SoilMoisture.h"
#include "Interface.h"
void relay_fan(){


if (temperature() <= (config.temperature +2)){
  digitalWrite(FAN, HIGH);
  }
if (temperature() >= (config.temperature -2)){
  digitalWrite(FAN, LOW);
}
}


void relay_moisture(){
   if (soil_moisture() > (config.moisture)){
    digitalWrite(MOISTURE, HIGH);
    }
    else {
    digitalWrite(MOISTURE, LOW);
      }
  }

 void relay_humidity(){
if (humidity() > (config.humidity +5)){
  digitalWrite(HUMID, LOW);
  }
if (humidity() < (config.humidity -5)){
  digitalWrite(HUMID, HIGH);
}
  }
