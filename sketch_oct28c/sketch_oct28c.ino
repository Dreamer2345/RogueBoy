#include "Global.h"

void UpdateMainMenu(){
  if (ard.justPressed(A_BUTTON)){
    gameState = GameState::Game;
  }
  if (ard.everyXFrames(15)) {
      if (AniStep == 2) {
          AniStep = 0;
          sprites.drawSelfMasked(21,56,Arrow,0);
      } else {
          AniStep++;
      }
  sprites.drawSelfMasked(1,1,Logo,0);
}


void setup() {
  ard.begin();
  ard.clear();
}



void loop()
{
  if(!ard.nextFrame())
    return;

  ard.pollButtons();
  ard.clear();

  switch(gameState)
  {
    case GameState::MainMenu: UpdateMainMenu(); break;
    //case GameState::Settings: UpdateSettings(); break;
    //case GameState::Game: UpdateGame(); break;
  }

  ard.display();
}
