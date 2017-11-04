#include <Arduboy2.h>
#include <Sprites.h>
#include "Bitmaps.h"
Arduboy2 ard;
Sprites sprites;

/*int Pressed [6] = {false,false,false,false,false,false};


bool GETKEYS(){
  bool Change = false;
  bool Keys [6] = {false,false,false,false,false,false};
  byte Key [6] = {LEFT_BUTTON,RIGHT_BUTTON,UP_BUTTON,DOWN_BUTTON,A_BUTTON,B_BUTTON};
  for (byte i=0; i<6; i++){
    Pressed[i] = false;
  }
  for (byte i=0; i<6; i++){
    if ((Keys[i] == false)&&(ard.pressed(Key[i]))){
      Keys[i] = true;
      }
    else if ((!(ard.pressed(Key[i])))&&(Keys[i] == true)){
      Keys[i] = false;
      Pressed[i] = true;
      Change = true;
      }
  }
 return Change;
}
*/

/*
void DisplayBitmap(byte x,byte y,int b,bool Col){
  uint8_t Buffer[16];
  int Wid = 16;
  int MemLoc = Wid*b;
  int MemLocEnd = MemLoc+Wid;
  for(byte i=MemLoc; i<MemLocEnd; i++){
    Buffer[i-MemLoc] = backTiles[i];
    }
  if (Col){
  ard.drawBitmap(x, y, Buffer, 16, 16, WHITE);
  } else {
  ard.drawBitmap(x, y, Buffer, 16, 16, BLACK);
  }
}
*/

void MainMenu(){
  byte Choice = 0;
  while(!(ard.justPressed(A_BUTTON))) {
    if (ard.pressed(UP_BUTTON)||ard.pressed(DOWN_BUTTON)){
      if (ard.justPressed(UP_BUTTON) && (Choice < 18)) {
        Choice += 1;
        }
      if (ard.justPressed(DOWN_BUTTON) && (Choice > 0)) {
        Choice -= 1;
        } 
      ard.clear();
      ard.print(Choice);  
    }
    sprites.drawSelfMasked(20,20,BackgroundEnviroment,Choice);
    }
}


void setup() {
  ard.begin();
  ard.clear();
}







void loop() {
 MainMenu();
}
