#pragma once

#include <Arduboy2.h>

#include "Maps.h"

enum class GameState { MainMenu, Settings, Game ,LoadMap ,GameOver, MapEnding};
GameState gameState = GameState::MainMenu;

class PlayerClass {
  public:
  int x;
  int y;
  byte d;
  byte H;
  byte Keys;
  byte Coins;
  bool Moving;
  bool Frame;
  void PlayerMovement();
};



void PlayerClass::PlayerMovement() {
  Moving = false;
  if (ard.pressed(UP_BUTTON) && Walkable(x,y-1)){
    y--;
    Moving = true;
    d = 0;
    }
  if (ard.pressed(DOWN_BUTTON) && Walkable(x,y+1)){
    y++;
    Moving = true;
    d = 1;
    }
  if (ard.pressed(RIGHT_BUTTON) && Walkable(x+1,y)){
    x++;
    Moving = true;
    d = 2;
    }
  if (ard.pressed(LEFT_BUTTON)&& Walkable(x-1,y)){
    x--;
    Moving = true;
    d = 3;
    }   









  
  if (ard.pressed(A_BUTTON+B_BUTTON)){
    gameState = GameState::MainMenu;
    Level = 0;
  }
  
  if (ard.justPressed(A_BUTTON)){
    int relx = x/16;
    int rely = y/16;
    uint8_t bl = GetBlock(relx,rely);
    if (bl == DOWN_STAIRS){
      gameState = GameState::MapEnding;
    } 
    else 
    {
        switch(d){
          case 0: rely++; break;
          case 1: rely--; break;
          case 2: relx++; break;
          case 3: relx--; break;
          }
        bl = GetBlock(relx,rely);
        switch(bl){
          case SWITCH_ON: SetBlock(relx,rely,SWITCH_OFF); break;
          case SWITCH_OFF: SetBlock(relx,rely,SWITCH_ON); break;
          case CLOSED_CHEST: SetBlock(relx,rely,OPEN_CHEST); break;
        }
    }
  
  }
}




