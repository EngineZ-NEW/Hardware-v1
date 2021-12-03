#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter(0x23);

int light(){
   int lux = int(lightMeter.readLightLevel());
   return lux;
}
