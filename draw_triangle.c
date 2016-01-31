//------------------------------------------------------------------------------
//  Description: This file contains the Main Routine - "While" Operating System
//
//  Shufan Kang
//  Fall 2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

//------------------------------------------------------------------------------
void draw_triangle(void){//This function draws Triangle
//------------------------------------------------------------------------------

// 
//------------------------------------------------------------------------------

  Time_Sequence = 0;                        
  int i=0;
  display_1 = "ThirdTask";
  posL1 = 0;
  display_2 = "DrawTriangle";
  posL2 = 0;
  display_3 = "ECE306";
  posL3 = 2;
  display_4 = "Skang";
  posL4 = 3;
  big = 0;
  Display_Process();
     while(Time_Sequence<300){}
   Time_Sequence=0;
  
//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
 
   while(i<3){
     Init_LEDs();
     i++;
     Time_Sequence=0;
     while(Time_Sequence<5){
     P3OUT |= LED5; 
     P3OUT |= LED7;     
     }
       
     turn_angle();
     Time_Sequence=0;
     
    while(Time_Sequence<5){
     P3OUT |= LED5; 
     P3OUT |= LED7;     
     }
    Init_LEDs();
    Time_Sequence=0;
   
   }
     
   
   
  

//------------------------------------------------------------------------------
current_job=triangle;
next_job=finish_job;
}


void turn_angle(void){

Time_Sequence = 0;
int i=0;
 
  while(i<5) {                            // Can the Operating system run
  switch(Time_Sequence){
    case 20:                               // 1000 msec  
      if(one_time){
        Init_LEDs();                        // Initialize LEDs
        one_time = 0;
        i++;
      }
      Time_Sequence = 0;                    // 
    case 18:                               // 1000 msec  
      if(one_time){
       // P3OUT |= LED5;                      // Change State of LED 5
        one_time = 0;
      }
    case 4:                               // 500 msec  
      if(one_time){
        P3OUT |= LED7;                      // Change State of LED 7
        one_time = 0;
      }

      break;                                // 
    default: break; 
  }

  if(Time_Sequence > 20){
    Time_Sequence = 0;
  }
 }

}

