#pragma once
#define SENSOR int(27)
#define MOISTURE int (25)
int soil_moisture(){
  int moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(SENSOR);
  moisture_percentage = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  return(moisture_percentage);
}
