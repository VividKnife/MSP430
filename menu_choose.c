//******************************************************************************
//
//  Description: This file contains the menu chooses
//
//
//  Shufan Kang
//  Fall 2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


void menu_1_function1(void){
int menu_stay = enable;
display_1 = sub1_menu_1_inf;
display_2 = "selected";
display_3 = "sw1 start";
display_4 = "sw2 back";
Display_Process();
while(menu_stay){
  if(sw1_bolling){
  sw1_bolling=disable;
  //run the function 
  adc_test();
  menu_stay=disable;
  }
  if(sw2_bolling){
  sw2_bolling=disable;
  menu_stay=disable; //back to menu
  }

}

}

void menu_1_function2(void){
int menu_stay = enable;
display_1 = sub1_menu_2_inf;
display_2 = "selected";
display_3 = "sw1 start";
display_4 = "sw2 back";
Display_Process();
while(menu_stay){
  if(sw1_bolling){
  sw1_bolling=disable;
  //run the function 
  //configMode();
  
  }
  if(sw2_bolling){
  sw2_bolling=disable;
  menu_stay=disable; //back to menu
  }

}


}
void menu_1_function3(void){
int menu_stay = enable;  
display_1 = sub1_menu_3_inf;
display_2 = "selected";
display_3 = "sw1 start";
display_4 = "sw2 back";
Display_Process();
while(menu_stay){
  if(sw1_bolling){
  sw1_bolling=disable;
  //run the function 
   back_light();
    menu_stay=disable; //back to menu
  }
  if(sw2_bolling){
  sw2_bolling=disable;
  menu_stay=disable; //back to menu
  }

}

}
void menu_1_function4(void){
int menu_stay = enable;
display_1 = sub1_menu_4_inf;
display_2 = "selected";
display_3 = "sw1 start";
display_4 = "sw2 back";
Display_Process();
while(menu_stay){
  if(sw1_bolling){
  sw1_bolling=disable;
 //config_straight();
  //run the function 
    menu_stay=disable; //back to menu
  }
  if(sw2_bolling){
  sw2_bolling=disable;
  menu_stay=disable; //back to menu
  }

}
}
void menu_1_function5(void){
int menu_stay = enable;
display_1 = sub1_menu_5_inf;
display_2 = "selected";
display_3 = "sw1 start";
display_4 = "sw2 back";
Display_Process();
while(menu_stay){
  if(sw1_bolling){
  sw1_bolling=disable;
  //run the function 
  sleep_setting();
  }
  if(sw2_bolling){
  sw2_bolling=disable;
  menu_stay=disable; //back to menu
  }

}


}