#include "Gamer.h"

Gamer g;

int waitTime = 100;
int waitTimeDefault = waitTime;
int changeAmount = 50;
int changeAmountDefault = changeAmount;
#define NUMFRAMES 6


/* Each of these blocks of code
 corresponds to one frame of the
 animation.

 A "1" turns the light in that
 position on, a "0" turns it off.
 */
byte frames[NUMFRAMES][8] = {
  {
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111
  },
  {
    B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00111100,
    B00100100,
    B00100100,
    B00111100,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00111100,
    B00100100,
    B00100100,
    B00111100,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B00000000
  }
};

void setup() {
  /* This code initialises the DIY Gamer
   Kit.
   */
  g.begin();
}

void loop() {

  if(g.isPressed(DOWN)){
    waitTime = waitTime + changeAmount;
    g.playTone(180);
    delay(50);
    g.stopTone();
  }
  else if (g.isPressed(UP)){
    if (waitTime-changeAmount > 0){
      waitTime = waitTime - changeAmount;
      g.playTone(180);
      delay(50);
      g.stopTone();
    }
  }
  else if (g.isPressed(LEFT)){
    changeAmount = changeAmount - 10;
    if (changeAmount <= 0){
      changeAmount = 1;
    }else{
      g.playTone(180);
      delay(50);
      g.stopTone();
      delay(50);
      g.playTone(180);
      delay(50);
      g.stopTone();
    }

    
  }
  else if (g.isPressed(RIGHT)){
    changeAmount = changeAmount + 10;
    g.playTone(180);
    delay(50);
    g.stopTone();
    delay(50);
    g.playTone(180);
    delay(50);
    g.stopTone();
  }
  else if (g.isPressed(START)){
    waitTime = waitTimeDefault;
    changeAmount = changeAmountDefault;
    g.playTone(180);
    delay(1000);
    g.stopTone();
  }


  
  for (int i = 0; i < NUMFRAMES; i++) {
    g.printImage(frames[i]);
    delay(waitTime);
  }
}
