#include <Arduboy2.h>
#include "Maps.h"

enum class GameState { MainMenu, Settings, Game };
GameState gameState = GameState::MainMenu;

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
  if (ard.pressed(UP_BUTTON) && Walkable(x,y+1)){
    y++;
    }
  if (ard.pressed(DOWN_BUTTON) && Walkable(x,y-1)){
    y--;
    }
  if (ard.pressed(RIGHT_BUTTON)&& Walkable(x+1,y)){
    x++;
    }
  if (ard.pressed(LEFT_BUTTON)&& Walkable(x-1,y)){
    x--;
    }   
  if (ard.pressed(A_BUTTON)&&ard.pressed(B_BUTTON)){
    gameState = GameState::MainMenu;
  }
}



void Init(int x,int y){
  playerobj.x = x;
  playerobj.y = y;
  playerobj.d = 0;
  playerobj.H = 100;
}

