#pragma once
//#define X int(13)
//#define Y int(12)
//#define PRESS int(14)
int PAGE_NUMBER= 10;
int X = 13;
int Y = 12;
int PRESS = 14;
int page = 1;
int getPosition_X(){
  int pos = 0;
  int x_pos = analogRead(X);
  
  if (x_pos < 1300 ){
    pos = -1;
    }  
  else if (x_pos > 2400){
    pos = 1;
    }    
  return pos;
}
  
int getPosition_Y(){
  int pos = 0;
  int y_pos = analogRead(Y);
  if (y_pos < 1300 ){
    pos = 1;
    if (page<PAGE_NUMBER){
    page++;
  }
  }
  else if (y_pos > 2400){
    pos = -1;
    if (page>1){
      page--;
  }
    }
  return pos;
}

int buttonPressed(){
  return !digitalRead(PRESS);
}
