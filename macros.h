// Required defines
// In the event the universe no longer exists, this bit will reset
#define ALWAYS                  (1)
#define InitReg              (0x00) // initialies register    
#define CNTL_STATE_INDEX        (3) // Control States
#define LED1                 (0x01) // LED 1
#define LED2                 (0x02) // LED 2
#define LED3                 (0x04) // LED 3
#define LED5                 (0x10) // LED 5
#define LED6                 (0x20) // LED 6
#define LED7                 (0x40) // LED 7
#define LED8                 (0x80) // LED 8
#define SW1                  (0x01) // Switch 1
#define SW2                  (0x02) // Switch 2
#define CNTL_STATE_INDEX        (3)
#define first   (1)
#define second  (2)
#define third    (3)
#define four   (4)
#define five   (5)
#define start    (0)
#define INIT   (0x00)

#define BLINK_LED            (0x01) // Allow LED to Blink
#define CNTL_STATE_INDEX        (3) // Control States
#define LCD_LINE_1           (0x80) // Position Cursor at Character 01 of Line 1
#define LCD_LINE_2           (0xC0) // Position Cursor at Character 01 of Line 2
#define GPS_ONOFF            (0x08) //
#define USE_LED5             (0x40)  //
#define USE_SMCLK            (0x00)  //
#define USE_NFETS            (0xA0)  //
#define CLEAR_DISPLAY        (0x01)

#define CSLOCK               (0x01) // Any incorrect password locks registers

#define TA1CCR0_INTERVAL      (2500) //(2500) // 8,000,000 / 8 / 2 / 25000 = 200Hz => 5msec
#define TA1CCR1_INTERVAL       (50000)//100ms
#define TA1CCR2_INTERVAL       (2500)




#define RESET_STATE   (0x00)

// Display Modes
#define ORIGINAL             (0x00) //

#define FLLN_BITS          (0x03ffu)
#define FLLN_255           (0x00ffu)

// Port J Pins
#define XINR                 (0x10) // XINR
#define XOUTR                (0x20) // XOUTR
#define CLEAR_REGISTER     (0X0000)

// LCD
#define LCD_HOME_L1	          0x80
#define LCD_HOME_L2         	0xA0
#define LCD_HOME_L3         	0xC0
#define LCD_HOME_L4         	0xE0

//Configure Port 1 
#define V_DETECT_R           (0x01) // 
#define V_DETECT_L           (0x02) //
#define IR_LED               (0x04) //
#define V_THUMB              (0x08) //
#define SPI_CS_LCD           (0x10) // LCD Chip Select
#define SA0_LCD              (0x20) // LCD SA0 H/L Slave Address
#define SIMO_B               (0x40) // SPI mode - slave in/master out of USCI_B0
#define SOMI_B               (0x80) // SPI mode - slave out/master in of USCI_B0


  
//Configure Port 2
#define USB_TXD     (0x01)//
#define USB_RXD     (0x02)//
#define SPI_SCK     (0x04)//
#define P2_3        (0x08) // 
#define P2_4        (0x10) // 
#define CPU_TXD     (0x20) //
#define CPU_RXD     (0x40) // 
#define P2_7        (0x80) //

//Configure Port 3
#define X                   (0x01)//
#define Y                   (0x02)//
#define P_Z                   (0x04)//
#define LCD_BACKLITE        (0x08) // 
#define R_FORWARD           (0x10) // 
#define R_REVERSE           (0x20) //
#define L_FORWARD           (0x40) // 
#define L_REVERSE           (0x80) //



// Configure PORT 4
// Port 4 has only two pins 
// Port 4 Pins 
#define SW1                  (0x01) // Switch 1
#define SW2                  (0x02) // Switch 2
#define repeat                (1)
#define next                  (2)
#define waite                 (3)


// Port J Pins
#define IOT_FACTORY                 (0x01) // LED 5
#define IOT_WAKEUP                 (0x02) // LED 6
#define IOT_STA_MINIAP                 (0x04) // LED 7
#define RESET                 (0x08) // LED 8
#define XINR                 (0x10) // XINR
#define XOUTR                (0x20) // XOUTR


//car functions
#define __1              (1)
#define __2                (2)
#define __3              (3)
#define finish_job           (4)
#define __10               (10)
#define pj3over              (333)
#define __7             (7)
#define __5             (5)
#define __8             (8)
#define __9             (9)
#define __4             (4)
#define __6             (6)
#define __100            (100)


//time_defines

#define onesec           (200)
#define twosec           (400)
#define halfsec          (100)
#define fivesec          (1000)
#define tensec            (2000)
#define half_halfsec       (50)
#define zero             (0)
#define line (11)
#define total       (1024)
#define QUATERSEC       (20)

#define debounce_time   (50)
#define enable           (1)
#define disable           (0)




//sleeping time
#define sleep_time_30sec      (300) //(sleep_time)*0.1s = sleep time
#define sleep_time_1min       (600) 
#define sleep_time_5min       (3000)
#define sleep_time_10min      (6000)











#define SDIV (10)
#define ARRAYL (16)
#define CONFIGT (500)
#define CONFIGt2 (400)
#define CONGIGT3 (400)
#define SLOWDOWN (15)
#define SLWODOWN (50)
#define SLOWF (25)
#define HALF (2)
#define REVT1 (5)
#define CLOCKT (52)
#define COUNTERC1 (75)

#define RESULTOVER (2)
#define TIMEOVER (4)
#define HIADC (6)
#define LOADC (8)
#define INADC (10)
#define THIS (12)
#define TISSSS (14)

#define R1TIME (2)
#define R2TIME (4)

#define CLEAR                (0x00) //clear
#define ONE                        1 //ON

#define black_line_def   (200)


//serial communication

#define baud_9600_BRW   (52)
#define baud_9600_MCTLW  (0x4911)
#define baud_115200_BRW  (4)
#define baud_115200_MCTLW (0x5551)
#define BEGINNING (0)
#define SMALL_RING_SIZE (16)
#define LARGE_RING_SIZE  (32)
#define COMMAND_SIZE  (40)
#define Vector_2    (2)
#define Vector_4    (4)


//menu set up

#define start_menu      (1)
#define menu_1          (205)
#define menu_2          (410)
#define menu_3          (615)
#define menu_4          (820)
#define menu_5          (1024)
#define menu_1_inf      "SETTING"
#define sub1_menu_1_inf  "ADC TEST"
#define sub1_menu_2_inf  "Config Mod"
#define sub1_menu_3_inf  "Back Light"
#define sub1_menu_4_inf  "config_straight"
#define sub1_menu_5_inf  "SleepSetUp"  
#define menu_2_inf      "Car Moves"
#define menu_3_inf      "Communcate"
#define menu_4_inf      "WIFI MODE"
#define sub2_menu_1_inf "HOME MODE"
#define sub2_menu_2_inf "NCSU MODE"
#define sub2_menu_3_inf "IP DETECT"
#define sub2_menu_4_inf "SEND PING"
#define sub2_menu_5_inf "RECE WIFI"
#define menu_5_inf      "undefined"

//Car related 
#define max_speed       (2500-1)
#define move_speed      (250-1)
#define low_speed       (700-1)
#define speed_change      (10)

//wifi defines
#define find_ip                 3
#define ip_length               14
#define enter__			0x0D
//#define SSIDTXT			"AT+S.SSIDTXT="
#define SSID_length		13
//#define SCFG			"AT+S.SCFG="
#define SCFG_length		10
#define name_length		4
//#define home_password	"wifi_wpa_psk_text,kangshufan"
//#define wifi_priv_mode	"wifi_priv_mode,"
//#define wifi_mode      	"wifi_mode"
//#define AT_W			"AT&W"
//#define AT_CFUN_1		"AT&CFUN=1"
//#define SEND_PING		"AT+S.PING=192.168.0.123"






// Global Variables
extern  volatile unsigned char control_state[CNTL_STATE_INDEX];
extern volatile unsigned int Time_Sequence;
extern char led_smclk;
extern volatile char one_time;
extern char display_line_1[line];
extern char display_line_2[line];
extern char display_line_3[line];
extern char display_line_4[line];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char size_count;
extern char big;
extern int switch_option;
extern int current_job;
extern int next_job;
extern int time_test;
extern volatile int fivemscount;
extern volatile int fivemsblink;
extern volatile int sw1_bolling;
extern volatile int sw2_bolling; 
extern volatile  unsigned int channalCount;
extern volatile  unsigned int chan;
extern volatile  unsigned int ADC_Right_Detector;
extern volatile  unsigned int ADC_Left_Detector;
extern volatile  unsigned int lineDecOld;
extern volatile unsigned int ADC_Thumb;
volatile extern unsigned int ADC_Thumb;
volatile extern unsigned int ADC_Right_Detector;
volatile extern unsigned int ADC_Left_Detector;
volatile extern unsigned int lineDecOld;
volatile extern unsigned int FirsttimeLine;

volatile extern unsigned int processCount;
volatile extern unsigned int RWhiteReading;
volatile extern unsigned int LWhiteReading;
volatile extern unsigned int RBlackReading;
volatile extern unsigned int LBlackReading;
volatile extern unsigned int LAvg;
volatile extern unsigned int RAvg;
volatile extern unsigned int avg_black;
volatile extern unsigned int avg_white;
extern int black_line;
extern int sleep_enable;
extern volatile unsigned int usb_rx_ring_wr;
extern volatile char USB_Char_Rx[SMALL_RING_SIZE];
extern volatile unsigned int usb_rx_ring_rd;
extern volatile char USB_Char_Tx[SMALL_RING_SIZE];
extern volatile unsigned int usb_tx_ring_wr;
extern volatile unsigned int usb_tx_ring_rd;
extern volatile int back_light_state;
extern volatile unsigned int right_forward_speed;
extern volatile unsigned int left_forward_speed;
extern volatile unsigned int timeA1_CCR1;
extern volatile unsigned int cpu_rx_ring_wr;
extern volatile char CPU_Char_Rx[LARGE_RING_SIZE] ;
extern volatile unsigned int cpu_rx_ring_rd;
extern volatile char CPU_Char_Tx[SMALL_RING_SIZE];
extern volatile unsigned int cpu_tx_ring_wr;
extern volatile unsigned int cpu_tx_ring_rd;
extern volatile unsigned int sleep_time;
extern volatile int check_ip;
extern volatile int writing_ip;
extern volatile char ip_char[ip_length];
extern volatile int ip_index;
extern volatile int asking_ip;
extern volatile int command_mode;
extern volatile int command_index;
extern volatile char command[COMMAND_SIZE];
extern volatile int command_done; 
extern volatile unsigned int sleeping__;
extern volatile int webpage_mode;
//extern volatile char *Rx_char;
//extern volatile char *Tx_char;
 
 
