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
    case 1: if ((Frame < 5)&&(ard.everyXFrames(12))) {Frame++;} else {Frame = 0;} break;
    case 6: if ((x < relx)&&(Walkable(x+1,y))) {x++;} else {if ((x > relx)&&(Walkable(x-1,y))) {x--;}}
            if ((y < relx)&&(Walkable(x,y+1))) {y++;} else {if ((y > relx)&&(Walkable(x,y-1))) {y--;}}
            break;
            
    case 7: if ((x < relx)&&(Walkable(x+2,y))) {x+=2;} else {if ((x > relx)&&(Walkable(x-2,y))) {x-=2;}}
            if ((y < relx)&&(Walkable(x,y+2))) {y+=2;} else {if ((y > relx)&&(Walkable(x,y-2))) {y-=2;}}
            break;
            
    case 8: if ((x < relx)&&(Walkable(x+3,y))) {x+=3;} else {if ((x > relx)&&(Walkable(x-3,y))) {x-=3;}}
            if ((y < relx)&&(Walkable(x,y+3))) {y+=3;} else {if ((y > relx)&&(Walkable(x,y-3))) {y-=3;}}
            if ((Frame < 1)&&(ard.everyXFrames(30))) {Frame++;} else {Frame = 0;} break;
  }
}


void SpriteClass::Display(){
  int _x = (relx-x)-4;
  int _y = (rely-y)-4;
  sprites.drawOverwrite(CENTERX-_x,CENTERY-_y,SpriteEnviroment,(Frame+offset));
}

