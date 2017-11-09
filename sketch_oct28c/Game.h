#include "Player.h"
#include "Sprites.h"

PlayerClass playerobj;
SpriteClass Objects[MAXOBJECT];
byte ONum = 0;



void Init(int x,int y){
  playerobj.x = x;
  playerobj.y = y;
  playerobj.d = 0;
  playerobj.H = 100;
}

void DisplayEnviroment(){
  int x = playerobj.x/16;
  int y = playerobj.y/16;
  int offx = playerobj.x % 16;
  int offy = playerobj.y % 16;
  for (int i=-5; i<10 ,i++;){
    for(int j=-3; j<3 ,j++;){
      uint8_t bl = GetBlock((i+x),(j+y));
      int drx = (CENTERX + (i*16) + offx)-8;
      int dry = (CENTERY + (j*16) + offy)-8;
      sprites.drawSelfMasked(drx,dry,BackgroundEnviroment,bl);
    }
  }
}

void DisplayPlayer(){
  if ((playerobj.Moving) && (ard.everyXFrames(15))){
        playerobj.Frame = !playerobj.Frame;
        if (playerobj.Frame){
        sprites.drawOverwrite(CENTERX-4,CENTERY-4,SpriteEnviroment,1);
        } else {
        sprites.drawOverwrite(CENTERX-4,CENTERY-4,SpriteEnviroment,2);
        }
  } else {
  sprites.drawOverwrite(CENTERX-4,CENTERY-4,SpriteEnviroment,0);
  }
}

void UpdateMainMenu(){
  sprites.drawSelfMasked(0,0,Logo,0);
  if (showarrow){sprites.drawOverwrite(20,55,Arrow,0);}
  if (ard.justPressed(A_BUTTON)){
    gameState = GameState::LoadMap;
  }
  if (ard.everyXFrames(30)) {
      showarrow = !showarrow;
      }
}

void LoadMAP(byte L){
    const uint8_t * CLevel = Maps[L];
    int px = pgm_read_byte(&CLevel[2]);
    int py = pgm_read_byte(&CLevel[3]);
    uint8_t index = OFFSET+(MAP_WIDTH*MAP_HEIGHT)+1;
    Init(px,py);
    for (int i=0; i<(MAP_WIDTH*MAP_HEIGHT), i++;){
        Map[i] = pgm_read_byte(&CLevel[(OFFSET+i)]);
    }
    ONum = pgm_read_byte(&CLevel[index]);
    byte ID = 0;
    byte H = 0;
    byte Offs = 0;
    index++;
    for (int i=0; i<MAXOBJECT, i++;){
      Objects[i].setSprite(0,0,0,0,0,false);
    }

    
    for (int i=0; i<ONum, i++;){
        ID = pgm_read_byte(&CLevel[index++]);
        px = pgm_read_byte(&CLevel[index++]);
        py = pgm_read_byte(&CLevel[index++]);
        H = pgm_read_byte(&CLevel[index++]);
        switch (ID){
          case 1: Offs=12; break;
        }
        Objects[i].setSprite(px,py,H,ID,Offs,true);
    }
}

void NextLevelLoad(){
  Level++; 
  LoadMAP(Level);
  gameState = GameState::Game;
}

void UpdateObjects(){
  for (byte i=0;i<ONum,i++;){
    if (Objects[i].IsActive()) {
      Objects[i].UPPos(playerobj.x,playerobj.y);
      Objects[i].SpriteAI();
      }
  }
}

void DisplayObjects() {
  for (byte i=0;i<ONum,i++;){
    if (Objects[i].IsActive()) {
    Objects[i].Display();
    }
  }
}



void UpdateGame(){
  playerobj.PlayerMovement();
  UpdateObjects();
  DisplayEnviroment();
  DisplayPlayer();
  DisplayObjects();
}

