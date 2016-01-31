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

void Init_LEDs(void){// this function initialies the LEDs
//------------------------------------------------------------------------------
// LED Configurations
//------------------------------------------------------------------------------
// Turns on all 8 LEDs
//  PJOUT &= ~LED1;
//  PJOUT &= ~LED2;
//  PJOUT &= ~LED3;
  fivemsblink = zero;
  while (fivemsblink<onesec);
  PJOUT |= RESET;
//  P3OUT &= ~LED5;
//  P3OUT &= ~LED6;
//  P3OUT &= ~LED7;
//  P3OUT &= ~LED8;
//------------------------------------------------------------------------------
}