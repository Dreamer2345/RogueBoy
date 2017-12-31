#pragma once
#define MAXLEVEL 12
#define MAXOBJECT 15
#define MAXENVIROMENT 15
#define CENTERX 63
#define CENTERY 31

#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define TILE_SIZE 16

uint8_t MAP_HEIGHT = 10;
uint8_t MAP_WIDTH = 10;
#define MAP_SIZE 100



#define CLOSED_CHEST  0
#define OPEN_CHEST  5 //Walkable

#define BARREL  4
#define EXPLOSIVE_BARREL  16
#define RUBBLE 18

#define LOCKED_DOOR  2
#define OPEN_DOOR  6 //walkable
#define SPEAR_DOOR  15

#define SWITCH_ON  10
#define SWITCH_OFF  11


#define BLANK_WALL  1
#define FULL_BLOCK_WALL  7
#define WINFDOW_WALL  13
#define TORCH_WALL  12
#define SIGN_WALL  14


#define UP_STAIRS  9
#define DOWN_STAIRS  3 //Walkable
#define LOCKED_STAIRS  17

#define EMPTY  8 //Walkable
#define OFFSET 4
/*
uint8_t enum Block {CLOSED_CHEST,
                    BLANK_WALL,
                    LOCKED_DOOR,
                    DOWN_STAIRS,
                    BARREL,
                    OPEN_CHEST,
                    OPEN_DOOR,
                    FULL_BLOCK_WALL,
                    EMPTY,
                    UP_STAIRS,
                    SWITCH_ON,
                    SWITCH_OFF,
                    TORCH_WALL,
                    WINDOW_WALL,
                    SIGN_WALL,
                    SPEAR_DOOR,
                    EXPLOSIVE_BARREL,
                    LOCKED_STAIRS,
                    RUBBLE};

*/
/*
   MAP DEFINITIONS
   0 - Closed_chest
   1 - Blank_Wall
   2 - Locked_Door
   3 - Stairs_Down
   4 - Barrel
   5 - Open_chest
   6 - Open_Door
   7 - Full_Block_Wall
   8 - Blank Space
   9 - Stairs_UP
   10 - Switch_ON
   11 - Switch_OFF
   12 - Wall_Torch
   13 - Window_Wall
   14 - Sign_wall
   15 - Spear_Door
   16 - explosive_barrel
   17 - Locked_Stairs_Down
   18 - Rubble


          1:Coin
          2:Sack o cash
          3:Jelly Filled Doughnut
          4:Key
          5:Ham
          6:Floater
          7:Skull
          8:Spider
          9:Bat

const uint8_t PROGMEM TEST_MAP[] = {
  //Map Dimentions (unused)
  MAP_HEIGHT, MAP_WIDTH,
  //PLAYER STARTING POSITION
  0, 0,
  //MAP DATA
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 17, 16, 15, 14, 13, 12, 11, 10,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
  //Number of Objects
  8,
  //Objects
  //<ID><xpos><ypos><Health>
  1, 5, 2, 1,
  2, 5, 3, 1,
  3, 5, 4, 1,
  4, 5, 5, 1,
  5, 6, 2, 1,
  6, 6, 3, 1,
  7, 6, 4, 1,
  8, 6, 5, 1,
  //Number of Oparators
  3,
  //Oparator (Switch locations/active points)
  //<xpos of switch><ypos of switch><x active><y active>
  9,7,9,2,
  9,7,9,3,
  9,7,9,4,
};
*/

const uint8_t PROGMEM MAP_12[] = {
4,9,
0,0,
9,8,11,1,
8,8,11,1,
8,8,11,1,
8,8,11,1,
1,15,1,1,
1,15,1,1,
1,15,8,1,
1,6,1,1,
1,3,1,1,
2,
9,2,6,50,
1,2,6,100,
9,
2,0,1,4,
2,0,1,6,
2,1,1,5,
2,1,1,7,
2,2,1,5,
2,2,1,6,
2,3,1,4,
2,3,1,6,
2,3,1,7,
};


const uint8_t PROGMEM MAP_11[] = {
10,6,
1,1,
8,8,8,1,1,1,0,1,3,1,
8,9,8,2,8,8,4,1,8,1,
8,8,8,1,8,8,1,1,8,8,
1,4,1,1,1,2,1,1,1,8,
8,8,8,1,8,8,8,8,8,8,
8,8,8,1,1,8,1,1,1,1,
11,
3,1,5,20,
8,2,4,20,
8,0,4,20,
9,5,1,20,
4,0,5,20,
9,4,2,20,
9,5,5,20,
8,4,4,20,
7,7,4,20,
6,8,2,20,
7,9,4,20,
0,
};

const uint8_t PROGMEM MAP_10[] = {
7,7,
0,0,
9,8,8,8,1,8,8,
8,8,8,8,4,8,8,
8,8,8,8,1,8,8,
8,8,8,17,1,8,8,
1,4,1,1,1,1,1,
8,8,8,8,1,1,1,
8,8,8,8,1,1,1,
15,
1,1,1,10,
1,1,2,10,
1,2,2,10,
1,2,1,10,
4,3,6,10,
8,3,6,50,
8,2,6,50,
8,1,6,50,
8,0,6,50,
7,6,3,50,
7,6,2,50,
7,6,1,50,
7,6,0,50,
1,6,0,50,
1,6,1,50,
0,
};


const uint8_t PROGMEM MAP_9[] = {
9,9,
5,8,
10,8,8,1,8,8,8,8,8,
8,8,8,1,8,1,1,1,8,
1,8,13,1,6,1,1,1,8,
8,8,8,15,8,8,8,1,8,
1,1,1,1,8,8,11,1,8,
8,8,8,6,8,8,8,1,8,
15,13,1,1,1,1,12,1,8,
8,8,8,8,1,8,8,8,8,
8,8,8,17,1,9,8,8,8,
5,
4,1,1,30,
9,1,1,30,
7,5,4,30,
8,8,3,30,
8,5,0,30,
5,
6,4,4,2,
6,4,3,3,
6,4,3,5,
0,0,3,5,
0,0,0,6,
};

const uint8_t PROGMEM MAP_8[] = {
10,10,
0,0,
9,1,1,8,8,2,8,8,8,8,
8,1,8,8,1,1,1,1,1,8,
8,8,8,1,1,1,1,1,1,8,
1,8,1,8,1,1,8,8,8,8,
1,8,1,8,1,1,8,8,8,8,
8,8,8,8,1,1,8,8,8,8,
4,1,8,1,1,1,1,1,1,1,
8,1,8,8,8,1,1,1,1,1,
8,1,1,1,2,1,1,1,1,1,
8,1,1,1,3,1,1,1,1,1,
9,
4,0,9,1,
6,3,3,30,
7,3,3,30,
4,3,3,1,
6,9,3,100,
2,6,4,1,
2,7,4,1,
2,8,4,1,
2,9,4,1,
0,
};


const uint8_t PROGMEM MAP_7[] = {
10,10,
0,0,
9,8,8,1,8,8,8,8,8,1,
8,8,1,1,8,8,1,8,8,1,
1,4,1,8,8,1,1,8,1,1,
8,8,8,8,8,1,8,8,1,1,
8,8,1,1,1,1,8,8,8,8,
1,1,1,8,8,8,8,1,8,8,
1,1,8,8,8,8,1,1,1,8,
1,8,8,8,8,1,14,8,8,8,
1,8,8,1,1,1,8,8,8,1,
1,17,8,1,1,8,8,8,1,1,
10,
4,5,9,30,
8,1,4,30,
8,0,4,30,
8,0,3,30,
9,7,0,30,
9,8,1,30,
7,7,8,30,
6,2,8,30,
6,1,7,30,
6,8,7,30,
0,
};

const uint8_t PROGMEM MAP_6[] = {
9,10,
2,0,
12,1,9,1,13,1,1,13,1,
4,8,8,8,11,1,8,4,1,
1,1,15,1,1,1,4,8,1,
8,8,8,8,8,8,8,8,1,
12,1,16,1,1,1,8,4,1,
8,8,8,8,8,1,4,4,1,
8,8,17,8,8,1,4,11,1,
1,1,1,1,1,1,16,16,1,
1,1,1,1,1,1,8,8,1,
1,1,1,1,1,1,8,0,1,
6,
7,6,9,10,
8,7,8,10,
7,6,8,10,
8,6,9,30,
7,6,8,30,
8,7,8,30,
4,
4,1,2,2,
7,6,7,7,
7,6,6,7,
7,6,2,4,
};

const uint8_t PROGMEM MAP_5[] = {
10,10,
0,0,
9,8,8,8,8,6,8,8,8,1,
8,8,8,4,1,1,1,1,6,1,
1,1,1,1,1,8,2,8,8,1,
8,8,8,8,2,8,1,8,8,0,
1,1,1,1,1,8,1,1,1,1,
1,8,8,0,1,8,8,1,1,1,
1,8,1,1,8,8,8,1,1,1,
1,8,8,8,8,8,8,1,1,1,
1,1,1,1,1,8,1,1,1,17,
1,1,1,1,1,8,8,8,8,8,
14,
6,5,6,20,
9,6,6,20,
9,6,7,20,
9,5,7,20,
9,4,7,20,
9,4,6,20,
8,7,2,20,
8,8,3,20,
9,7,3,20,
3,8,2,20,
2,1,3,20,
2,2,3,20,
2,3,3,20,
4,0,3,20,
0,
};

const uint8_t PROGMEM MAP_3[] = {
9,6,
3,0,
4,8,8,9,8,8,8,1,1,
8,8,8,8,8,8,8,2,8,
11,8,8,8,8,8,8,1,8,
1,1,15,1,15,1,1,1,11,
1,1,8,1,8,1,1,1,1,
1,1,0,1,3,1,1,1,1,
2,
8,8,2,1,
9,2,4,20,
2,
0,2,2,3,
8,3,4,3,
};


const uint8_t PROGMEM MAP_4[] = {
9,7,
4,0,
4,4,8,8,9,4,8,4,4,
4,8,8,8,11,8,8,8,4,
8,8,4,8,8,8,4,8,8,
1,16,1,15,1,15,1,15,1,
1,8,1,8,1,8,1,8,1,
1,8,1,8,1,8,1,8,1,
1,17,1,11,1,0,1,11,1,
1,
8,3,5,1,
4,
4,1,3,3,
7,6,5,3,
3,6,7,3,
7,6,1,3,
};


const uint8_t PROGMEM MAP_2[] = {
7,5,
0,0,
9,8,8,8,8,8,8,
8,8,8,4,4,8,8,
8,8,8,0,4,8,4,
4,8,8,8,8,8,4,
4,4,8,8,8,8,17,
0,
0,
};

const uint8_t PROGMEM MAP_1[] = {
4,4,
0,0,
9,8,8,8,
8,8,8,8,
8,8,8,8,
8,8,8,3,
4,
1,1,1,100,
1,1,2,100,
1,2,2,100,
1,2,1,100,
0,
};


byte Level;

const uint8_t * Maps[] = {MAP_1, MAP_2 ,MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8 , MAP_9,MAP_10,MAP_11,MAP_12};
uint8_t Map[MAP_SIZE];




uint8_t GetTileX(uint16_t x)
{
  return (x / TILE_WIDTH);
}

uint8_t GetTileY(uint16_t y)
{
  return (y / TILE_HEIGHT);
}

uint8_t GetTileXOffset(uint16_t x)
{
  return (x % TILE_WIDTH);
}

uint8_t GetTileYOffset(uint16_t y)
{
  return (y % TILE_HEIGHT);
}

uint16_t GetDist(int x,int y,int x1,int y1){uint16_t ret = (abs(GetTileX(x)-GetTileX(x1))+abs(GetTileY(y)-GetTileY(y1))); return ret;}

uint8_t GetBlock(uint16_t x, uint16_t y) {
  if ((x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
    return BLANK_WALL;
  } else {
    uint8_t Block = Map[(x + (y * MAP_WIDTH))];
    return Block;
  }
}

void SetBlock(uint8_t x, uint8_t y, uint8_t bl) {
  if ((x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
    return;
  }
  Map[(x + (y * (MAP_WIDTH)))] = bl;
}



bool Walkable(uint16_t x, uint16_t y) {
  uint8_t p[4];
  bool Walk = true; 
  p[0] = (GetBlock(GetTileX(x-4), GetTileY(y-4)));
  p[1] = (GetBlock(GetTileX(x+3), GetTileY(y-4)));
  p[2] = (GetBlock(GetTileX(x-4), GetTileY(y+3)));
  p[3] = (GetBlock(GetTileX(x+3), GetTileY(y+3)));
  for (byte i=0; i<4;i++){
    if (!((p[i] == OPEN_DOOR)||(p[i] == UP_STAIRS)||(p[i] == DOWN_STAIRS)||(p[i] == EMPTY)||(p[i] == OPEN_CHEST)||(p[i] == RUBBLE))){
      	Walk = false;
        break;
      }
  }
  return Walk;
}

class EnviromentClass{
  public:
    EnviromentClass(){}
    void SetEnv(byte _x, byte _y, byte _x1, byte _y1, bool _Active){x = _x; y = _y; x1 = _x1; y1 = _y1; Active = _Active;}
    bool CheckStart(byte _x,byte _y){return ((_x==x)&&(_y==y));}
    byte FinishX(){return x1;}
    byte FinishY(){return y1;}
    bool IsActive(){return Active;}
  private:
    byte x;
    byte y;
    byte x1;
    byte y1;
    bool Active;
  
};

EnviromentClass Envi[MAXENVIROMENT];
byte ENum = 0;

void UpdateEBlock(byte x,byte y){
  for (int i = 0; i < ENum; i++){
    if (Envi[i].CheckStart(x,y)&&Envi[i].IsActive()) {
      byte x1 = Envi[i].FinishX();
      byte y1 = Envi[i].FinishY();
      switch(GetBlock(x1,y1)){
        case SPEAR_DOOR: SetBlock(x1,y1,OPEN_DOOR); break;
        case OPEN_DOOR: SetBlock(x1,y1,SPEAR_DOOR); break;
        case LOCKED_STAIRS: SetBlock(x1,y1,DOWN_STAIRS); break;
        case DOWN_STAIRS: SetBlock(x1,y1,LOCKED_STAIRS); break;
        case EXPLOSIVE_BARREL: SetBlock(x1,y1,RUBBLE); break;
      }
    }
  }
}







