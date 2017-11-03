#include <Arduboy2.h>
#include "Bitmaps.h"
Arduboy2 ard;
int Pressed [6] = {false,false,false,false,false,false};


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

void setup() {
  ard.begin();
  ard.clear();
  
}

void MainMenu(){
  bool Change = false;
  byte Choice = 0;
  while(!(Pressed[4])) {
    Change = GETKEYS();
    if (Change){
      if (Pressed[2] && (Choice < 4)) {
        Choice += 1;
        }
      if (Pressed[3] && (Choice > 0)) {
        Choice -= 1;
        }   
    }
  }
  
}

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



void loop() {
  
}
