#include <Arduboy2.h>
#include <Sprites.h>
#include "Bitmaps.h"
Arduboy2 ard;
Sprites sprites;

void MainMenu(){
  byte Choice = 0;
  bool Update = false;
  while(!(ard.justPressed(A_BUTTON))) {
    while(!ard.nextFrame()){} 
    ard.pollButtons();
    if (ard.justPressed(UP_BUTTON) && (Choice < 18)) {
        Choice += 1;
        Update = true;
    } 
    if (ard.justPressed(DOWN_BUTTON) && (Choice > 0)) {
        Choice -= 1;
        Update = true;
    } 
    if (Update){
      ard.clear();
      ard.print(Choice);  
      ard.display();
      Update = false;
    }
    
    }
sprites.drawSelfMasked(20,20,BackgroundEnviroment,Choice);
ard.display();
}


void setup() {
  ard.begin();
  ard.clear();
}

void loop() {
 MainMenu();
}
