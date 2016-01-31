
//******************************************************************************
//
//  Description: This file contains the cofigure function that change the value of black_line
//
//
//  shufan kang
//  Sep 2015
//  Built with IAR Embedded Workbench Version: 6.30.2
//******************************************************************************

//------------------------------------------------------------------------------
#include "msp430.h"
#include "functions.h"
#include "macros.h"



volatile extern unsigned int ADC_Thumb;
volatile extern unsigned int ADC_Right_Detector;
volatile extern unsigned int ADC_Left_Detector;
volatile extern unsigned int lineDecOld;
volatile extern unsigned int FirsttimeLine;

volatile extern unsigned int processCount;
volatile extern unsigned int RWhiteReading;
volatile extern unsigned int LWhiteReading;
volatile extern unsigned int RBlackReading;
volatile extern unsigned int LBlackReading;
volatile extern unsigned int LAvg;
volatile extern unsigned int RAvg;
volatile extern unsigned int avg_black;
volatile extern unsigned int avg_white;

 extern int black_line;

 
 
//******************************************************************************
//
//  Description: This function contains the cofigure function that change the value of black_line
//
//
//  shufan kang
//  Sep 2015
//  Built with IAR Embedded Workbench Version: 6.30.2
// 
//
// volatile extern unsigned int ADC_Thumb;
//volatile extern unsigned int ADC_Right_Detector;
//volatile extern unsigned int ADC_Left_Detector;
//volatile extern unsigned int lineDecOld;
//volatile extern unsigned int FirsttimeLine;
//
//volatile extern unsigned int processCount;
//volatile extern unsigned int RWhiteReading;
//volatile extern unsigned int LWhiteReading;
//volatile extern unsigned int RBlackReading;
//volatile extern unsigned int LBlackReading;
//volatile extern unsigned int LAvg;
//volatile extern unsigned int RAvg;
//volatile extern unsigned int avg_black;
//volatile extern unsigned int avg_white;
//
// extern int black_line;
//********************************************************************************
 
 
 void ifconfig(void){//ask need a config for detector or not
 
  sw1_bolling=zero;
   sw2_bolling=zero;
   fivemsblink = CLEAR;
   Init_displayC();
   display_1="Want config?";
   display_2="SW1 NO";
   display_3="SW2 YES";
   display_4="Shufan K"; 
   Display_Process();   
  while(fivemsblink < tensec&&!sw1_bolling && !sw2_bolling);
   if(sw2_bolling){
   configMode();
   }
 }
 
 
 
 void adc_test(void){//call this function to test the adc input
 char Thumb[SMALL_RING_SIZE];
 char Right[SMALL_RING_SIZE];
 char Left[SMALL_RING_SIZE];
 int adc_testing =enable;
 while(adc_testing){

P1OUT |= IR_LED;
ADC_Process();
ADC_Process();
ADC_Process();
if(fivemsblink>half_halfsec){
   toString( Thumb, ADC_Thumb); //puts values into string
   toString( Right, ADC_Right_Detector); //puts values into string
   toString( Left, ADC_Left_Detector); //puts values into string

  display_1 = Thumb;
  display_2 = Right;
  display_3 = Left;  
  display_4="sw2 back";  // display information 

  Display_Process();
  fivemsblink=zero;
  }
if(sw2_bolling){
sw2_bolling=disable;
adc_testing = disable;
}
  
 
 }//end of testing loop
 P1OUT &=~ IR_LED;
 }
 
 
 
 
void configMode(void)
{
//  int LB,LW,RB,RW,LO,RO;
  int LB,LW,LO;
  int avg_out_IR;
  //int diff;
    sw1_bolling=zero;
  
   char LBlackS[ARRAYL]; //char arrays for output
   char RBlackS[ARRAYL];
   char LWhiteS[ARRAYL];
   char RWhiteS[ARRAYL];
   char IR_OUT[ARRAYL];
   char white_IR[ARRAYL];
   char black_IR[ARRAYL];
 Init_displayC(); 
display_2="config mode";
  Display_Process();
   P1OUT |= IR_LED; //turn on IR
   fivemsblink = CLEAR;
   
   while(fivemsblink < tensec &&!sw1_bolling);
  
  Init_displayC();  
display_2="Place White"; //tell user what to do
  Display_Process();

 sw1_bolling=zero;
   fivemsblink = CLEAR;
    
   while(fivemsblink < tensec&&!sw1_bolling);
 
  
  ADC_Process(); // get adc values
   ADC_Process();
    ADC_Process(); 
   LWhiteReading = ADC_Left_Detector; //read in values and store 
   RWhiteReading = ADC_Right_Detector;
  
   toString( LWhiteS, LWhiteReading); //puts values into string
 toString(RWhiteS, RWhiteReading);
 
  Init_displayC(); 
   display_1="L White Reading";
   display_2=LWhiteS;
    
   display_3="R White Reading"; //prints out message for user
   display_4=RWhiteS;
   Display_Process();
  
   
     fivemsblink = CLEAR;
    sw1_bolling=zero;
     while(fivemsblink < tensec&&!sw1_bolling);
    Init_displayC(); 
   display_2="Place Black";
  Display_Process();
  fivemsblink = CLEAR;
    sw1_bolling=zero;
  while(fivemsblink < tensec&&!sw1_bolling);
   
   

  ADC_Process();
   ADC_Process();
    ADC_Process();
    
 LBlackReading = ADC_Left_Detector; //reads in line values for black
 RBlackReading = ADC_Right_Detector;
 
  toString(LBlackS, LBlackReading); //puts values into a string
 toString(RBlackS, RBlackReading);
 
 Init_displayC(); 
  display_1="L Black Reading "; //prints out message for user
    display_2=LBlackS;


    display_3="R Black Reading "; //prints out message for user
    display_4=RBlackS;
  Display_Process();

 //lcd_out("   Black Done   ",LCD_LINE_1);

 
 //lcd_out("L: " + LBlackS + "R: " + RBlackS,LCD_LINE_2);

   LW=LWhiteReading;
   LB=LBlackReading;
   //RW=RWhiteReading;
  // RB=RBlackReading;
  
 //  avg = (LW + RW)/second; //gets average of black and white so we can tell if it detects lines
 //  avg = (LB + RB)/second;
   
avg_white= LW;
avg_black=LB;

 sw1_bolling=zero;
   fivemsblink = CLEAR;
    
   while(fivemsblink < tensec&&!sw1_bolling);
   Init_displayC(); 
   display_2="configing";
   display_3="IR conditions" ; 
   Display_Process();
   P1OUT &=~ IR_LED;//turn off IR
    sw1_bolling=zero;
   fivemsblink = CLEAR;
    
   while(fivemsblink < tensec&&!sw1_bolling);
    
    
    ADC_Process();
    ADC_Process();
    ADC_Process();
   
    LO=ADC_Left_Detector;
  //  RO=ADC_Right_Detector;
    
    avg_out_IR=LO;
    
    

    
    LW=avg_white;
    LB=avg_black;
    //black_line=(LW+LB)/second/second*third;
    black_line = LB-halfsec;//halfsec=100
    
    toString(IR_OUT, avg_out_IR);
    toString(black_IR, avg_black);
    toString(white_IR, avg_white);
    
    Init_displayC();
    display_1= IR_OUT;
    display_2= black_IR;
    display_3= white_IR;
    display_4="sw2 End";
    Display_Process();  


    sw1_bolling=zero;
   fivemsblink = CLEAR;
    
   while(!sw2_bolling);
  

}
