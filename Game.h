

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



void UpdateGame(){
  playerobj.PlayerMovement();
  DisplayEnviroment();
  DisplayPlayer();
}

