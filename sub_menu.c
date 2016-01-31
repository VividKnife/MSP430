//******************************************************************************
//
//  Description: This file contains the sub_menu function
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


void sub_menu_1(void){
  int sub_menu_stay = enable;  
  while(sub_menu_stay){
  fivemsblink = zero;
  while(fivemsblink<half_halfsec);
  ADC_Process();
  ADC_Process();
  ADC_Process();
  display_1 = menu_1_inf;
  display_3 = "SW1 ENTER";
  display_4 = "SW2 BACK";
  if(ADC_Thumb>=start_menu && ADC_Thumb<=menu_1){//menu 1 set up
  display_2 = sub1_menu_1_inf;
  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable;
    menu_1_function1();
   
  }
  if(sw2_bolling){
  sw2_bolling = disable;
  sub_menu_stay = disable;
  
  }
  
  
  }else if(ADC_Thumb>menu_1 && ADC_Thumb<=menu_2){//menu 2 set up
  display_2 = sub1_menu_2_inf;
  fivemsblink = zero;
  Display_Process();
  
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable;
    menu_1_function2();
   
  }
    if(sw2_bolling){
  sw2_bolling = disable;
  sub_menu_stay = disable;
  
  }
  
  
  }else if(ADC_Thumb>menu_2 && ADC_Thumb<=menu_3){//menu 3 set up
  display_2 = sub1_menu_3_inf;
  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable;
    menu_1_function3(); 

  }
    if(sw2_bolling){
  sw2_bolling = disable;
  sub_menu_stay = disable;
  
  }
  
  
  
  }else if(ADC_Thumb>menu_3 && ADC_Thumb<=menu_4){//menu 4 set up 
  display_2 = sub1_menu_4_inf; 
  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable; 
    menu_1_function4();
  
  }
    if(sw2_bolling){
  sw2_bolling = disable;
  sub_menu_stay = disable;
  
  }
  
  
  
  
  }else if(ADC_Thumb>menu_4 && ADC_Thumb<=menu_5){// menu 5 set up
  display_2 = sub1_menu_5_inf;
  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable; 
    menu_1_function5();
  
  }
    if(sw2_bolling){
  sw2_bolling = disable;
  sub_menu_stay = disable;
  
  }
    
  }// more menu options by change the value of menu_1 to menu_n

  
  
  }//end of menu while loop


}




void sub_menu_2(void){
int sub_menu_stay = enable;  
while(sub_menu_stay){
    fivemsblink = zero;
    while(fivemsblink<half_halfsec);
        ADC_Process();
        ADC_Process();
        ADC_Process();
        display_1 = menu_1_inf;
        display_3 = "SW1 ENTER";
        display_4 = "SW2 BACK";
        if(ADC_Thumb>=start_menu && ADC_Thumb<=menu_1){//menu 1 set up
            display_2 = sub2_menu_1_inf;            
            Display_Process();
            if(sw1_bolling){// if sw1 is pressed, run function under this menu
                sw1_bolling=disable;
                wifi_home_mode();
            }
            if(sw2_bolling){
                sw2_bolling = disable;
                sub_menu_stay = disable;
            }
        }
        else if(ADC_Thumb>menu_1 && ADC_Thumb<=menu_2){//menu 2 set up
            display_2 = sub2_menu_2_inf;
            fivemsblink = zero;
            Display_Process(); 
            if(sw1_bolling){// if sw1 is pressed, run function under this menu
                sw1_bolling=disable;
                wifi_ncsu_mode();   
            }
            if(sw2_bolling){
                sw2_bolling = disable;
                sub_menu_stay = disable;
            }  
        }
        else if(ADC_Thumb>menu_2 && ADC_Thumb<=menu_3){//menu 3 set up
            display_2 = sub2_menu_3_inf;
            Display_Process();
            if(sw1_bolling){// if sw1 is pressed, run function under this menu
                sw1_bolling=disable;
                check_IP();
                //ip_detect();
            }
            if(sw2_bolling){
                sw2_bolling = disable;
                sub_menu_stay = disable;  
            }
        }
        else if(ADC_Thumb>menu_3 && ADC_Thumb<=menu_4){//menu 4 set up
            display_2 = sub2_menu_4_inf;
            fivemsblink = zero;
            Display_Process(); 
            if(sw1_bolling){// if sw1 is pressed, run function under this menu
                sw1_bolling=disable;
                send_ping();   
            }
            if(sw2_bolling){
                sw2_bolling = disable;
                sub_menu_stay = disable;
            }  
        }        
        else if(ADC_Thumb>menu_4 && ADC_Thumb<=menu_5){//menu 5 set up
            display_2 = sub2_menu_5_inf;
            fivemsblink = zero;
            Display_Process(); 
            if(sw1_bolling){// if sw1 is pressed, run function under this menu
                sw1_bolling=disable;
                receive_wifi();   
            }
            if(sw2_bolling){
                sw2_bolling = disable;
                sub_menu_stay = disable;
            }  
        }  
        
  }  // end of sub_menu_while loop
}