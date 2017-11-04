#include <Arduboy2.h>
#include <Sprites.h>
#include <ArduboyPlaytune.h>
#include "Bitmaps.h"
//Instances
Arduboy2 ard;
Sprites sprites;

byte AniStep;


enum class GameState { MainMenu, Settings, Game };
GameState gameState = GameState::MainMenu;
