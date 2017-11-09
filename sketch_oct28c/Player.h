#include <Arduboy2.h>

enum class GameState { MainMenu, Settings, Game ,LoadMap};
GameState gameState = GameState::MainMenu;

class PlayerClass {
  public:
  int x;
  int y;
  byte d;
  byte H;
  bool Moving;
  bool Frame;
  void PlayerMovement();   
  
};



void PlayerClass::PlayerMovement(){
  Moving = false;
  if (ard.pressed(UP_BUTTON) && Walkable(x,y+1)){
    y++;
    Moving = true;
    d = 0;
    }
  if (ard.pressed(DOWN_BUTTON) && Walkable(x,y-1)){
    y--;
    Moving = true;
    d = 1;
    }
  if (ard.pressed(RIGHT_BUTTON)&& Walkable(x+1,y)){
    x++;
    Moving = true;
    d = 2;
    }
  if (ard.pressed(LEFT_BUTTON)&& Walkable(x-1,y)){
    x--;
    Moving = true;
    d = 3;
    }   

  if (ard.justPressed(A_BUTTON)){
    
  }







  
  if (ard.pressed(A_BUTTON+B_BUTTON)){
    gameState = GameState::MainMenu;
  }
}




