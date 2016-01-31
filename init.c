//******************************************************************************
//
//  Description: This file contains the initialise conditions 
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
//  Description: //this function enable interrupts and initialies displays
//
//
//  Shufan Kang
//  Fall 2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************


void Init_Conditions(void){
//------------------------------------------------------------------------------
// Initializations Configurations
//------------------------------------------------------------------------------
// Interrupts are disabled by default, enable them. 
  enable_interrupts();
  display_1 = &display_line_1[start];
  display_2 = &display_line_2[start];
  display_3 = &display_line_3[start];
  display_4 = &display_line_4[start];
  //Rx_char = &USB_Char_Rx[start];
  //Tx_char = &USB_Char_Tx[start];
 

//------------------------------------------------------------------------------
}

