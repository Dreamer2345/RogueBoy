#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;

#include "Global.h"
#include "Game.h"



void UpdateMainMenu(){
  sprites.drawSelfMasked(0,0,Logo,0);
  if (showarrow){sprites.drawOverwrite(20,55,Arrow,0);}
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
