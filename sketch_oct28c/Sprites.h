#pragma once
#include <Arduboy2.h>

class SpriteClass{
  public:
    SpriteClass() { };

    void setSprite(int _x,int _y,byte _H,byte _type,byte _offset,bool _Active){x = _x;y = _y;H = _H;type = _type;Frame = 0;offset=_offset;Active = _Active;};
    void UPPos(int _x,int _y){relx = _x; rely = _y;};
    void SpriteAI();
    void Display();
    byte GetFrame(){return Frame;}
    byte GetType(){return type;}
    bool IsActive(){return Active;}
    void SetActive(bool _k){Active = _k;}
    byte GetX(){return x;}
    byte GetY(){return y;}
  private:
    byte offset;
    int x;
    int y;
    int relx;
    int rely;
    byte H;
    byte type;
    byte Frame;
    bool Active;
  };

void SpriteClass::SpriteAI(){
  switch(type){
    case 1: if (ard.everyXFrames(24)) { ++Frame; Frame %= 6; } break;
    case 6: if ((x < relx)&&(Walkable(x+1,y))) {x++;} else {if ((x > relx)&&(Walkable(x-1,y))) {x--;}}
            if ((y < relx)&&(Walkable(x,y+1))) {y++;} else {if ((y > relx)&&(Walkable(x,y-1))) {y--;}}
            break;
            
    case 7: if ((x < relx)&&(Walkable(x+1,y))) {x++;} else {if ((x > relx)&&(Walkable(x-1,y))) {x--;}}
            if ((y < relx)&&(Walkable(x,y+1))) {y++;} else {if ((y > relx)&&(Walkable(x,y-1))) {y--;}}
            break;
            
    case 8: if ((x < relx)&&(Walkable(x+1,y))) {x++;} else {if ((x > relx)&&(Walkable(x-1,y))) {x--;}}
            if ((y < relx)&&(Walkable(x,y+1))) {y++;} else {if ((y > relx)&&(Walkable(x,y-1))) {y--;}}
            break;        
            
    case 9: if ((x < relx)&&(Walkable(x+1,y))) {x++;} else {if ((x > relx)&&(Walkable(x-1,y))) {x--;}}
            if ((y < relx)&&(Walkable(x,y+1))) {y++;} else {if ((y > relx)&&(Walkable(x,y-1))) {y--;}}
            if (ard.everyXFrames(24)) { ++Frame; Frame %= 2; } break;
  }
}


void SpriteClass::Display(){
  int _x = (relx-x)-4;
  int _y = (rely-y)-4;
  sprites.drawExternalMask(CENTERX-_x,CENTERY-_y,SpriteEnviroment,SpriteMask,(Frame+offset),(Frame+offset));
}

