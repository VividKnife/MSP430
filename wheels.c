////------------------------------------------------------------------------------
////  Description: This file contains the car move functions
////
////  Shufan Kang
////  Fall 2015
////  Built with IAR Embedded Workbench Version: V6.30.2
////------------------------------------------------------------------------------
//
////------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

/*
  TB1CCR1 = Right forward
  TB1CCR2 = Right reverse
  TB2CCR1 = Left forward
  TB2CCR2 = Left Revers

*/

void forward_stright(int speed){
//  unsigned int tmp_right,tmp_left;
//  tmp_right = right_forward_speed;
//  tmp_left = left_forward_speed;
//  TB1CCR1 = tmp_right;
//  TB2CCR1 = tmp_left;
  TB1CCR1 = (move_speed*speed);
  TB2CCR1 = (move_speed*speed+__1);  
 
  
  left_forward_on();
  right_forward_on();
}


void reverse_stright(int speed){
  
  TB1CCR2 = (move_speed*speed);
  TB2CCR2 = (move_speed*(speed+__1));  

  right_reverse_on();
  left_reverse_on();  
  
  
 }

void turn_right(int angle){
  TB1CCR1 = low_speed;
  TB2CCR2 = low_speed;
    right_reverse_on();
  left_forward_on();

//  fivemsblink = zero;
//  while(fivemsblink<(angle-__10));
//  stop_car();
  
}

void turn_left(int angle){
  TB1CCR2 = low_speed;
  TB2CCR1 = low_speed;

  right_forward_on();
  left_reverse_on();
//  fivemsblink = zero;
//  while(fivemsblink<(angle-__10));
//  stop_car();
}






void stop_car(void)
{
left_both_off();
right_both_off();


}






//--------------------------------------------------------------------------
void right_forward_off(void){// turn off right forward
  P3SEL0 &= ~R_FORWARD;//  R_FORWARD is selected
  P3SEL1 &= ~R_FORWARD;//  R_FORWARD  is selected
  P3DIR  |= R_FORWARD;//  R_FORWARD set to output   *****change to GPIO pin to turn right forward off***
}
//---------------------------------------------------------------------------

void right_reverse_off(void){// turn off right reverse
  P3SEL0 &= ~R_REVERSE;//  R_REVERSE is selected
  P3SEL1 &= ~R_REVERSE;//  R_REVERSE  is selected
  P3DIR  |= R_REVERSE;//  R_REVERSE set to output  ***** change to GPIO pin to turn right revese off****
  
}
//----------------------------------------------------------------------------
void right_forward_on(void){//turn off right reverse before turn forward on
  right_reverse_off();
  P3SEL0 |= R_FORWARD;//  R_FORWARD is selected
  P3SEL1 &= ~R_FORWARD;//  R_FORWARD  is selected
  P3DIR  |= R_FORWARD;//  R_FORWARD set to output ***** change to TB1 pin to turn right forward on****
}
//----------------------------------------------------------------------------
void right_reverse_on(void){// turn off right forward before turn reverse on
  right_forward_off();
  P3SEL0 |= R_REVERSE;//  R_REVERSE is selected
  P3SEL1 &= ~R_REVERSE;//  R_REVERSE  is selected
  P3DIR  |= R_REVERSE;//  R_REVERSE set to output **** change to TB1 pin to turn right reverse on****
}
//left wheels stars here
//============================================================================
void left_forward_off(void){
  P3SEL0 &= ~L_FORWARD;//  L_FORWARD is selected
  P3SEL1 &= ~L_FORWARD;//  L_FORWARD  is selected
  P3DIR  |= L_FORWARD;//  L_FORWARD set to output  *** change to GPIO pin to turn left forward off***
}
//---------------------------------------------------------------------------

void left_reverse_off(void){
  P3SEL0 &= ~L_REVERSE;//  L_REVERSE is selected
  P3SEL1 &= ~L_REVERSE;//  L_REVERSE  is selected
  P3DIR  |= L_REVERSE;//  L_REVERSE set to output ** change to GPIO pin to turn left reverse off****
}
//----------------------------------------------------------------------------
void left_forward_on(void){
  left_reverse_off();
  P3SEL0 |= L_FORWARD;//  L_FORWARD is selected
  P3SEL1 &= ~L_FORWARD;//  L_FORWARD  is selected
  P3DIR  |= L_FORWARD;//  L_FORWARD set to output  ***change to TB2 pin to turn left forward on****
}
//----------------------------------------------------------------------------
void left_reverse_on(void){
  left_forward_off();
  P3SEL0 |= L_REVERSE;//  L_FORWARD is selected
  P3SEL1 &= ~L_REVERSE;//  L_FORWARD  is selected
  P3DIR  |= L_REVERSE;//  L_FORWARD set to output  **** change to TB2 pin tp turn left reverse on****
}
//both stop start here
//============================================================================
void right_both_off(void){
 right_reverse_off();
 right_forward_off();
}
//----------------------------------------------------------------------------
void left_both_off(void){
 left_reverse_off();
 left_forward_off();
}


