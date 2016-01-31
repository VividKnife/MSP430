//******************************************************************************
//
//  Description: This file contains the initialise LEDs
//
//
//  Shufan Kang
//  Fall 2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


//******************************************************************************
//
//  Description: This funtion contains the initialise LEDs
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************

void Display_Process(void){//display current information
  ClrDisplay();
  lcd_out(display_1, LCD_HOME_L1, posL1);
  lcd_out(display_2, LCD_HOME_L2, posL2);
  lcd_out(display_3, LCD_HOME_L3, posL3);
  lcd_out(display_4, LCD_HOME_L4, posL4);
}