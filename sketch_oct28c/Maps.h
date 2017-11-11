#pragma once
#define MAXOBJECT 25
#define MAXENVIROMENT 15
#define CENTERX 63
#define CENTERY 31

#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define TILE_SIZE 16

#define MAP_HEIGHT  10
#define MAP_WIDTH  10
#define MAP_SIZE MAP_HEIGHT*MAP_WIDTH


#define CLOSED_CHEST  0
#define OPEN_CHEST  5 //Walkable

#define BARREL  4
#define EXPLOSIVE_BARREL  16

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
#define OFFSET 5



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
*/





const uint8_t PROGMEM MAP_1[] = {
  //Map Dimentions
  MAP_HEIGHT, MAP_WIDTH,
  //PLAYER STARTING POSITION
  0, 0,
  //MAP DATA
  9, 8, 8, 8, 8, 1, 11, 1, 1, 0,
  1, 1, 1, 1, 8, 1, 8, 1, 1, 0,
  8, 8, 8, 1, 8, 8, 8, 1, 1, 0,
  8, 8, 8, 1, 8, 0, 8, 1, 1, 0,
  8, 8, 8, 1, 8, 8, 8, 1, 1, 0,
  8, 8, 8, 1, 8, 8, 8, 1, 1, 0,
  8, 8, 8, 1, 8, 1, 2, 1, 1, 0,
  8, 8, 8, 1, 8, 1, 8, 1, 1, 0,
  8, 8, 8, 1, 8, 1, 3, 1, 1, 0,
  8, 8, 8, 1, 8, 1, 1, 1, 1, 0,
  8, 8, 8, 15, 8, 1, 1, 1, 0, 0,
  //Number of Objects
  7,
  //Objects
  //<ID><xpos><ypos><Health>
  1, 1, 3, 0,
  1, 1, 4, 0,
  1, 1, 5, 0,
  1, 1, 6, 0,
  1, 1, 7, 0,
  1, 1, 8, 0,
  1, 1, 9, 0,
  //Number of Oparators
  1,
  //Oparator (Switch locations/active points)
  //<xpos of switch><ypos of switch><x active><y active><State>
  6,0,3,9,0
};

const uint8_t PROGMEM MAP_2[] = {
  //Map Dimentions
  MAP_HEIGHT, MAP_WIDTH,
  //PLAYER STARTING POSITION
  0, 0,
  //MAP DATA
  9, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 3,
  //Number of Objects
  1,
  //Objects
  //<ID><xpos><ypos><Health>
  1, 2, 2, 0,
  //Number of Oparators
  0,
  //Oparator (Switch locations/active points)
  //<xpos of switch><ypos of switch><x active><y active><State>
};

byte Level;

const uint8_t * Maps[] = { MAP_1, MAP_2 };
uint8_t Map[MAP_SIZE];

int GetTileX(int x)
{
	if(x < 0)
  		return (x / TILE_WIDTH) - 1;
  	else
  		return (x / TILE_WIDTH);
}

int GetTileY(int y)
{
	if(y < 0)
  		return (y / TILE_HEIGHT) - 1;
  	else
  		return (y / TILE_HEIGHT);
}

int GetTileXOffset(int x)
{
	if(x < 0)
  		return (TILE_WIDTH + (x % TILE_WIDTH));
  	else
  		return (x % TILE_WIDTH);
}

int GetTileYOffset(int y)
{
	if(y < 0)
  		return (TILE_HEIGHT + (y % TILE_HEIGHT));
  	else
  		return (y % TILE_HEIGHT);
}

uint8_t GetBlock(int x, int y) {
  if ((x < 0) || (y < 0) || (x > MAP_WIDTH) || (y > MAP_HEIGHT)) {
    return BLANK_WALL;
  }
  uint8_t Block = Map[(x + (y * MAP_WIDTH))];
  return Block;
}

void SetBlock(int x, int y, uint8_t bl) {
  if ((x < 0) || (y < 0) || (x > MAP_WIDTH) || (y > MAP_HEIGHT)) {
    return;
  }
  Map[(x + (y * (MAP_WIDTH)))] = bl;
}



bool Walkable(int x, int y) {
  switch (GetBlock(GetTileX(x), GetTileY(y))) {
    case OPEN_DOOR:
    case DOWN_STAIRS:
    case EMPTY:
    case OPEN_CHEST:
    	return true;
    default:
    	return false;
  }
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
        case EXPLOSIVE_BARREL: SetBlock(x1,y1,EMPTY); break;
      }
    }
  }
}







