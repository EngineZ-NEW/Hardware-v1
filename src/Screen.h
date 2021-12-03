#pragma once
#include <LiquidCrystal_I2C.h>
// LCD PINS SDA = 21
//          SCL = 22 
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
