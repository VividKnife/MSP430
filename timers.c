//******************************************************************************
//
//  Description: This file contains the initialise timers 
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


//******************************************************************************
//
//  Description: This function initialise timers 
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************


void Init_Timers(void){//this function initialies the timers
//------------------------------------------------------------------------------
// Timer Configurations
//------------------------------------------------------------------------------
  fivemscount = zero;
  fivemsblink = zero;
 Init_Timer_A0(); //
 Init_Timer_A1(); // 
//  Init_Timer_B0(); // 
 Init_Timer_B1(); //  
 Init_Timer_B2();   //  Required for provided compiled code to work
//------------------------------------------------------------------------------
}


//------------------------------------------------------------------------------
// Timer A1 initialization
//#pragma vector = TIMER0_A1_VECTOR;

//******************************************************************************
//
//  Description: This function initialise A1 timer
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************




void Init_Timer_A1(void) {
 TA1CTL = TASSEL__SMCLK; // SMCLK source
 TA1CTL |= TACLR; // Resets TA0R, clock divider, count direction
 TA1CTL |= MC__CONTINOUS; // Continuous up
 TA1CTL |= ID__2; // Divide clock by 8
 TA1CTL &= ~TAIE; // Disable Overflow Interrupt
 TA1CTL &= ~TAIFG; // Clear Overflow Interrupt flag

 TA1EX0 = TAIDEX_7; // Divide clock by an additional 8

//enable_interrupts();
 TA1CCR0 = TA1CCR0_INTERVAL; // CCR0
 TA1CCTL0 |= CCIE; // CCR0 enable interrupt
 TA1CCR1 = TA1CCR1_INTERVAL; // CCR1
 TA1CCTL1 |= CCIE; // CCR1 enable interrupt
// TA0CCR2 = TA0CCR2_INTERVAL; // CCR2
// TA0CCTL2 |= CCIE; // CCR2 enable interrupt
}
//------------------------------------------------------------------------------
//******************************************************************************

void Five_msec_Delay(int i){
    fivemscount=zero;
    while(fivemscount<=i){};     }




//******************************************************************************
//
//  Description: This function initialise B1 and B2 timer for PWM
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************





void Init_Timer_B1(void) {
 TB1CTL = TBSSEL__SMCLK; // SMCLK source
 TB1CTL |= TBCLR; // Resets TA0R, clock divider, count direction
 TB1CTL |= MC__UP; // Continuous up
 TB1CTL |= ID__8; // Divide clock by 8
 TB1CTL &= ~TBIE; // Disable Overflow Interrupt

 TB1EX0 = TBIDEX_7; // Divide clock by an additional 8

 TB1CCR0 = max_speed; // CCR0
 TB1CCR1 = max_speed; // CCR1 for R forward
 TB1CCTL1 |= OUTMOD_7; //OUTMOD_7 PWM output mode: 7 - PWM reset/set
 TB1CCR2 = low_speed;  //CCR2 for R reverse 
 TB1CCTL2 |= OUTMOD_7; //OUTMOD_7 PWM output mode: 7 - PWM reset/set
}
//------------------------------------------------------------------------------
//******************************************************************************
void Init_Timer_B2(void) {


 TB2CTL = TBSSEL__SMCLK; // SMCLK source
 TB2CTL |= TBCLR; // Resets TA0R, clock divider, count direction
 TB2CTL |= MC__UP; // Continuous up
 TB2CTL |= ID__8; // Divide clock by 8
 TB2CTL &= ~TBIE; // Disable Overflow Interrupt
 TB2EX0 = TBIDEX_7; // Divide clock by an additional 8
 TB2CCR0 = max_speed; // CCR0
 TB2CCR1 = max_speed; // CCR1 for L forward
 TB2CCTL1 |= OUTMOD_7; //OUTMOD_7 PWM output mode: 7 - PWM reset/set
 TB2CCR2 = low_speed;//ccr2 for L reverse 
 TB2CCTL2 |= OUTMOD_7; //OUTMOD_7 PWM output mode: 7 - PWM reset/set




}
 

