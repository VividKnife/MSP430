//******************************************************************************
//
//  Description: This file contains the wifi_settings and mode
//
//
//  Shufan Kang
//  Fall 2015 9/30/2015
//  Built with IAR Embedded Workbench Version: V6.30.2
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"
#include  <string.h>


void wifi_home_mode(void){
//        display_1 = "Configing";
//        display_2 = "Home_Mode";
//        display_3 = "Please w8";
//        display_4 = "";
//        Display_Process();
//        //send_IOT("AT+S.SCFG=console1_speed,9600\r");
//	send_IOT("AT+S.SSIDTXT=Kang\r");
//        send_IOT("AT+S.SCFG=wifi_wpa_psk_text,kangshufan\r");
//        send_IOT("AT+S.SCFG=ip_hostname,IOT_athome_skang\r");
//        send_IOT("AT+S.SCFG=wifi_priv_mode,2\r");
//        send_IOT("AT+S.SCFG=wifi_mode,1\r");
//        send_IOT("AT&W\r");
//        send_IOT("AT+CFUN=1\r");
//        waite1sec();
//        PJOUT &=~ RESET;
//        waite1sec();
//        PJOUT |= RESET;
//        Init_LCD();
//        display_1 = "Configing";
//        display_2 = "Home_Mode";
//        display_3 = "DONE";
//        display_4 = "SW2 EXIT";
//        Display_Process();
          display_1 = "Configing";
        display_2 = "MiniAP";
        display_3 = "Please w8";
        display_4 = "";
        Display_Process();  
	send_IOT("AT+S.SSIDTXT=SPWF_AP\r");
        send_IOT("AT+S.SCFG=wifi_priv_mode,0\r");
        send_IOT("AT+S.SCFG=wifi_mode,3\r");
        send_IOT("AT&W\r");
        send_IOT("AT+CFUN=1\r");
        waite1sec();
        PJOUT &=~RESET;
        waite1sec();
        PJOUT |= RESET;
        Init_LCD();
        waite1sec();
        waite1sec();
        display_1 = "Configing";
        display_2 = "MiniAP";
        display_3 = "DONE";
        display_4 = "SW2 EXIT";
        Display_Process();
}

void wifi_ncsu_mode(void){
        display_1 = "Configing";
        display_2 = "NCSU_Mode";
        display_3 = "Please w8";
        display_4 = "";
        Display_Process();  
	send_IOT("AT+S.SSIDTXT=ncsu\r");
        send_IOT("AT+S.SCFG=ip_hostname,ECE-306_12_A\r");
        send_IOT("AT+S.SCFG=wifi_priv_mode,0\r");
        send_IOT("AT+S.SCFG=wifi_mode,1\r");
        send_IOT("AT&W\r");
        send_IOT("AT+CFUN=1\r");
        waite1sec();
        PJOUT &=~RESET;
        waite1sec();
        PJOUT |= RESET;
        Init_LCD();
        display_1 = "Configing";
        display_2 = "NCSU_Mode";
        display_3 = "DONE";
        display_4 = "SW2 EXIT";
        Display_Process();
}

void check_IP(void){
        int index = zero;
        char ip_temp1[__9];
        char ip_temp2[__9];
        strcpy(ip_temp1,"         ");
        strcpy(ip_temp2,"         ");
        check_ip = disable;
        ip_index = zero;
        asking_ip = enable;
        ip_index = zero;
        send_IOT("AT+S.STS\r");
        display_1 = "GETTING IP";
        display_2="...";
        display_3=".....";
        display_4="........";
        Display_Process();
        fivemsblink=zero;
        while(fivemsblink<onesec);
        for(index=zero;index<__8;index++){
        ip_temp1[index] = ip_char[index+__1];
        }
        for(index=zero;index<__5;index++){
        ip_temp2[index] = ip_char[index+__9];
        }
        display_1 = "  GET IP";
        display_2 = "  ipaddr";
        display_3 = ip_temp1;
        display_4 = ip_temp2;
        posL3 = __1;
        posL4 = __2;
        Display_Process();
        posL3 = zero;
        posL4 = zero;
        while(!sw1_bolling);
        sw1_bolling = disable;
}

void send_IOT(char request[]){
	int index = zero;
	int length = zero;
	while (request[length]!=enter__){
		length++;
	}
	while (index<=length){
		fivemsblink=zero;
                while(fivemsblink<QUATERSEC);
 		UCA1TXBUF = request[index];
 		index++;
	}
        waite1sec();
        //while(UCA1RXBUF != 'O');
}

void send_ping(void){
    display_1 = " SENDING";
    display_2 = " PING TO";
    display_3 = "  LAB PC";
    send_IOT("AT+S.PING=10.139.71.181\r");
    fivemsblink = zero;
    while(fivemsblink<twosec){      
        display_4 = "    .";
        Display_Process();
        waiteQsec();
        display_4 = "   ...";
        Display_Process();
        waiteQsec();
        display_4 = "  .....";
        Display_Process();
        waiteQsec();        
    }
    display_4 = "   DONE";
    Display_Process();
    while(!sw2_bolling);
    sw2_bolling = disable;
}


void receive_wifi(void){
  int index=zero;
  int i = zero;
  char temp_com[__10];
  int w8ing=enable;
  int temp;
  int searching = enable;
  int ex_command = disable;
  char *com;
  com = &temp_com[zero];
  while(searching){
    display_3 = " Waitting";
    display_1 = " COMMAND";
    display_2 = "  ENTER";
    command_mode = enable;
    temp = zero;
    cpu_rx_ring_wr =zero;
    fivemsblink = zero;
    for(i=zero;i<COMMAND_SIZE;i++){
      command[i] = CLEAR;
    }
    command_index = zero;
    index = zero;
    while((fivemsblink<onesec || w8ing) && !(sw2_bolling)){
        if(temp==cpu_rx_ring_wr){
            fivemsblink = zero;
        }
        else{
            w8ing = disable;
        }
        display_4 = "    .";
        Display_Process();
        waiteQsec();
        display_4 = "   ...";
        Display_Process();
        waiteQsec();
        display_4 = "  .....";
        Display_Process();
        waiteQsec(); 
    }// end of waiting for input command
    
    //sw2_bolling = disable;
    display_4 ="   DONE";
    Display_Process();
    if(command[zero]=='*'){ex_command = enable;}
    while(ex_command){
      for(i=zero;i<__10;i++){
        temp_com[i]=command[index+i];
      }
      index += __10;
      //call a function to excute the command
      excute_command(com);
      while(command[index++]!='*' && index<=(COMMAND_SIZE-__10));
      if((index--)>=(COMMAND_SIZE)){
        ex_command = disable;
      }      
    }
    lcd_4line();
    display_1 = " Command";
    display_3 = " SW1 Retry";
    display_4 = " SW2 Back";
    Display_Process();
   // while(!(sw1_bolling || sw2_bolling));// single step or use // for  multi step
    if(sw1_bolling){
       sw1_bolling = disable;
    }
    else if(sw2_bolling){
       searching = disable;
       sw2_bolling = disable;
    }

  }// end of searching
}




void excute_command(char *com){
    int time;
    int speed;
    display_2 = com;
    lcd_BIG_mid();
    Display_Process();
    speed = (com[__6]-'0');
    time = ((com[__7]-'0')*__100)+(com[__8]-'0')*__10+(com[__9]-'0');
    if(com[__1]=='k' && com[__2]=='a' && com[__3]=='n' && com[__4]=='g'){
      switch (com[__5]){
         case 'F':
            forward_stright(speed);
            fivemsblink = zero;
            while(fivemsblink<time);
            stop_car();
            break;
         case 'B':
            reverse_stright(speed);
            fivemsblink = zero;
            while(fivemsblink<time);
            stop_car();
            break;
         case 'R':
            turn_right(time);
            break;
         case 'L':
            turn_left(time);
            break;
        // case '?' inplement for dirction here    
         default:
            display_1 = "XXXXXXXXXX";
            display_3 = " VOID DIR";
            Display_Process();
     }// end of switch 
    }else{
      display_1 = "XXXXXXXXXX";
      display_2 = "  ERROR";
      display_3 = " PASSWORD";
      Display_Process();    
    }
    waite1sec();
    waite1sec();
    waite1sec();
} 


void webpage_drive(void){
      display_1 = "   GOTO";
      display_2 = "wifi.html";
      display_3 = "  DRIVE";
      display_4 = " The CAR";
      Display_Process(); 
      int doing=enable;
      webpage_mode=enable;
      while(doing){
            webpage_mode=enable;
            P3OUT &=~ LCD_BACKLITE;
            //LPM4;
            __bis_SR_register(LPM4_bits + GIE);
            //PJOUT &=~ IOT_WAKEUP;
            if(sw1_bolling){
              sw1_bolling = disable;
              webpage_mode=disable;
              doing = disable;
            }           
      }


}

/*******************************************************************************
void ip_detect(void){
    int temp_rd;
    int index = zero;
    int length = zero;
    char *request;
    char *ip_address;
    char temp_data;
    int count_addr=zero;
    int checking_for_ip = enable;
    int finding = enable;
    int i;
    request = "AT+S.STS\r";
    while (request[length]!=enter__){
	length++;
    }
    while (index<=length){
        fivemsblink=zero;
        while(fivemsblink<QUATERSEC);
        UCA1TXBUF = request[index];
        index++;
	}
    cpu_rx_ring_wr=zero;
    cpu_rx_ring_rd=zero;
    while(checking_for_ip){
    temp_rd = cpu_rx_ring_rd;
    if(temp_rd != cpu_rx_ring_wr){
         temp_data = CPU_Char_Rx[cpu_rx_ring_wr];
         cpu_rx_ring_rd++;
          if(cpu_rx_ring_rd>=SMALL_RING_SIZE){ // if input overflow, reset both USB_Char_Rx[] and reveive[];
              cpu_rx_ring_rd=zero;
          }
       if(finding){
         i=0;
         switch (temp_data){
         case 'a':
           count_addr++; break;
         case 'd':
           count_addr++; break;
         case 'r':
           count_addr++; break;
         case ' ':
           count_addr++;  break;
         case '=':
           count_addr++; break;
         case 'i':
           count_addr++; break;
         case 'p':
           count_addr++; break;
         default:
           if(count_addr<__8){
           count_addr = zero;
           } break;             
         }
       }// end of finding
        if(count_addr>=8){
         finding = disable;
         ip_address[i]= temp_data; 
         i++;
         if(i>=11){
         checking_for_ip = disable;
         }
         }
       
    }// end of temp_data
    
    }//end if while chack
    
    display_3 = ip_address;
    Display_Process();
    while(!sw1_bolling);
    sw1_bolling = disable;


}
****************************************************************************/

