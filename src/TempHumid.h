#pragma once
#define DHTPIN 4
#define DHTTYPE DHT11
#define FAN 26
#define HUMID 33
#include "DHT.h"      
DHT dht(DHTPIN, DHTTYPE, 20);
int temperature(){
  float temp =0;
  while (true){
    temp = dht.readTemperature();
  if ((temp >1) && (temp < 100)){
   return int(temp);
  }
  }
}

int humidity(){
  float humid =0;
  while (true){
    humid = dht.readHumidity();
  if ((humid >1) && (humid < 100)){
   return int(humid);
  }
  }
  }
