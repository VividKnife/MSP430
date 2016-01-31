//******************************************************************************
//
//  Description: This file contains the initialise Ports
//
//
//  Shufan Kang
//  Fall 2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

void Init_Ports(void); //This calls the rest of the initialization functions 



void Init_Ports(void){//This calls the rest of the initialization functions 
  Init_Port1();
  Init_Port2();
  Init_Port3();
  Init_Port4();
  Init_PortJ();
}


void Init_Port1(void){
  
//------------------------------------------------------------------------------
//Configure Port 1
// V_DETECT_R (0x01) //
// V_DETECT_L (0x02) //
// IR_LED (0x04) //
// V_THUMB (0x08) //
// SPI_CS_LCD (0x10) // LCD Chip Select
// SA0_LCD (0x20) // LCD SA0 H/L Slave Address
// SIMO_B (0x40) // SPI mode - slave in/master out of USCI_B0
// SOMI_B (0x80) // SPI mode - slave out/master in of USCI_B0
//------------------------------------------------------------------------------
 P1SEL0 = INIT; // P1 set as I/0
 P1SEL1 = INIT; // P1 set as I/0
 P1DIR = INIT; // Set P1 direction to input
 P1OUT = INIT;
 P1REN = INIT;  
   
 P1SEL0 |= V_DETECT_R; // V_DETECT_R selected
 P1SEL1 |= V_DETECT_R; // V_DETECT_R selected
 
 P1SEL0 |= V_DETECT_L; // V_DETECT_L selected
 P1SEL1 |= V_DETECT_L; // V_DETECT_L selected
 
 P1SEL0 &= ~IR_LED; // IR_LED GPI/O selected
 P1SEL1 &= ~IR_LED; // IR_LED GPI/O selected
 P1OUT  &= ~IR_LED; // P1 IR_LED Port Pin set low
 P1DIR |= IR_LED; // Set P1 IR_LED direction to output
 
 P1SEL0 |= V_THUMB; // V_THUMB selected
 P1SEL1 |= V_THUMB; // V_THUMB selected
 
 P1SEL0 &= ~SPI_CS_LCD; // SPI_CS_LCD GPI/O selected
 P1SEL1 &= ~SPI_CS_LCD; // SPI_CS_LCD GPI/O selected
 P1OUT |= SPI_CS_LCD; // P1 SPI_CS_LCD Port Pin set high
 P1DIR |= SPI_CS_LCD; // Set SPI_CS_LCD output direction
 
 P1SEL0 &= ~SA0_LCD; // SA0_LCD GPI/O selected
 P1SEL1 &= ~SA0_LCD; // SA0_LCD GPI/O selected
 P1OUT &= ~SA0_LCD; // P1 SA0_LCD Port Pin set low
 P1DIR |= SA0_LCD; // Set SA0_LCD output direction
 
 P1SEL0 &= ~SIMO_B; // SIMO_B selected
 P1SEL1 |= SIMO_B; // SIMO_B selected
 P1DIR |= SIMO_B; // SIMO_B set to Output
 
 P1SEL0 &= ~SOMI_B; // SOMI_B is used on the LCD
 P1SEL1 |= SOMI_B; // SOMI_B is used on the LCD
 P1DIR &= ~SOMI_B; // SOMI_B set to Input
 P1REN |= SOMI_B; // Enable pullup resistor
//------------------------------------------------------------------------------
}


void Init_Port2(void){//this function initialies port2

  P2SEL0 = InitReg;              
  P2SEL1 = InitReg;              
  P2DIR  = InitReg;               
  P2OUT  = InitReg;
  
  P2SEL0 &= ~USB_TXD;//  usb_txd is selected
  P2SEL1 |= USB_TXD;//  usb_txd is selected
  P2DIR  |= USB_TXD;// usb_txd set to output
  
  P2SEL0 &= ~USB_RXD;//   usb_rxd is selected
  P2SEL1 |= USB_RXD;//  usb_rxd is selected
  P2DIR  &= ~USB_TXD;// usb_rxd set to output
  
  P2SEL0 &= ~SPI_SCK;//  SPI_SCK is selected
  P2SEL1 |= SPI_SCK;//  SPI_SCK is selected
  P2OUT  |= SPI_SCK;//  set to high
  P2DIR  |= SPI_SCK;// usb_txd set to output
  
  P2SEL0 &= ~P2_3;//  P2_3 is selected
  P2SEL1 &= ~P2_3;//  P2_3 is selected
  P2DIR  &= ~P2_3;// P2_3 set to input
  P2REN  &= ~P2_3;// P2_3 pull-up set to low
  
  P2SEL0 &= ~P2_4;//  P2_4 is selected
  P2SEL1 &= ~P2_4;//  P2_4 is selected
  P2DIR  &= ~P2_4;// P2_4 set to input
  P2REN  &= ~P2_4;// P2_4 pull-up set to low
  
  
  
  P2SEL0 &= ~CPU_TXD;//  CPU_TXD is selected
  P2SEL1 |= CPU_TXD;//  CPU_TXD is selected
  P2DIR  |= CPU_TXD; // CPU_TXD set to output
  
  

  
  P2SEL0 &= ~CPU_RXD;//  CPU_RXD is selected
  P2SEL1 |= CPU_RXD;//  CPU_RXD is selected
  P2DIR  &= ~CPU_RXD;// CPU_RXD set to input
  
  P2SEL0 &= ~P2_7;//  P2_7 is selected
  P2SEL1 &= ~P2_7;//  P2_7 is selected
  P2DIR  &= ~P2_7;// P2_7 set to input
  P2REN  &= ~P2_7;// P2_7 pull-up set to low
}

void Init_Port3(void){//this function initialies port3
//----------------------------------------------------------------------------
//Configure Port 3
// X                   (0x01)//
// Y                   (0x02)//
// Z                   (0x04)//
// LCD_BACKLITE        (0x08) // 
// R_FORWARD           (0x10) // 
// R_REVERSE           (0x20) //
// L_FORWARD           (0x40) // 
// L_REVERSE           (0x80) //
//-----------------------------------------------------------------------------
  
  P3SEL0 = InitReg;              
  P3SEL1 = InitReg;              
  P3DIR  = InitReg;               
  P3OUT  = InitReg;
  
  
  P3SEL0 &= ~X;//  X is selected
  P3SEL1 &= ~X;//  X is selected
  P3DIR  &= ~X;//  X set to input
  P3REN  &= ~X;//  X pull-up set to low  
  
  P3SEL0 &= ~Y;//  X is selected
  P3SEL1 &= ~Y;//  X is selected
  P3DIR  &= ~Y;//  X set to input
  P3REN  &= ~Y;//  X pull-up set to low 
  
  P3SEL0 &= ~P_Z;//  X is selected
  P3SEL1 &= ~P_Z;//  X is selected
  P3DIR  &= ~P_Z;//  X set to input
  P3REN  &= ~P_Z;//  X pull-up set to low 
  
  P3SEL0 &= ~LCD_BACKLITE;//  LCD_BACKLITE is selected
  P3SEL1 &= ~LCD_BACKLITE;//  LCD_BACKLITE  is selected
  P3DIR  |= LCD_BACKLITE;//  LCD_BACKLITE set to output
  
  P3SEL0 &= ~R_FORWARD;//  R_FORWARD is selected
  P3SEL1 &= ~R_FORWARD;//  R_FORWARD  is selected
  P3DIR  |= R_FORWARD;//  R_FORWARD set to output
  
  P3SEL0 &= ~R_REVERSE;//  R_REVERSE is selected
  P3SEL1 &= ~R_REVERSE;//  R_REVERSE  is selected
  P3DIR  |= R_REVERSE;//  R_REVERSE set to output
  
  P3SEL0 &= ~L_FORWARD;//  L_FORWARD is selected
  P3SEL1 &= ~L_FORWARD;//  L_FORWARD  is selected
  P3DIR  |= L_FORWARD;//  L_FORWARD set to output
  
  P3SEL0 &= ~L_REVERSE;//  L_REVERSE is selected
  P3SEL1 &= ~L_REVERSE;//  L_REVERSE  is selected
  P3DIR  |= L_REVERSE;//  L_REVERSE set to output
  
}

void Init_Port4(void){
 P4SEL0 = ORIGINAL; // P4 set as I/0
 P4SEL1 = ORIGINAL; // P4 set as I/0
 P4DIR = ORIGINAL; // Set P4 direction to input
 P4DIR &= ~(SW1 | SW2); // Direction = input
 P4OUT = ORIGINAL;
 P4OUT |= SW1; // Configure pullup resistor
 P4OUT |= SW2; // Configure pullup resistor
 P4REN |= SW1; // Enable pullup resistor
 P4REN |= SW2; // Enable pullup resistor
// Configure the interrupt
 P4IES |= SW1; // P4.0 Hi/Lo edge interrupt
 P4IES |= SW2; // P4.0 Hi/Lo edge interrupt
 P4IFG &= ~SW1; // P4 IFG SW1 cleared
 P4IFG &= ~SW2; // P4 IFG SW2 cleared
// Start / Enable Interrupt
 P4IE |= SW1; // P4.0 SW1 interrupt Enabled
 P4IE |= SW2; // P4.0 SW2 interrupt enabled
}

void Init_PortJ(void){//this function initialies portJ
//------------------------------------------------------------------------------
// Port J Pins
// LED1                 (0x01) // LED 5
// LED2                 (0x02) // LED 6
// LED3                 (0x04) // LED 7
// LED4                 (0x08) // LED 8
// XINR                 (0x10) // XINR
// XOUTR                (0x20) // XOUTR
//------------------------------------------------------------------------------
  PJSEL0 = InitReg;              
  PJSEL1 = InitReg;              
  PJDIR  = InitReg;               

  PJSEL0 &= ~RESET;
  PJSEL1 &= ~RESET;
  PJOUT &= ~RESET;
  PJDIR |= RESET;               // Set PJ Pin 3 direction to output

  PJSEL0 &= ~IOT_FACTORY;
  PJSEL1 &= ~IOT_FACTORY;
  PJOUT &= ~IOT_FACTORY;
  PJDIR |= IOT_FACTORY;               // Set PJ Pin 3 direction to output
 
  PJSEL0 &= ~IOT_WAKEUP;
  PJSEL1 &= ~IOT_WAKEUP;
  PJOUT |= IOT_WAKEUP;
  PJDIR |= IOT_WAKEUP;               // Set PJ Pin 3 direction to output
  
  PJSEL0 &= ~IOT_STA_MINIAP;
  PJSEL1 &= ~IOT_STA_MINIAP;
  PJOUT |= IOT_STA_MINIAP;
  PJDIR |= IOT_STA_MINIAP;               // Set PJ Pin 3 direction to output
  
  PJOUT &= ~RESET;  

// XT1 Setup   
  PJSEL0 |= XINR;
  PJSEL0 |= XOUTR;

//------------------------------------------------------------------------------
} 