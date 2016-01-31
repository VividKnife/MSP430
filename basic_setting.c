//******************************************************************************
//
//  Description: This file contains the basic function of board
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void back_light(void){
display_2="sw1 open";
display_3="sw1 close";
display_1="";
display_4="sw2 back";
Display_Process();
int DOING = enable;
while(DOING){
  if(sw1_bolling){
  sw1_bolling=disable;
  P3OUT ^= LCD_BACKLITE;
  back_light_state ^= LCD_BACKLITE;
  //PJOUT ^= IOT_WAKEUP;
  
  }
  if(sw2_bolling){
  sw2_bolling=disable;
  DOING = disable;
  
  }

}

}



void sleep_setting(void){
    int setting = enable;
    while(setting){
        fivemsblink=zero;
        while(fivemsblink<QUATERSEC);
        ADC_Process();
        ADC_Process();
        ADC_Process();
        display_1 = "Sleep_Time";
        if(ADC_Thumb>=start_menu && ADC_Thumb<=menu_1){
            display_2 = "30  sec";
            display_3 = "SW1 APPLY";
            display_4 = "SW2 BACK";
            Display_Process();
            if(sw1_bolling){// if sw1 is pressed, run function under this menu
                sw1_bolling=disable;
                sleep_time=sleep_time_30sec;
                setting = disable;
                sleep_enable=enable;
            }
    
        }else if(ADC_Thumb>menu_1 && ADC_Thumb<=menu_2){
            display_2 = "1  min";
            display_3 = "SW1 APPLY";
            display_4 = "SW2 BACK";
            Display_Process();  
            if(sw1_bolling){
                sw1_bolling=disable;
                sleep_time=sleep_time_1min;
                setting = disable;
                sleep_enable=enable;                
            } 
  
        }else if(ADC_Thumb>menu_2 && ADC_Thumb<=menu_3){
            display_2 = "5   mins";
            display_3 = "SW1 APPLY";
            display_4 = "SW2 BACK";
            Display_Process();
            if(sw1_bolling){
                sw1_bolling=disable;
                sleep_time=sleep_time_5min;
                setting = disable;
                sleep_enable=enable;
            }
  
    
         }else if(ADC_Thumb>menu_3 && ADC_Thumb<=menu_4){
            display_2 = "10  mins";
            display_3 = "SW1 APPLY";
            display_4 = "SW2 BACK";
            Display_Process();
            if(sw1_bolling){
                sw1_bolling=disable;
                sleep_time=sleep_time_10min;
                setting = disable;
                sleep_enable=enable;
            }
  
            
         }else if(ADC_Thumb>menu_4 && ADC_Thumb<=menu_5){// menu 5 set up
            display_2 = "Never_Sleep";
            display_3 = "SW1 APPLY";
            display_4 = "SW2 BACK";
            Display_Process();
            if(sw1_bolling){
                sw1_bolling=disable;
                sleep_enable=disable;
                TA1CCTL1 &=~ CCIE;
                setting = disable;  
            }
         }
    }//end of setting while loop

}

void waiteQsec(void){
fivemscount = zero;
while(fivemscount<half_halfsec);

}
void waite1sec(void){
fivemscount = zero;
while(fivemscount<onesec);

}







/*
void config_straight(void){
  display_1 = "config";
  display_2 = "straight";
  display_3 = "SW1 START";
  display_4 = "SW2 BACK";
  Display_Process();
  int DOING = enable;
  while(DOING){
    if(sw1_bolling){
      sw1_bolling = disable;
      fivemsblink = zero;
      while(fivemsblink<fivesec);
      fivemscount = zero;
      while(DOING){
        fivemsblink=zero;
        while(fivemsblink<2);
        P1OUT |= IR_LED;
        ADC_Process();
        ADC_Process();
        ADC_Process();
        if(ADC_Right_Detector>black_line && ADC_Left_Detector>black_line){//if car under black line speed up
          if(left_forward_speed<max_speed){
            left_forward_speed+=speed_change;     }
          if(right_forward_speed<max_speed){
             right_forward_speed+=speed_change; }
          forward_stright();
        }        
        if(ADC_Right_Detector<black_line && ADC_Left_Detector>black_line){//if car is turning right, lower the left speed
        left_forward_speed -= speed_change; 
        forward_stright();
        } 
        if(ADC_Right_Detector>black_line && ADC_Left_Detector<black_line){//if car is turning left, lower the right speed
        left_forward_speed -= speed_change;  
        forward_stright();
        } 
        if(ADC_Right_Detector<black_line && ADC_Left_Detector<black_line){
        reverse_stright();
        }
        if(fivemscount>tensec){
          stop_car();
          DOING=disable;}
      
      }
    }
    if(sw2_bolling){
    sw2_bolling = disable;
    DOING = disable;
    
    }
  
  }
  P1OUT &=~ IR_LED;


}*/