#include "RBELib.h"
#include <stdlib.h>

#define LED_PORT
#define LED_DIR
#define LED_NUMPINS

#define BUTTON_PORT
#define BUTTON_DIR
#define BUTTON_NUMPINS

int main(void){

  //set pins (LED out and Button in)
  setPinsDir(LED_PORT, LED_DIR, LED_NUMPINS);
  setPinsDir(BUTTON_PORT, BUTTON_DIR, BUTTON_NUMPINS);

  while(1){
    if(getPinsVal(BUTTON_PORT, BUTTON_NUMPINS)){
      setPinsVal(LED_PORT, 1, LED_NUMPINS);
    }  else {
      setPinsVal(LED_PORT, 0, LED_NUMPINS);
    }
  }

  return 0;
}
