void BarrelBreak(uint8_t x,uint8_t y);

#include "Player.h"
#include "Sprites.h"

PlayerClass playerobj;
SpriteClass Objects[MAXOBJECT];

byte ONum = 0;
byte Diff = 1;
byte Timer = 255;





void DropItem(uint8_t x,uint8_t y,bool EnDrop){
  bool NewSlot = true;
  uint8_t Found = 0;
  for (byte i=0;i<ONum;i++){
    if (!(Objects[i].IsActive())){
      NewSlot = false;
      Found = i;
      break;
    }
  }
  if ((ONum == MAXOBJECT)&&(NewSlot)) return;
  if (NewSlot){
    if (ONum < MAXOBJECT){ONum++;}
    uint8_t ID = random(1,5);
    uint8_t Offs = 0;
    if (ID!=4){
      switch (ID){
          case 1: Offs=12; break; //Coin
          case 2: Offs=8; break; //Potion
          case 3: Offs=9; break; //Jelly Filled Doughnut
          case 4: Offs=10; break; //Key
          case 5: Offs=11; break; //Ham
        }
      if (!EnDrop){
      Objects[ONum-1].setSprite((x*16)+8,(y*16)+8,1,ID,Offs,true);
      }else{
      Objects[ONum-1].setSprite(x,y,1,ID,Offs,true);
      }
      Objects[ONum-1].UPPos(playerobj.x,playerobj.y);
    }
  } else {
    uint8_t ID = random(1,5);
    uint8_t Offs = 0;
    if (ID!=4){
      switch (ID){
          case 1: Offs=12; break; //Coin
          case 2: Offs=8; break; //Potion
          case 3: Offs=9; break; //Jelly Filled Doughnut
          case 4: Offs=10; break; //Key
          case 5: Offs=11; break; //Ham
        }
      if (!EnDrop){
      Objects[Found].setSprite((x*16)+8,(y*16)+8,1,ID,Offs,true);
      }else{
      Objects[Found].setSprite(x,y,1,ID,Offs,true);
      }
      Objects[Found].UPPos(playerobj.x,playerobj.y);
    }
  }
}


void BarrelBreak(uint8_t x,uint8_t y){
  SetBlock(x,y,18);
  DropItem(x,y,false);
  sound.noTone();
  sound.tone(NOTE_C3,50, NOTE_C2,50, NOTE_E3,150);
}

void Init(int x,int y){
  sound.noTone();
  sound.tone(NOTE_C7H,150, NOTE_REST,100, NOTE_C6,150);
  playerobj.x = x;
  playerobj.y = y;
  playerobj.d = 0;
  playerobj.Coins = 0;
  playerobj.Keys = 0;
  playerobj.Kill = 0;
  playerobj.H = 100;
  for (int i = 0; i < 6; i++){
  Bullet[i].Kill();
  }
  Timer = 255;
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
    if(ard.everyXFrames(5))
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
  if (Audio){sprites.drawOverwrite(2,1,Speaker,1);} else {sprites.drawOverwrite(2,1,Speaker,0);}
  if (ard.justPressed(A_BUTTON)){
    gameState = GameState::LoadMap;
  }
  if (ard.justPressed(B_BUTTON)){
    Audio = !Audio;
    ard.audio.on();
    sound.noTone();
    sound.tone(NOTE_C4,50);
    ard.audio.off();
    if (Audio){ard.audio.on();}else{ard.audio.off();}
  }
  if (ard.everyXFrames(30)) {
      showarrow = !showarrow;
      }
}


void TitleText(){
  if (ard.justPressed(A_BUTTON)) {sound.tone(NOTE_C4,500); Audio = true; showarrow = 0; gameState = GameState::MainMenu; }
  if (!Audio) {
      ard.setCursor(0, 0);
      uint8_t i = 0;
      while(i < 151){
          if(ard.nextFrame()){
            ard.pollButtons();

            if (ard.everyXFrames(5)){
            ard.print((char)pgm_read_byte(&TitleSequenceText[i]));
            if ((pgm_read_byte(&TitleSequenceText[i]) != 32)&&(pgm_read_byte(&TitleSequenceText[i]) != 13))
              {
              sound.noTone();
              sound.tone(NOTE_C5,150);
              }
            i++;
            }

            ard.display();
            
            if (ard.justPressed(A_BUTTON)) {break;}
          }
      }
      Audio = true; 
      showarrow = 0;
  }
  else {
      for(uint8_t i = 0; i < 151; i++) {
          ard.print((char)pgm_read_byte(&TitleSequenceText[i]));
      }
      sprites.drawOverwrite(0,64-showarrow,Logo,0);
      showarrow++;
      if (showarrow >= 64){sound.noTone(); sound.tone(NOTE_D2H,150);Audio = true; showarrow = 0; gameState = GameState::MainMenu;}
  }
}


void LoadMAP(byte L){
    const uint8_t * CLevel = Maps[L];
    MAP_WIDTH = pgm_read_byte(&CLevel[0]);
    MAP_HEIGHT = pgm_read_byte(&CLevel[1]);
    uint8_t UsedMap = MAP_WIDTH*MAP_HEIGHT; 
    uint16_t px = (pgm_read_byte(&CLevel[2])*16)+8;
    uint16_t py = (pgm_read_byte(&CLevel[3])*16)+8;
    uint8_t index = OFFSET+UsedMap;
    Init(px,py);
    memcpy_P(&Map[0], &CLevel[OFFSET], UsedMap);
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
  } else {gameState = GameState::WinState;}
}

void UpdateObjects(){
  for (byte i=0;i<ONum;i++){
    Objects[i].UPPos(playerobj.x,playerobj.y);
    if (Objects[i].IsActive()) {
      bool Updatable = true; 
      for (byte j=0;j<ONum;j++){
        if ((j < i)&&(Collision(Objects[i].GetX(),Objects[i].GetY(),Objects[j].GetX(),Objects[j].GetY()))&&(Objects[j].GetType() >= 6)&&(Objects[j].IsActive())){
          Updatable = false;
        }
      }

      if (Updatable){
        Objects[i].SpriteAI();
      }
      
      if (Collision(Objects[i].GetX(),Objects[i].GetY(),playerobj.x,playerobj.y)){
          switch(Objects[i].GetType()){
            case 1: playerobj.Coins++; Objects[i].SetActive(false); sound.noTone(); sound.tone(NOTE_C7H,150); break;
            case 2: playerobj.Coins+=5; Objects[i].SetActive(false); sound.noTone(); sound.tone(NOTE_C7H,150); break;
            case 3: playerobj.H += 5; if (playerobj.H > 100) {playerobj.H = 100;} Objects[i].SetActive(false); sound.noTone();  sound.tone(NOTE_C3H,150); break;
            case 5: playerobj.H += 10; if (playerobj.H > 100) {playerobj.H = 100;} Objects[i].SetActive(false); sound.noTone(); sound.tone(NOTE_C3H,150); break;
            case 4: playerobj.Keys++; Objects[i].SetActive(false); sound.noTone(); sound.tone(NOTE_C7H,150); break;

            case 6: if (ard.everyXFrames(5)) {playerobj.H -= 10*Diff; sound.noTone(); sound.tone(NOTE_D3,50); ard.setRGBled(255,0,0); delay(5); ard.setRGBled(0,0,0);}  break;
            case 7: if (ard.everyXFrames(5)) {playerobj.H -= 5*Diff; sound.noTone(); sound.tone(NOTE_D3,50); ard.setRGBled(255,0,0); delay(5); ard.setRGBled(0,0,0);} break;
            case 8: if (ard.everyXFrames(5)) {playerobj.H -= 2*Diff; sound.noTone(); sound.tone(NOTE_D3,50); ard.setRGBled(255,0,0); delay(5); ard.setRGBled(0,0,0);} break;
            case 9: if (ard.everyXFrames(5)) {playerobj.H -= 1*Diff; sound.noTone(); sound.tone(NOTE_D3,50); ard.setRGBled(255,0,0); delay(5); ard.setRGBled(0,0,0);} break;

            
            }
         }
      }
  }
  for (byte j=0;j<6;j++){
    if (Bullet[j].GetActive()){
      Bullet[j].UPPos(playerobj.x,playerobj.y);
      Bullet[j].Update();
    }
  }
    for (byte i=0;i<ONum;i++){
      for (byte j=0;j<6;j++){
        if ((Bullet[j].GetActive()) && (Objects[i].IsActive()) && (Objects[i].GetType() >= 6) && (Collision(Objects[i].GetX()-4,Objects[i].GetY()-4,Bullet[j].GetX()-4,Bullet[j].GetY()-4))){
          Objects[i].Damage();
          Bullet[j].Kill();
          if (!Objects[i].IsActive()){
            playerobj.Kill++;
            DropItem(Objects[i].GetX(),Objects[i].GetY(),true);
            }
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
  for (byte i=0;i<6;i++){
    if (Bullet[i].GetActive()){
      Bullet[i].Display();
    }
  }
}

const uint16_t DeathNotes[] PROGMEM = {NOTE_A3,500,NOTE_REST,100,NOTE_A3,500,NOTE_REST,100,NOTE_A3,250,NOTE_REST,100,NOTE_A3,250,NOTE_REST,50,NOTE_C3,500,NOTE_REST,100,NOTE_B3,250,NOTE_REST,100,NOTE_B3,250,NOTE_REST,100,NOTE_A3,500,NOTE_REST,100,NOTE_B3,250, TONES_END};

void Death(){
  sprites.drawOverwrite(CENTERX-7,CENTERY-7,Flowers,0);
  ard.setCursor(0,0);
  ard.print(F("SCORED:"));
  ard.println(POINTS);
  ard.print(F("GotToLevel:"));
  ard.println(Level);
  if (ard.justPressed(A_BUTTON)||ard.justPressed(B_BUTTON)){sound.noTone(); gameState = GameState::MainMenu; Level = 0; POINTS = 0;}
  }

void win(){
  sprites.drawOverwrite(CENTERX-7,CENTERY-7,Ardu,0);
  ard.setCursor(0,0);
  ard.println(F("WellDone!"));
  ard.print(F("YOU SCORED:"));
  ard.println(POINTS);
  if (ard.justPressed(A_BUTTON)||ard.justPressed(B_BUTTON)){sound.noTone(); gameState = GameState::MainMenu; Level = 0; POINTS = 0;}
}

void MapEnding(){
    int padd = playerobj.Coins * 5;    
    int kadd = playerobj.Keys * 10;
    int killp = playerobj.Kill * 15;
    ard.setCursor(0,0);
    ard.print(F("Level:"));
    ard.println(Level);
    ard.print(F("Kills:"));
    ard.println(playerobj.Kill);
    ard.print(F("Coins:"));
    ard.println(playerobj.Coins);
    ard.print(F("Keys:"));
    ard.println(playerobj.Keys);
    ard.print(F("TimeBonus:"));
    ard.println((Timer/10));
    ard.print(F("Level Points:"));
    ard.println(kadd+padd+killp+(Timer/10));
    
    ard.print(F("Total Points:"));
    ard.println(POINTS+kadd+padd+killp+(Timer/10));
    
    if ((ard.everyXFrames(240)) || (ard.justPressed(A_BUTTON))) {
        gameState = GameState::LoadMap;
        POINTS += padd + kadd + killp + (Timer/10);
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
  ard.println((uint8_t)playerobj.H);
  ard.print(F("T:"));
  ard.print(Timer);
  }


void UpdateGame(){
  playerobj.PlayerMovement();
  UpdateObjects();
  DisplayEnviroment();
  DisplayPlayer();
  DisplayObjects();
  DrawHud();
  if (ard.everyXFrames(15)) {Timer--;}
  if (Timer == 0){playerobj.H = 0;}
  if (playerobj.H <= 0) {sound.noTone(); sound.tones(DeathNotes); gameState = GameState::Dead;}
}

