#include "Player.h"
#include "Sprites.h"

PlayerClass playerobj;
SpriteClass Objects[MAXOBJECT];

byte ONum = 0;
byte Diff = 1;


void Init(int x,int y){
  playerobj.x = x;
  playerobj.y = y;
  playerobj.d = 0;
  playerobj.Coins = 0;
  playerobj.Keys = 0;
  playerobj.H = 100;
}

bool Intersect(unsigned Min0, unsigned Max0, unsigned Min1, unsigned Max1){return ((Max0 > Min1) && (Min0 < Max1));}

bool Collision(unsigned x, unsigned y, unsigned x1, unsigned y1) {return (Intersect(x,x+8,x1,x1+8)&&Intersect(y,y+8,y1,y1+8));}




void DisplayEnviroment()
{
  int tileX = GetTileX(playerobj.x);
  int tileY = GetTileY(playerobj.y);
  int offsetX = GetTileXOffset(playerobj.x);
  int offsetY = GetTileYOffset(playerobj.y);
    
  for (int i = -5; i < 5; i++)
  {
    for(int j = -3; j < 3; j++)
    {
      uint8_t block = GetBlock(tileX + i, tileY + j);
      int drawX = (i * 16) + CENTERX - offsetX;
      int drawY = (j * 16) + CENTERY - offsetY;
      sprites.drawSelfMasked(drawX, drawY, BackgroundEnviroment, block);
    }
  }
}

void DisplayPlayer(){	
	const uint8_t PlayerFrames[] = { 0, 1, 0, 2 };
  if(!playerobj.Moving)
  {
    sprites.drawExternalMask(CENTERX - 4, CENTERY - 4, SpriteEnviroment,SpriteMask,0,0);
  }
  else
  {
    if(ard.everyXFrames(15))
    {
      ++playerobj.Frame;
      playerobj.Frame %= 4;
    }
    sprites.drawExternalMask(CENTERX - 4, CENTERY - 4, SpriteEnviroment,SpriteMask,PlayerFrames[playerobj.Frame],PlayerFrames[playerobj.Frame]);
  }
}

void UpdateMainMenu(){
  sprites.drawSelfMasked(0,0,Logo,0);
  if (showarrow){sprites.drawOverwrite(20,55,Arrow,0);}
  //if (Audio){sprites.drawOverwrite(1,1,Speaker,1);} else {sprites.drawOverwrite(1,1,Speaker,0);}
  if (ard.justPressed(A_BUTTON)){
    gameState = GameState::LoadMap;
  }
  if (ard.justPressed(B_BUTTON)){
    Audio = !Audio;
  }
  if (ard.everyXFrames(30)) {
      showarrow = !showarrow;
      }
}


void TitleText(){
  if (ard.justPressed(A_BUTTON)) { Audio = true; showarrow = 0; gameState = GameState::MainMenu; }
  else {
  byte ofs = 0;
  if (!Audio) {
      if (showarrow > 168){ofs = 42;}
      ard.setCursor(0, 0);
      for(uint8_t i = ofs; i < showarrow; i++) {
          ard.print((char)pgm_read_byte(&TitleSequenceText[i]));
      }
      if (ard.everyXFrames(15)) {showarrow++;}
      if (showarrow > 192){Audio = true; showarrow = 0;}
  }
  else {
      for(uint8_t i = 48; i < 192; i++) {
          ard.print((char)pgm_read_byte(&TitleSequenceText[i]));
      }
      sprites.drawOverwrite(0,64-showarrow,Logo,0);
      showarrow++;
      if (showarrow >= 64){Audio = true; showarrow = 0; gameState = GameState::MainMenu;}
  }
 }
}


void LoadMAP(byte L){
    const uint8_t * CLevel = Maps[L];
	
    int px = (pgm_read_byte(&CLevel[2])*16)+8;
    int py = (pgm_read_byte(&CLevel[3])*16)+8;
    uint8_t index = OFFSET+MAP_SIZE;
    Init(px,py);
    memcpy_P(&Map[0], &CLevel[OFFSET], MAP_SIZE);
    ONum = pgm_read_byte(&CLevel[index]);
    byte ID = 0;
    byte H = 0;
    byte Offs = 0;
    bool A = false;
    index++;
    for (int i=0; i<MAXOBJECT; i++){
      Objects[i].setSprite(0,0,0,0,0,false);
    }
    for (int i=0; i<MAXENVIROMENT; i++){
      Envi[i].SetEnv(0,0,0,0,false);
    }
    
    for (int i=0; i<ONum; i++){
        ID = pgm_read_byte(&CLevel[index++]);
        px = (pgm_read_byte(&CLevel[index++])*16)+8;
        py = (pgm_read_byte(&CLevel[index++])*16)+8;
        H = pgm_read_byte(&CLevel[index++]);
        switch (ID){
          case 1: Offs=12; break; //Coin
          case 2: Offs=8; break; //Potion
          case 3: Offs=9; break; //Jelly Filled Doughnut
          case 4: Offs=10; break; //Key
          case 5: Offs=11; break; //Ham
          case 6: Offs=3; break; //Floater
          case 7: Offs=4; break; //Skull
          case 8: Offs=5; break; //Spider
          case 9: Offs=6; break; //Bat
        }
        Objects[i].setSprite(px,py,H,ID,Offs,true);
    }
    ENum = pgm_read_byte(&CLevel[index++]);
    for (int i=0; i<ENum; i++){
        ID = pgm_read_byte(&CLevel[index++]);
        Offs = pgm_read_byte(&CLevel[index++]);
        py = pgm_read_byte(&CLevel[index++]);
        H = pgm_read_byte(&CLevel[index++]);
        Envi[i].SetEnv(ID,Offs,py,H,true);
    }
}

void NextLevelLoad(){
  if (Level < MAXLEVEL){
    LoadMAP(Level);
    Level++; 
    gameState = GameState::Game;
  } else {gameState = GameState::Dead;}
}

void UpdateObjects(){
  for (byte i=0;i<ONum;i++){
    Objects[i].UPPos(playerobj.x,playerobj.y);
    if (Objects[i].IsActive()) {
      if (Collision(Objects[i].GetX()-4,Objects[i].GetY()-4,playerobj.x-4,playerobj.y-4)){
          switch(Objects[i].GetType()){
            case 1: playerobj.Coins++; Objects[i].SetActive(false); break;
            case 3: playerobj.H += 5; if (playerobj.H > 100) {playerobj.H = 100;} Objects[i].SetActive(false); break;
            case 5: playerobj.H += 10; if (playerobj.H > 100) {playerobj.H = 100;} Objects[i].SetActive(false); break;
            case 4: playerobj.Keys++; Objects[i].SetActive(false); break;

            case 6: if (ard.everyXFrames(60)) {playerobj.H -= 10*Diff;} break;
            case 7: if (ard.everyXFrames(60)) {playerobj.H -= 5*Diff;} break;
            case 8: if (ard.everyXFrames(60)) {playerobj.H -= 2*Diff;} break;
            case 9: if (ard.everyXFrames(60)) {playerobj.H -= 1*Diff;} break;

            
            }
      } else {
        Objects[i].SpriteAI();
        }
      }
  }
  for (byte j=0;j<3;j++){
    if (Bullet[j].GetActive()){
      Bullet[j].UPPos(playerobj.x,playerobj.y);
      Bullet[j].Update();
    }
  }
    for (byte i=0;i<ONum;i++){
      for (byte j=0;j<3;j++){
        if ((Bullet[j].GetActive()) && (Objects[i].IsActive()) && (Objects[i].GetType() >= 6) && (Collision(Objects[i].GetX()-4,Objects[i].GetY()-4,Bullet[j].GetX()-4,Bullet[j].GetY()-4))){
          Objects[i].Damage();
          Bullet[j].Kill();
        }
      }
    }
}

void DisplayObjects() {
  for (byte i=0;i<ONum;i++){
    if (Objects[i].IsActive()) {
    Objects[i].Display();
    }
  }
  for (byte i=0;i<3;i++){
    if (Bullet[i].GetActive()){
      Bullet[i].Display();
    }
  }
}

void Death(){
  sprites.drawOverwrite(CENTERX-7,CENTERY-7,Flowers,0);
  ard.setCursor(CENTERX-7,CENTERY+10);
  ard.print(F("SCORED:"));
  ard.print(POINTS);
  ard.setCursor(CENTERX-7,CENTERY+18);
  ard.print(F("GotToLevel:"));
  ard.print(Level);
  if (ard.justPressed(A_BUTTON)||ard.justPressed(B_BUTTON)){gameState = GameState::MainMenu; Level = 0; POINTS = 0;}
  }

void MapEnding(){
    int padd = playerobj.Coins * 5;    
    int kadd = playerobj.Keys * 10;
    ard.setCursor(0,0);
    ard.print(F("Level:"));
    ard.println(Level);
    ard.print(F("Coins:"));
    ard.println(playerobj.Coins);
    ard.print(F("Keys:"));
    ard.println(playerobj.Keys);
    ard.print(F("Level Points:"));
    ard.println(kadd+padd);
    
    ard.print(F("Total Points:"));
    ard.println(POINTS+kadd+padd);
    
    if (ard.everyXFrames(240)) {
        gameState = GameState::LoadMap;
        POINTS += padd + kadd;
    }
}


void DrawHud(){
  ard.setCursor(0,0);
  ard.print(F("L:"));
  ard.print(Level);
  ard.print(F(" C:"));
  ard.print(playerobj.Coins);
  ard.print(F(" K:"));
  ard.print(playerobj.Keys);
  ard.print(F(" H:"));
  ard.print(playerobj.H);
  }


void UpdateGame(){
  playerobj.PlayerMovement();
  UpdateObjects();
  DisplayEnviroment();
  DisplayPlayer();
  DisplayObjects();
  DrawHud();
  if (playerobj.H <= 0) {gameState = GameState::Dead;}
}

