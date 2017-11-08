#include <Arduboy2.h>
#include "Maps.h"

class PlayerClass {
  public:
  int x;
  int y;
  byte d;
  byte H;
  void PlayerMovement();   
  
};

PlayerClass playerobj;

void PlayerClass::PlayerMovement(){
  if (ard.justPressed(UP_BUTTON) && Walkable(x,y+1)){
    y++;
    }
  if (ard.justPressed(DOWN_BUTTON) && Walkable(x,y-1)){
    y--;
    }
  if (ard.justPressed(RIGHT_BUTTON)&& Walkable(x+1,y)){
    x++;
    }
  if (ard.justPressed(LEFT_BUTTON)&& Walkable(x-1,y)){
    x--;
    }   
}


/*
void Init(int x,int y){
  playerobj.x = x;
  playerobj.y = y;
  playerobj.d = 0;
  playerobj.H = 100;
}
*/
