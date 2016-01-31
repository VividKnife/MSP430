////------------------------------------------------------------------------------
////  Description: This file contains serial_communication apps
////
////  Shufan Kang
////  Fall 2015
////  Built with IAR Embedded Workbench Version: V6.30.2
////------------------------------------------------------------------------------
//
////------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include "macros.h"





void send_to_PC(void){
    int i=0;
    int k=0;
    char receive[SMALL_RING_SIZE];
    display_1 = "";
    display_2 = "";
    display_4 = "   9600";
    Display_Process();
    fivemsblink = zero;
    while(fivemsblink<twosec);
    fivemsblink = zero;
    USB_Char_Tx[0] = 'N';
    USB_Char_Tx[1] = 'C';
    USB_Char_Tx[2] = 'S';
    USB_Char_Tx[3] = 'U';
    USB_Char_Tx[4] = ' ';
    USB_Char_Tx[5] = ' ';
    USB_Char_Tx[6] = '#';
    USB_Char_Tx[7] = '1';
      k++;
       transmit_usb();
    while(i< SMALL_RING_SIZE){
    receive[i]=USB_Char_Rx[i];
      i++;
    }
     i=zero;
    display_1 = receive;
    display_2 = "NCSU  #1";
    Display_Process();



}







void recesive_PC(void){
    char receive[SMALL_RING_SIZE];
    int receiving = enable;
    int k=zero;
    int temp_rd;
    
    for(k=zero;k<SMALL_RING_SIZE;k++){
    receive[k]=CLEAR;
    USB_Char_Rx[k]=CLEAR;    
    } 
    USB_Char_Tx[0] = 'R';//ready 
    USB_Char_Tx[1] = 'E';
    USB_Char_Tx[2] = 'A';
    USB_Char_Tx[3] = 'D';
    USB_Char_Tx[4] = 'Y';
    USB_Char_Tx[5] = ' ';
    USB_Char_Tx[6] = ':';
    USB_Char_Tx[7] = ' ';
    transmit_usb();
    display_1 = "Received";
    display_2 = receive;
    display_3 = "SW1 Rest";
    display_4 = "SW2 Back";
    Display_Process();
    while(receiving){
      temp_rd = usb_rx_ring_rd;
      if(sw1_bolling){
        sw1_bolling = disable;
        transmit_usb();
        
        for(k=zero;k<SMALL_RING_SIZE;k++){
          receive[k]=CLEAR;
          USB_Char_Rx[k]=CLEAR;
          usb_rx_ring_wr=zero;
          usb_rx_ring_rd=zero;

        }
        Display_Process();
      
      }
      if(usb_rx_ring_wr != temp_rd){
        receive[temp_rd]=USB_Char_Rx[temp_rd];   
      Display_Process();
        usb_rx_ring_rd++;
    }
    if(usb_rx_ring_rd>=SMALL_RING_SIZE){ // if input overflow, reset both USB_Char_Rx[] and reveive[];
      usb_rx_ring_rd=zero;
      for(k=zero;k<SMALL_RING_SIZE;k++){
        receive[k]=CLEAR;
        USB_Char_Rx[k]=CLEAR;
    
      }
     }
       if(sw2_bolling){
       sw2_bolling = disable;
       receiving = disable;
       }
    
    }

}


