#include <Arduboy2.h>
#include <Sprites.h>
Arduboy2 ard;
Sprites sprites;

#include "Global.h"
#include "Game.h"



void UpdateMainMenu(){
  sprites.drawSelfMasked(1,1,Logo,0);
  if (showarrow){sprites.drawOverwrite(21,56,Arrow,0);}
  if (ard.justPressed(A_BUTTON)){
    gameState = GameState::Game;
  }
  if (ard.everyXFrames(30)) {
      showarrow = !showarrow;
      }
}


void setup() {
  ard.begin();
  ard.clear();
  Init(1,1);
}



void loop() {
  if(!ard.nextFrame())
    return;

  ard.pollButtons();
  ard.clear();

  switch(gameState)
  {
    case GameState::MainMenu: UpdateMainMenu(); break;
    //case GameState::Settings: UpdateSettings(); break;
    case GameState::Game: UpdateGame(); break;
  }

  ard.display();
}
