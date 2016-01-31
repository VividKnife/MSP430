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


// global variables
volatile unsigned int usb_rx_ring_wr;
volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
volatile unsigned int usb_rx_ring_rd;
volatile char USB_Char_Tx[SMALL_RING_SIZE];
volatile unsigned int usb_tx_ring_wr;
volatile unsigned int usb_tx_ring_rd;

// serical variables for cpu
volatile unsigned int cpu_rx_ring_wr;
volatile char CPU_Char_Rx[LARGE_RING_SIZE] ;
volatile unsigned int cpu_rx_ring_rd;
volatile char CPU_Char_Tx[SMALL_RING_SIZE];
volatile unsigned int cpu_tx_ring_wr;
volatile unsigned int cpu_tx_ring_rd;
//IOT variables
volatile unsigned int IOT_enable=disable;
volatile int check_ip=zero;
volatile int writing_ip = disable;
volatile char ip_char[ip_length];
volatile int ip_index;
volatile int asking_ip=disable;
volatile int command_mode = disable;
volatile int command_index = zero;
volatile char command[COMMAND_SIZE];
volatile int writing_command = disable;
volatile int command_done = disable;
volatile int webpage_mode = disable;
volatile int web_speed = 9;
//----------------------------------------------------------------------------

void Init_Serial_UCA0(void){
 int i;
 for(i=zero; i<SMALL_RING_SIZE; i++){
 USB_Char_Rx[i] = CLEAR;// USB Character
 }
 usb_rx_ring_wr = zero;
 usb_rx_ring_rd = zero;

 for(i=zero; i<LARGE_RING_SIZE; i++){
 USB_Char_Tx[i] = CLEAR;// USB Character
 }
 usb_tx_ring_wr = zero;
 usb_tx_ring_rd = zero;
 // Configure UART 0
 UCA0CTLW0 = zero; // Use word register
 UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
 UCA0CTLW0 |= UCSWRST; // Set Software reset enable
// 9,600 Baud Rate
// 1. Calculate N = fBRCLK/Baudrate [if N > 16 continue with step 3, otherwise with step 2]
// N = SMCLK / 9,600 => 8,000,000 / 9,600 = 833.3333333
//
// 2. OS16 = 0, UCBRx = INT(N) [continue with step 4]
// 3. OS16 = 1, UCx = INT(N/16), UCFx = INT([(N/16) 每 INT(N/16)] ℅ 16)
// UCx = INT(N/16) = 833.333/16 => 52
// UCFx = INT([(N/16) 每 INT(N/16)] ℅ 16) = ([833.333/16-INT(833.333/16)]*16) =>
// (52.08333333-52)*16=>0.083*16=1
// 4. UCSx can be found by looking up the fractional part of N ( = N - INT(N) ) in Table 18-4
// Decicmal of SMCLK / 8,000,000 / 9,600 = 833.3333333 => 0.333 yields 0x25
// 5. If OS16 = 0 was chosen, a detailed error calculation is recommended to be performed
// TX error (%) RX error (%)
// BRCLK Baudrate UCOS16 UCBRx UCFx UCSx neg pos neg pos
// 8000000 9600 1 52 1 0x49 -0.08 0.04 -0.10 0.14
 UCA0BRW = baud_9600_BRW ; // 9,600 baud
// UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
// UCA0MCTLW = 0x49 concatenate 1 concatenate 1;
 UCA0MCTLW = baud_9600_MCTLW ;
 //115,200 Baud Rate
 //N=SMCLK/115,200 =69.4444444
 //since N>16, OS16=1
 //UCx=int(N/16)=4 
 //UCFx = int([(N/16)-int(N/16)] * 16)= 0.340 *16=5
 //UCSX 0.444-> 0x55
 //UCA0BRW = 4;
 //UCA0MCTLW=0x5551
 
 
 UCA0CTL1 &= ~UCSWRST; // Release from reset
 UCA0IE |= UCRXIE; // Enable RX interrupt
}

//------------------------------------------------------------------------------
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
 unsigned int Rxtemp;
 char data_in;
 if(back_light_state){
  P3OUT |= LCD_BACKLITE;}
 PJOUT |= IOT_WAKEUP;
 LPM4_EXIT; // wake up from low power mode
 sleeping__=zero; 
 
 switch(__even_in_range(UCA0IV,RESET)){ //RESET = 0x08
 case zero: // Vector 0 - no interrupt
 break;
 case Vector_2: // Vector 2 - RXIFG
 IOT_enable = enable;
 Rxtemp = usb_rx_ring_wr++;
 data_in = UCA0RXBUF;
 while (!(UCA0IFG & UCTXIFG)); 
 UCA0TXBUF = data_in;
 if(data_in){
 USB_Char_Rx[Rxtemp] = data_in; // RX -> USB_Char_Rx character
 while (!(UCA1IFG & UCTXIFG)); 
 UCA1TXBUF = data_in;
 if (usb_rx_ring_wr >= (SMALL_RING_SIZE)){
 usb_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
 }
 }
 break;
 case Vector_4: // Vector 4 每 TXIFG
   
   
 break;
 default: break;
 }
}




void Init_rx_tx(void){
 int i;
 for(i=zero; i<SMALL_RING_SIZE; i++){
 CPU_Char_Rx[i] = CLEAR;// CPU Character
 }
 cpu_rx_ring_wr = zero;
 cpu_rx_ring_rd = zero;

 for(i=zero; i<SMALL_RING_SIZE; i++){
 USB_Char_Rx[i] = CLEAR;// USB Character
 }
 usb_rx_ring_wr = zero;
 usb_rx_ring_rd = zero;


}



void Init_Serial_UCA1(void){
      check_ip = disable;
      ip_index = zero;
 int i;
 for(i=zero; i<LARGE_RING_SIZE; i++){
 CPU_Char_Rx[i] = CLEAR;// USB Character
 }
 cpu_rx_ring_wr = zero;
 cpu_rx_ring_rd = zero;

 for(i=zero; i<LARGE_RING_SIZE; i++){
 USB_Char_Tx[i] = CLEAR;// USB Character
 }
 cpu_tx_ring_wr = zero;
 cpu_tx_ring_rd = zero;
 // Configure UART 0
 UCA1CTLW0 = zero; // Use word register
 UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
 UCA1CTLW0 |= UCSWRST; // Set Software reset enable
// 9,600 Baud Rate
// 1. Calculate N = fBRCLK/Baudrate [if N > 16 continue with step 3, otherwise with step 2]
// N = SMCLK / 9,600 => 8,000,000 / 9,600 = 833.3333333
//
// 2. OS16 = 0, UCBRx = INT(N) [continue with step 4]
// 3. OS16 = 1, UCx = INT(N/16), UCFx = INT([(N/16) 每 INT(N/16)] ℅ 16)
// UCx = INT(N/16) = 833.333/16 => 52
// UCFx = INT([(N/16) 每 INT(N/16)] ℅ 16) = ([833.333/16-INT(833.333/16)]*16) =>
// (52.08333333-52)*16=>0.083*16=1
// 4. UCSx can be found by looking up the fractional part of N ( = N - INT(N) ) in Table 18-4
// Decicmal of SMCLK / 8,000,000 / 9,600 = 833.3333333 => 0.333 yields 0x25
// 5. If OS16 = 0 was chosen, a detailed error calculation is recommended to be performed
// TX error (%) RX error (%)
// BRCLK Baudrate UCOS16 UCBRx UCFx UCSx neg pos neg pos
// 8000000 9600 1 52 1 0x49 -0.08 0.04 -0.10 0.14
 UCA1BRW = baud_9600_BRW ; // 9,600 baud
// UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
// UCA0MCTLW = 0x49 concatenate 1 concatenate 1;
 UCA1MCTLW = baud_9600_MCTLW ;
 //115,200 Baud Rate
 //N=SMCLK/115,200 =69.4444444
 //since N>16, OS16=1
 //UCx=int(N/16)=4 
 //UCFx = int([(N/16)-int(N/16)] * 16)= 0.340 *16=5
 //UCSX 0.444-> 0x55
 //UCA0BRW = 4;
 //UCA0MCTLW=0x5551
 
 
 UCA1CTL1 &= ~UCSWRST; // Release from reset
 UCA1IE |= UCRXIE; // Enable RX interrupt
}

volatile int is_a;
volatile int is_ad;
volatile int is_add;
volatile int is_addr;
volatile int is_addre;

//------------------------------------------------------------------------------
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void){
 unsigned int Rxtemp;
 char data_in=0x00;
 //if(back_light_state){
  //P3OUT |= LCD_BACKLITE;}
 PJOUT |= IOT_WAKEUP;
 LPM4_EXIT; // wake up from low power mode
 sleeping__=zero;
 
 
 
 switch(__even_in_range(UCA1IV,RESET)){ //RESET = 0x08
 case zero: // Vector 0 - no interrupt
 break;
 case Vector_2: // Vector 2 - RXIFG
       Rxtemp = cpu_rx_ring_wr;
       data_in= UCA1RXBUF; 
       CPU_Char_Rx[Rxtemp] = data_in; //save the receive value to *CPU_Char_Rx
       UCA0TXBUF = CPU_Char_Rx[Rxtemp];
       if(webpage_mode){
          if(data_in=='H'){
            stop_car();
          }else if(data_in=='F'){
            forward_stright(web_speed);
          }else if(data_in=='B'){
            reverse_stright(web_speed);
          }else if(data_in=='R'){
            turn_right(1);
          }else if(data_in=='L'){
            turn_left(1);
          }else if(data_in=='1'){
            web_speed = 3;
          }else if(data_in=='2'){
            web_speed = 6;
          }else if(data_in=='3'){
            web_speed = 9;
          }
       }
       
       
       //*********************************//
       //getting ip address ISR start here//
       //*********************************//
       if(asking_ip){                // check if is asking ip  
         if(data_in == '#'){         // set up the CPU_Char_Rx to save every information after '#'
                cpu_rx_ring_wr = zero;
            }
            if(data_in == ' '){      // once get a ' ' check the arry to see if contain "ipaddr" 
                if(CPU_Char_Rx[Rxtemp-__3]=='r' && CPU_Char_Rx[Rxtemp-__4]=='d' &&CPU_Char_Rx[Rxtemp-__5]== 'd' && CPU_Char_Rx[Rxtemp-__6]=='a' && CPU_Char_Rx[Rxtemp-__7]=='p' && CPU_Char_Rx[Rxtemp-__8]=='i'){
                check_ip = enable;  //get ready to receive ip address
                ip_index = zero;  
                }
            } 
            if(check_ip){// write the ip address to *ip_char
                ip_char[ip_index++]=data_in;
            }
            if(ip_index>ip_length){// once finish record, init this "function"
                check_ip = disable;
                ip_index = zero;
                asking_ip = disable;
            }
      }
      //**************************//
      //***getting ip ends here***//
      //**************************//
      

      //**************************//
      //receive command start here//
      //**************************//
      if(command_mode){
        if(data_in == '*' && !(writing_command)){
           writing_command = enable;
        }
        if(writing_command){
          command[command_index] = data_in;
          fivemsblink = zero;
        }
        if(++command_index>=(COMMAND_SIZE)){
          command_mode = disable;
          command_index = zero;
        }
      }
      //************************//
      //receive command end here//
      //************************//
      if(++cpu_rx_ring_wr >= (LARGE_RING_SIZE)){
          cpu_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
      }
 
 break;
 case Vector_4: // Vector 4 每 TXIFG
   
   
 break;
 default: break;
 }
}








void transmit_cpu(void){
 unsigned int Txtemp;
 while (cpu_tx_ring_wr <= (SMALL_RING_SIZE)){

 fivemsblink=zero;
 while(fivemsblink<=QUATERSEC);
 
 Txtemp=cpu_tx_ring_wr;
 UCA1TXBUF = CPU_Char_Tx[Txtemp];//USB_Char_Tx character -> Tx  
 
 cpu_tx_ring_wr++;
 }
 cpu_tx_ring_wr=BEGINNING; // Circular buffer back to beginning
 //UC0IE &= ~UCA0TXIE; //do I need this? 
}


void transmit_usb(void){
 unsigned int Txtemp;
 while (usb_tx_ring_wr <= (SMALL_RING_SIZE)){

 fivemsblink=zero;
 while(fivemsblink<=QUATERSEC);
 
 Txtemp=usb_tx_ring_wr;
 UCA0TXBUF = USB_Char_Tx[Txtemp];//USB_Char_Tx character -> Tx  
 
 usb_tx_ring_wr++;
 }
 usb_tx_ring_wr=BEGINNING; // Circular buffer back to beginning
 //UC0IE &= ~UCA0TXIE; //do I need this? 
}


