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
volatile int sw1_en;
volatile int sw2_en;
volatile int sw1_count;
volatile int sw2_count;
volatile unsigned int sleeping__;
volatile unsigned int timeA1_CCR1;
//******************************************************************************
//------------------------------------------------------------------------------
// TimerA0 0 Interrupt handler
 
 
 
 
 
#pragma vector = TIMER1_A0_VECTOR
__interrupt void Timer1_A0_ISR(void){
 fivemscount++;
 fivemsblink++;
 
   sw1_count++;
 if(sw1_count>=debounce_time &&sw1_en==disable){
 P4IE |= SW1;
 sw1_en=enable;
 P4IFG &=~SW1;
 }
 
   sw2_count++;
 if(sw2_count>=debounce_time &&sw2_en==disable){
 P4IE |=SW2;
 sw2_en=enable;
 P4IFG &=~SW2;
 }
 TA1CCR0 += TA1CCR0_INTERVAL; // Add Offset to TACCR0
 
 
}



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
   sw1_bolling =enable;
   sleeping__ = zero; //clear sleeping time
    if(back_light_state){
      P3OUT |= LCD_BACKLITE;
      }
   PJOUT |= IOT_WAKEUP;
   LPM4_EXIT; // wake up from low power mode

    sleeping__=zero;

   
   }

 if (P4IFG & SW2) {

 sw2_bolling =enable;
 sw2_en=disable;
    P4IFG &=~SW2;
    P4IE &=~SW2;
    sw2_count=zero;
    if(back_light_state){
      P3OUT |= LCD_BACKLITE;}
       PJOUT |= IOT_WAKEUP;
    LPM4_EXIT; // wake up from low power mode
    sleeping__=zero;
    
 }
// Enable the Timer Interrupt for the debounce.
}





#pragma vector=TIMER1_A1_VECTOR 
__interrupt void TIMER1_A1_ISR(void){ 
  switch(__even_in_range(TA1IV,14)){ 
    case  0: break;                    // No interrupt 
    case  2:                           // CCR1 not used 
//  Put code here for CCR1 
      timeA1_CCR1++;
      sleeping__++;
      unsigned int ST;
      ST = sleep_time;
      if(sleeping__==ST)
      {
      PJOUT &=~ IOT_WAKEUP;
      P3OUT &=~ LCD_BACKLITE;
      //LPM4;
      __bis_SR_register(LPM4_bits + GIE);
        //PJOUT &=~ IOT_WAKEUP;
      }
      
      TA1CCR1 += TA1CCR1_INTERVAL;     // Add Offset to TACCR1 
      break; 
    case  4:                           // CCR2 not used 
//  Put code here for CCR2  
      
      
     // TA2CCR2 += TA2CCR2_INTERVAL;     // Add Offset to TACCR2 
      break; 
    case  6: break;                    // reserved 
    case  8: break;                    // reserved 
    case 10: break;                    // reserved 
    case 12: break;                    // reserved 
    case 14:                           // overflow 
//  Put code here for overflow 
      break; 
    default: break;  
  }
}


//
//
//#pragma vector = TIMER1_A0_VECTOR
//__interrupt void Timer1_A0_ISR(void){
//  
//  
//  
//  
//   TA1CCR0 += TA1CCR0_INTERVAL; // Add Offset to TACCR0
//  
//  
//}