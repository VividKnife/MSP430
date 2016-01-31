//******************************************************************************
//
//  Description: This file contains adc Interrups and functions
//
//
//  shufan kang
//  Sep 2015
//  Built with IAR Embedded Workbench Version: 6.30.2
//******************************************************************************

//------------------------------------------------------------------------------
#include "msp430.h"
#include "functions.h"
#include "macros.h"
char adc_char[four];
char adc_char_thumb[four];
char adc_char_left[four];
char adc_char_right[four];
volatile unsigned int ADC_Thumb;
volatile int temp;

//******************************************************************************
//
//  Description: This function contains adc and functions
//
//
//  shufan kang
//  Sep 2015
//  Built with IAR Embedded Workbench Version: 6.30.2
//******************************************************************************



void Init_ADC(void){
ADC10CTL0 = RESET_STATE; // Clear ADC10CTL0
ADC10CTL0 |= ADC10SHT_2; // 16 ADC clocks
ADC10CTL0 &= ~ADC10MSC; // Single Sequence
ADC10CTL0 |= ADC10ON; // ADC ON - Core Enabled
ADC10CTL1 = RESET_STATE; // Clear ADC10CTL1
ADC10CTL1 |= ADC10SHS_0; // ADC10SC bit
ADC10CTL1 |= ADC10SHP; // SAMPCON signal sourced from sampling timer
ADC10CTL1 &= ~ADC10ISSH; // The sample-input signal is not inverted.
ADC10CTL1 |= ADC10DIV_0; // ADC10_B clock divider ?Divide by 1.
ADC10CTL1 |= ADC10SSEL_0; // MODCLK
ADC10CTL1 |= ADC10CONSEQ_0; // Single-channel, single-conversion
ADC10CTL2 = RESET_STATE; // Clear ADC10CTL2
ADC10CTL2 |= ADC10DIV_0; // Pre-divide by 1
ADC10CTL2 |= ADC10RES; // 10-bit resolution
ADC10CTL2 &= ~ADC10DF; // Binary unsigned
ADC10CTL2 &= ~ADC10SR; // supports up to approximately 200 ksps
ADC10MCTL0 = RESET_STATE; // Clear ADC10MCTL0
ADC10MCTL0 |= ADC10SREF_0; // V(R+) = AVCC and V(R-) = AVSS
ADC10MCTL0 |= ADC10INCH_3; // Channel A3 Thumb Wheel
ADC10IE |= ADC10IE0; // Enable ADC conversion complete interrupt
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ADC10 interrupt service routine
// ADC_Right_Detector; // A00 ADC10INCH_0 - P1.0
// ADC_Left_Detector; // A01 ADC10INCH_1 - P1.1
// ADC_Thumb; // A03 ADC10INCH_3 - P1.3
// ADC_Temp; // A10 ADC10INCH_10 ?Temperature REF module
// ADC_Bat; // A11 ADC10INCH_11 - Internal
volatile  unsigned int channalCount;
volatile  unsigned int chan;
volatile  unsigned int ADC_Right_Detector;
volatile  unsigned int ADC_Left_Detector;
volatile  unsigned int lineDecOld;
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
 if(back_light_state){
 P3OUT |= LCD_BACKLITE;}
 PJOUT |= IOT_WAKEUP;
 LPM4_EXIT; // wake up from low power mode
 sleeping__=zero;
 
 switch(__even_in_range(ADC10IV,12)) {
 case CLEAR: break; // No interrupt
 case RESULTOVER: break; // conversion result overflow
 case TIMEOVER: break; // conversion time overflow
 case HIADC: break; // ADC10HI
 case LOADC: break; // ADC10LO
 case INADC: break; // ADC10IN
 case THIS:
 // Need this to change the ADC10INCH_x value.
 ADC10CTL0 &= ~ADC10ENC; // Toggle ENC bit.
 switch (chan++){
 case 0:
 ADC10MCTL0 = ADC10INCH_1; // Next channel A1
 ADC_Right_Detector = ADC10MEM0; // Read Channel A0 
 break;
 case 1:
 ADC10MCTL0 = ADC10INCH_3; // Next channel A3
 ADC_Left_Detector = ADC10MEM0; // Read Channel A1 
 break;
 case 2:
 ADC10MCTL0 = ADC10INCH_0; // Next channel A11
 ADC_Thumb = ADC10MEM0; // Read Channel A3 
 chan = CLEAR;
 break; 
 default: break; 
 } 
}
}



//--------------------------------------------------------
void ADC_Process(void){
 while (ADC10CTL1 & BUSY); // Wait if ADC10 core is active
 ADC10CTL0 |= ADC10ENC + ADC10SC; // Sampling and conversion start
}
//---------------------------------------------------------



