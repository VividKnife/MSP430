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

extern volatile int fivemscount;
extern volatile int fivemsblink;
extern volatile int sw1_bolling;
extern volatile int sw2_bolling; 
volatile int sw1_en;
volatile int sw2_en;
 volatile int sw1_count;
 volatile int sw2_count;
//******************************************************************************
//-----------------------------------------------------------------------------


 //******************************************************************************
//
//  Description: This function contains the switch interrupt 
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//globles sw1_bolling
 //sw2_bolling
 //sw1_count
 //sw2_count
//******************************************************************************

 
 #pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR(void){
 fivemscount++;
 fivemsblink++;
 
 
   sw1_count++;
 if(sw1_count>=debounce_time &&sw1_en==disable){
 P4IE |= SW1;
 sw1_en=enable;
 P4IFG &=~SW1;
 PJOUT &=~LED3;

 }
 
   sw2_count++;
 if(sw2_count>=debounce_time &&sw2_en==disable){
 P4IE |=SW2;
 sw2_en=enable;
 P4IFG &=~SW2;
 PJOUT &=~LED3;

 }
 TA0CCR0 += TA0CCR0_INTERVAL; // Add Offset to TACCR0
 
 
}

 
 
 
#pragma vector=PORT4_VECTOR
//Create Interrupt Service Routine Function with ¡°__interrupt¡±
__interrupt void switch_interrupt(void) {
  
// Switch 1
 if (P4IFG & SW1) {
   //P4IES &=~SW1; // set p4.0 to low/ hi edge interrupt
   P4IE &=~SW1;
   sw1_en=disable;
   sw1_count=zero;
   P4IFG &=~SW1;
    PJOUT ^= LED1;
    PJOUT |=LED3;
   sw1_bolling =enable;
   
   
   }

 if (P4IFG & SW2) {

 PJOUT ^= LED2; // Toggle LED 1 on to indicate boot ISR working
 sw2_bolling =enable;
 sw2_en=disable;
    P4IFG &=~SW2;
    P4IE &=~SW2;
    sw2_count=zero;
  PJOUT |=LED3;
    
 }
// Enable the Timer Interrupt for the debounce.
}





//#pragma vector=TIMER0_A1_VECTOR 
//__interrupt void TIMER0_A1_ISR(void){ 
//  switch(__even_in_range(TA0IV,14)){ 
//    case  0: break;                    // No interrupt 
//    case  2:                           // CCR1 not used
//      TA0CCR1 += TA0CCR1_INTERVAL;     // Add Offset to TACCR1 
//      break; 
//    case  4:                           // CCR2 not used 
////  Put code here for CCR2  
//      TA0CCR2 += TA0CCR2_INTERVAL;     // Add Offset to TACCR2 
//      break; 
//    case  6: break;                    // reserved 
//    case  8: break;                    // reserved 
//    case 10: break;                    // reserved 
//    case 12: break;                    // reserved 
//    case 14:                           // overflow 
////  Put code here for overflow 
//      break; 
//    default: break;  
//  }
//}