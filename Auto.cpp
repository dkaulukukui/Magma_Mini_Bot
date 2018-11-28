#include <string.h>
#include <Arduino.h>
#include "MiniBot.h"
#include "Auto.h"




void loopauto(void){

//insert autonomous loop mode code here


  
}

void figure_eight_auto(void){

//insert autonomous figure eight mode code here


  
}

void destruct_auto(void){

//insert auto destruct mode code here

  
}


//////////////////////////////////////////////////////////////////////
/* This Function calls all the routines above when the mode is selected*/

 void Autobot(int mode){

   //switch statement to assign actions to different buttons
  switch(mode) {
    case 1: /// Auto Loop mode
          loopauto();
      break;
    case 2:  ///Auto Figure 8 mode
          figure_eight_auto();
      break;
    case 3:  ///Auto Destruction Derby Mode
          destruct_auto();
      break;
    default:
         //Code here will never run since this function is only called when a command is sent
      break;               
    }
 }
