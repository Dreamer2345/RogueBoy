#include <Arduboy2.h>


class PlayerClass {
  public:
  byte x;
  byte y;
  byte d;
  byte H;
  void PlayerMovement();   
  void Init();
};
PlayerClass playerobj;


void PlayerClass::PlayerMovement(){
  if (ard.justPressed(UP_BUTTON)){
    y++;
    }
  if (ard.justPressed(DOWN_BUTTON)){
    y--;
    }
  if (ard.justPressed(RIGHT_BUTTON)){
    x++;
    }
  if (ard.justPressed(LEFT_BUTTON)){
    x--;
    }   
}



void Init(byte x,byte y){
  playerobj.x = x;
  playerobj.y = y;
  playerobj.d = 0;
  playerobj.H = 100;
}
