#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;
int POINTS = 0;
bool Audio = true;
#include "Global.h"
#include "Game.h"





void setup() {
  ard.begin();
  ard.clear();
  Level = 0;
  
}



void loop() {
  if(!ard.nextFrame())
    return;

  ard.pollButtons();
  if (gameState != GameState::TextTitle)
      {      
      ard.clear();
      }

  switch(gameState)
  {
    case GameState::TextTitle: TitleText(); break;
    case GameState::MainMenu: UpdateMainMenu(); break;
    case GameState::Game: UpdateGame(); break;
    case GameState::LoadMap: NextLevelLoad(); break;
    case GameState::MapEnding: MapEnding(); break;
    case GameState::Dead: Death(); break;
  }

  ard.display();
}
