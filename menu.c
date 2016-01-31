//******************************************************************************
//
//  Description: This file contains the menu function
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


void main_menu(void){
  //int in_menu = 1;
//  int waite__;       // use for help menu
//  waite__ = enable;
//  display_1 = "NEED HELP";
//  display_3 = "  SW1 YES";
//  display_4 = "  SW2 NO";
//  display_2 = "FOR MENU?";
//  Display_Process();
//  while(waite__){
//   if (sw1_bolling){
//     sw1_bolling=disable;
//    menu_help();
//    waite__ = disable;
//  }
//  if (sw2_bolling) {
//    sw2_bolling=disable;
//    waite__ = disable;
//  
//  }
//  } 
  while(ALWAYS){
  fivemsblink = zero;
  while(fivemsblink<QUATERSEC);
  ADC_Process();
  ADC_Process();
  ADC_Process();
  display_1 = "   MENU";
  if(ADC_Thumb>=start_menu && ADC_Thumb<=menu_1){//menu 1 set up
  display_2 = "menu 1";
  display_3 = menu_1_inf;
  display_4 = "-> menu 2";

  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable;
    sub_menu_1();
   
  }
  
  
  }else if(ADC_Thumb>menu_1 && ADC_Thumb<=menu_2){//menu 2 set up
  display_2 = "menu 2";
  display_3 = menu_2_inf;
  display_4 = "-> menu 3";
  fivemsblink = zero;
  Display_Process();
  
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable;
      webpage_drive();
  }   
  
  
  }else if(ADC_Thumb>menu_2 && ADC_Thumb<=menu_3){//menu 3 set up
  display_2 = "menu 3";
  display_3 = menu_3_inf;
  display_4 = "-> menu 4";
  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable;
      recesive_PC();
   // menu_3_function(); 

  }
  
  
  
  }else if(ADC_Thumb>menu_3 && ADC_Thumb<=menu_4){//menu 4 set up 
  display_2 = "menu 4";
  display_3 = menu_4_inf;
  display_4 = "-> menu 5"; 
  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable; 
    sub_menu_2();
  
  }
  
  
  
  
  }else if(ADC_Thumb>menu_4 && ADC_Thumb<=menu_5){// menu 5 set up
  display_2 = "menu 5";
  display_3 = menu_5_inf;
  display_4 = "->  N/A";  
  Display_Process();
  if (sw1_bolling){// if sw1 is pressed, run function under this menu
      sw1_bolling=disable;
      
   // menu_5_function();
  
  }
    
  }// more menu options by change the value of menu_1 to menu_n

  
  
  }//end of menu while loop


}








void menu_help(void){
    int waite_help = enable;
    display_1 = "USE Thumb";
    display_2 = "ForMenuOpt";
    display_3 = "Sw1 Enter";
    display_4 = "Sw2 Back";
    Display_Process();
    fivemsblink=zero;
    while(fivemsblink<onesec);
    while(waite_help){      
      
      if (sw1_bolling){
        waite_help = disable;
        sw1_bolling = disable;

    }
      if (sw2_bolling){
        waite_help = disable;
        sw2_bolling = disable;
    }
    
}
}