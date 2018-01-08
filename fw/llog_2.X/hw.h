#include <xc.h>

#define		LL_LOG_SIZE	1440/1
#define     LOG_PERIOD  1   //minutes

#define     KEY_1   PORTFbits.RF6
#define     KEY_2   PORTDbits.RD11
#define     KEY_3   PORTDbits.RD9
#define     KEY_4   PORTEbits.RE4

#define     MEM_CS  LATFbits.LATF4

#define     LDR_PWR LATBbits.LATB7

#define     LDR_ADC_CHNL    6

#define     EE_SIZE        32768
#define     EE_PAGE_SIZE   4
#define     MAX_EE_LOG_PTR EE_SIZE/EE_PAGE_SIZE

#define	FCY		500000UL


typedef struct osa_msg_res_struct {
	uint8_t sec_o;
	uint8_t sec_t;
	uint8_t min_o;
	uint8_t min_t;
	uint8_t hrs_o;
	uint8_t hrs_t;
	uint8_t day_o;
	uint8_t day_t;
	uint8_t mon_o;
	uint8_t mon_t; 
} rtc_t;

typedef union
{
struct
 {
    unsigned k1:1;
    unsigned k2:1;
    unsigned k3:1;
    unsigned k4:1;
 };
unsigned char CHAR;
}key_t; 

void shdn (uint8_t lcd_state);
void enable_lcd (void);
void power_on (void);
void main_init (void);
void clock_lprc (void);
void clock_frc (void);
void rtc_read (rtc_t * rtc_val);
void rtc_write_hm (rtc_t * rtc_val);
void rtc_write_md (rtc_t * rtc_val);
uint8_t timer_elapsed (void);
uint8_t keys_state (void);

uint8_t write_spi (uint8_t data);
void ee_wren (void);
uint8_t ee_rdsr (void);
void ee_write_page (uint16_t addr, uint8_t * data, uint8_t len);
void ee_read_page (uint16_t addr, uint8_t * data, uint8_t len);

void usart_send_str (char * data);
void usart_send_str (char * data);
void write_u1 (unsigned char data);
unsigned int get_adc(uint8_t chnl);


#define MS_DISP_TIME    0
#define MS_DISP_DATE    1
#define MS_EDIT_TIME    2
#define MS_EDIT_DATE    3
#define MS_DISP_LAT     4
#define MS_DISP_LON     5
#define MS_DISP_LOG     6
#define MS_DISP_SND     7
#define MS_DISP_SENDING 8
#define MS_IDLE         9
#define MS_CALCULATE    10
#define MS_UPDATE       11
#define MS_LCDST        12
