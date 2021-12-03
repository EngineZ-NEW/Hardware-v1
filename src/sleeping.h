#pragma once;
#include "Joystick.h"
#include "Screen.h"
int counter = 0;
int sleep_check (){
  if (getPosition_Y() == 0 && getPosition_X() == 0 && buttonPressed() == 0)
  {
    counter++;
  }
  else 
  { 
    counter = 0;
    lcd.display();
    lcd.backlight();
    return 1;
  }
  if (counter > 30)
  {
    lcd.noDisplay();
    lcd.noBacklight();
    return 0;
  }
  return 1;
  }
