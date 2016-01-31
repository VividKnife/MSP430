//******************************************************************************
//
//  Description: This file contains the interrupt that count up time 
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//globles fivemscount
//******************************************************************************






#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

//******************************************************************************
//
//  Description: This function contains the interrupt that count up time 
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//globles fivemscount
//******************************************************************************


extern volatile int fivemscount;
extern volatile int fivemsblink;
extern volatile int sw1_bolling;
extern volatile int sw2_bolling; 
extern volatile int sw1_en;
extern volatile int sw2_en;
extern volatile int sw1_count;
extern volatile int sw2_count;
//******************************************************************************
//------------------------------------------------------------------------------
// TimerA0 0 Interrupt handler
 
 
 
 
 
//#pragma vector = TIMER0_A0_VECTOR
//__interrupt void Timer0_A0_ISR(void){
// fivemscount++;
// fivemsblink++;
// 
// 
//   sw1_count++;
// if(sw1_count>=debounce_time &&sw1_en==disable){
// P4IE |= SW1;
// sw1_en=enable;
// P4IFG &=~SW1;
// PJOUT &=~LED3;
// }
// 
//   sw2_count++;
// if(sw2_count>=debounce_time &&sw2_en==disable){
// P4IE |=SW2;
// sw2_en=enable;
// P4IFG &=~SW2;
// PJOUT &=~LED3;
// }
// TA0CCR0 += TA0CCR0_INTERVAL; // Add Offset to TACCR0
// 
// 
//}



