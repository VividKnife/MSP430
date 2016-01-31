
//******************************************************************************
//
//  Description: This file contains car move function
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


//******************************************************************************
//
//  Description: This function contains car move function
//
//
//  shufan kang
//  Sep 2015
//  Built with IAR Embedded Workbench Version: 6.30.2
//Golobe use fivemsblink,
//fivemscount
//Black_line 
//ADC_Left_Detector
//ADC_Right_Detector
//******************************************************************************

/*
void car_drive(void){
  int avg;
  int job=first;
  //int adc_R,
  int adc_L;
  int time_save;
  Init_displayC();
  
P1OUT |= IR_LED;
ADC_Process();
ADC_Process();
ADC_Process();
//adc_R=ADC_Right_Detector;
adc_L=ADC_Left_Detector;
avg=adc_L;

display_2="forward";
Display_Process();


while(avg<black_line&&job==first){
//right_forward_on();
//left_forward_on();
ADC_Process();
ADC_Process();
ADC_Process();
//adc_R=ADC_Right_Detector;
adc_L=ADC_Left_Detector;
avg=adc_L;

  forward_stright();
}
job=second;
stop_car();
fivemsblink = CLEAR;
while(fivemsblink < onesec);
fivemscount = CLEAR;

display_2="reverse";
Display_Process();

reverse_stright();
fivemsblink = CLEAR;
while(fivemsblink < twosec);
avg=zero;

while(avg<black_line&&job==second){
reverse_stright();

ADC_Process();
ADC_Process();
ADC_Process();
//adc_R=ADC_Right_Detector;
adc_L=ADC_Left_Detector;
avg=adc_L;
}
job=third;
time_save=fivemscount;
stop_car();
time_save=time_save/second;
fivemsblink = CLEAR;
while(fivemsblink < halfsec);

fivemscount=zero;

display_2="forward";
Display_Process();


while(fivemscount<time_save){
forward_stright();
} 
stop_car();
fivemsblink = CLEAR;
while(fivemsblink < halfsec);

fivemsblink = CLEAR;

display_2="clockwise";
Display_Process();

while(fivemsblink<twosec){
right_forward_on();
left_reverse_on();
}
stop_car();
fivemsblink = CLEAR;
while(fivemsblink < halfsec);

fivemsblink = CLEAR;

display_2="cunterCLK";
Display_Process();

while(fivemsblink<twosec){
left_forward_on();
right_reverse_on();
}
stop_car();



}*/