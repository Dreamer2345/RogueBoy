#include <Arduboy2.h>
#include "Bitmaps.h"
#include "Player.h"
#include "Maps.h"

byte AniStep;
enum class GameState { MainMenu, Settings, Game };
GameState gameState = GameState::MainMenu;
byte Level;


uint8_t GetBlock(byte x,byte y){
    const uint8_t * CLevel = Maps[Level];
    uint8_t Block = pgm_read_byte(&CLevel[(OFFSET+x+(y*MAP_WIDTH))]);
    return Block;
}








