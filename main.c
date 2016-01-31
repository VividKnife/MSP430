//------------------------------------------------------------------------------
//  Description: This file contains the Main Routine - "While" Operating System
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//// 
//// Global Variables

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include "macros.h"

// Global Variables
volatile unsigned char control_state[CNTL_STATE_INDEX];
volatile unsigned int Time_Sequence;
char led_smclk;
volatile char one_time;
extern char display_line_1[line];
extern char display_line_2[line];
extern char display_line_3[line];
extern char display_line_4[line];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
char posL1;
char posL2;
char posL3;
char posL4;
char size_count;
char big;
int switch_option;
int current_job;
int next_job;
int time_test;
volatile int fivemscount;
volatile int fivemsblink;
volatile int sw1_bolling;
volatile int sw2_bolling; 
extern volatile unsigned int ADC_Thumb;
 
volatile unsigned int right_forward_speed;
volatile unsigned int left_forward_speed;
volatile  unsigned int processCount;
volatile  unsigned int RWhiteReading;
volatile  unsigned int LWhiteReading;
volatile  unsigned int RBlackReading;
volatile  unsigned int LBlackReading;
volatile  unsigned int LAvg;
volatile  unsigned int RAvg;
volatile unsigned int avg_black;
volatile unsigned int avg_white;
int black_line;
volatile int back_light_state;
volatile unsigned int sleep_time;
int sleep_enable;

//------------------------------------------------------------------------------
//  Description: This file contains the Main Routine - "While" Operating System
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2

// Main Program
// This is the main routine for the program. Execution of code starts here.
// doing the project 4
  // global used here : switch_option,fivemscount,display_1,display_2
// 
//// ---------------------------------------------------------------------------



//------------------------------------------------------------------------------
void main(void){
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
  Init_Ports();                             // Initialize Ports
  PJOUT |= RESET;
  Init_Clocks();                            // Initialize Clock System 
  Init_Conditions();
  Init_ADC(); 
  Init_Timers();                            // Initialize Timers
  Init_LEDs();                              // Initialize LEDs
  Init_LCD();                               // Initialize LCD
  Init_displayC();
  Init_Serial_UCA1();                          //init serial communication port
  Init_Serial_UCA0();   
  
  black_line = black_line_def; 
  back_light_state|=LCD_BACKLITE;
  left_forward_speed = max_speed;
  right_forward_speed = max_speed;
  sleep_enable = enable;
  sleep_time = sleep_time_1min;
while(ALWAYS){ 
  //PJOUT |= IOT_WAKEUP;
main_menu();
 // Init_rx_tx();
}//  while always end
  }//main end 
  









