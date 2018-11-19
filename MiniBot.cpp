#include <string.h>
#include <Arduino.h>
#include "MiniBot.h"

//////////////////////////////////////////////////////////////////////
/* This Function is where you assign an action to each button press*/

 void buttoncommands(int buttnum,boolean pressed){

   //switch statement to assign actions to different buttons
  switch(buttnum) {
    case 1:
      if(pressed){
        //Insert code to run if button 1 is pressed here
        Serial.println("Button 1 pressed");
      } else{
         //Insert code to run when button 1 is released here
        Serial.println("Button 1 released");
      }              
      break;
    case 2:
      if(pressed){
        //Insert code to run if button 2 is pressed here
        Serial.println("Button 2 pressed");        
      } else{
         //Insert code to run when button 2 is released here
        Serial.println("Button 2 released");         
      } 
      break;
    case 3:
      if(pressed){
        //Insert code to run if button 3 is pressed here
         Serial.println("Button 3 pressed");       
      } else{
         //Insert code to run when button 3 is released here
        Serial.println("Button 3 released");         
      } 
      break;
    case 4:
      if(pressed){
        //Insert code to run if button 4 is pressed here
        Serial.println("Button 4 pressed");        
      } else{
         //Insert code to run when button 4 is released here
        Serial.println("Button 4 released");         
      } 
      break;
    case 5:
      if(pressed){
        //Insert code to run if button 5 is pressed here
         Serial.println("Button 5 pressed");       
      } else{
         //Insert code to run when button 5 is released here
        Serial.println("Button 5 released");         
      } 
      break;
    case 6:
      if(pressed){
        //Insert code to run if button 6 is pressed here
        Serial.println("Button 6 pressed");        
      } else{
         //Insert code to run when button 6 is released here
        Serial.println("Button 6 released");         
      } 
      break;
    case 7:
      if(pressed){
        //Insert code to run if button 7 is pressed here
         Serial.println("Button 7 pressed");       
      } else{
         //Insert code to run when button 7 is released here
        Serial.println("Button 7 released");        
      } 
      break;
    case 8:
      if(pressed){
        //Insert code to run if button 8 is pressed here
         Serial.println("Button 8 pressed");       
      } else{
         //Insert code to run when button 8 is released here
        Serial.println("Button 8 released");         
      } 
      break;
    default:
         //Code here will never run since this function is only called when a command is sent
      break;               
    }
 }

void stop_all_motors(void){

  //Add any motors added to to bot to this function

  analogWrite(MOTOR_1_PWM_PIN, 127);
  analogWrite(MOTOR_2_PWM_PIN, 127);

}

//// Function to ENABLE motors, DO NOT CHANGE

void enable_motors(void) {
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
}

//// Function to DISABLE motors, DO NOT CHANGE

void disable_motors(void) {
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
}
