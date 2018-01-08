#include <xc.h>
#include <stdio.h>
#include "lcd.h"
#include "geo.h"
#include "hw.h"


//init test data, 2.1.2018
const uint16_t ll_vals[1440] = {
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 2, 3, 3, 3, 3, 
3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6, 7, 8, 9, 10, 12, 13, 15, 18, 20, 23, 26, 30, 34, 39, 45, 52, 59, 66, 
74, 82, 91, 100, 108, 116, 124, 132, 139, 146, 153, 160, 166, 172, 178, 184, 190, 194, 198, 201, 204, 207, 209, 211, 213, 215, 217, 218, 
220, 220, 221, 221, 222, 223, 223, 223, 223, 223, 224, 224, 225, 225, 225, 224, 223, 221, 220, 218, 218, 218, 218, 219, 220, 221, 222, 224, 
225, 227, 228, 229, 231, 232, 233, 234, 235, 236, 237, 239, 239, 240, 241, 241, 242, 242, 242, 242, 243, 243, 244, 244, 244, 244, 244, 244,
 244, 244, 244, 245, 245, 245, 245, 245, 245, 245, 245, 245, 246, 246, 246, 246, 245, 245, 245, 246, 246, 246, 246, 246, 247, 247, 247, 247, 
247, 247, 247, 247, 247, 247, 248, 248, 248, 248, 248, 248, 248, 248, 249, 249, 249, 249, 249, 249, 249, 249, 248, 248, 248, 248, 248, 248, 
247, 247, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 247, 247, 247, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 
247, 247, 247, 246, 244, 243, 243, 244, 244, 244, 245, 245, 244, 244, 244, 245, 246, 247, 247, 248, 248, 248, 248, 248, 248, 249, 249, 249, 
249, 249, 250, 250, 250, 249, 249, 248, 249, 249, 249, 248, 248, 248, 248, 248, 248, 248, 248, 247, 246, 246, 246, 246, 246, 244, 243, 243, 
244, 245, 246, 245, 245, 245, 245, 245, 244, 244, 244, 243, 242, 240, 236, 232, 229, 226, 224, 223, 223, 223, 224, 224, 223, 224, 225, 225, 
225, 226, 228, 232, 234, 235, 237, 239, 241, 244, 245, 246, 246, 246, 246, 246, 246, 246,
 246, 246, 247, 247, 247, 247, 247, 247, 246, 246, 247, 247, 248, 248, 249, 250, 250, 249, 249, 249, 249, 249, 250, 250, 249, 249, 249, 248, 
248, 248, 247, 247, 246, 245, 245, 245, 245, 246, 246, 246, 246, 245, 244, 245, 245, 245, 246, 246, 247, 248, 248, 248, 248, 249, 249, 249, 
249, 249, 248, 248, 247, 247, 247, 247, 248, 247, 247, 247, 247, 246, 247, 246, 246, 247, 246, 246, 245, 245, 245, 245, 245, 245, 244, 244, 
244, 244, 244, 244, 243, 244, 244, 244, 243, 243, 242, 241, 241, 241, 240, 239, 239, 237, 236, 237, 237, 237, 237, 237, 237, 237, 237, 237, 
236, 236, 236, 235, 235, 235, 234, 234, 233, 233, 232, 231, 231, 230, 230, 230, 229, 228, 228, 230, 
230, 231, 232, 231, 232, 231, 233, 234, 235, 234, 233, 233, 233, 233, 232, 232, 231, 231, 232, 232, 232, 231, 232, 232, 234, 234, 234, 235, 
236, 237, 236, 236, 235, 233, 231, 230, 229, 228, 227, 227, 227, 227, 227, 227, 227, 226, 226, 226, 227, 227, 226, 226, 226, 227, 228, 227, 
226, 225, 225, 225, 227, 229, 231, 231, 232, 232, 232, 232, 232, 231, 231, 230, 230, 229, 229, 228, 228, 228, 227, 227, 226, 225, 224, 223, 
222, 221, 219, 217, 216, 214, 213, 211, 
210, 210, 210, 209, 208, 206, 204, 202, 199, 196, 194, 191, 189, 188, 187, 186, 187, 188, 189, 190, 191, 190, 189, 188, 185, 183, 181, 179, 
178, 176, 174, 172, 171, 168, 166, 163, 160, 157, 156, 154, 151, 149, 145, 139, 131, 120, 108, 96, 85, 76, 71, 68, 65, 61, 57, 54, 51, 47, 
42, 37, 32, 28, 26, 23, 20, 17, 14, 12, 10, 9, 8, 7, 6, 5, 5, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 
2, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 
2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 
2, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 
3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 6, 6, 6, 6, 6, 
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 88, 3, 3, 
4, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
4, 4, 4, 4, 4, 4, 3, 3, 3, 4, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 4, 3, 4, 3, 3, 3, 4, 
4, 4, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4

	
};

void display_time (char * line, char * msg, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t blank);
void display_date (char * line, char * msg, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t blank);
void refresh_lcd_arrays (void);

#define		IDLE_CNT_MAX	10

rtc_t rtc_now,rtc_set;
key_t keys,keys_new,keys_old;
uint8_t main_state,edit_ptr,edit_blank,edit_blank_tmr,main_state_prev,day,month,lcd_state;
uint16_t ll_log_arr[LL_LOG_SIZE],ll_log_ptr=0,mem_log_ptr=0,ee_read_addr=0;
uint16_t i,t,idle_cnt;
char lcd_array[10], lcd_array_o[10],lcd_array_lat[10],lcd_array_lon[10],lcd_array_log[10],tx_str[25];
uint16_t val;
double day_length,solar_noon,declination,latitude,longitude,eq_of_time,lat_read,lon_read;

uint8_t ee_array[8];


void _ISR __attribute__((auto_psv)) _RTCCInterrupt(void)
{
IFS3bits.RTCIF = 0;
ALCFGRPTbits.ALRMEN = 1;
main_state_prev = main_state;
main_state = MS_UPDATE;
}

void _ISR __attribute__((auto_psv)) _T1Interrupt(void)
{
IFS0bits.T1IF = 0;
}

void _ISR __attribute__((auto_psv)) _INT0Interrupt(void)
{
IFS0bits.INT0IF = 0;
main_state = MS_DISP_TIME;
idle_cnt = IDLE_CNT_MAX;
}



int main(void)
	{
	clock_frc();
	main_init();
	refresh_lcd_arrays();
	idle_cnt = IDLE_CNT_MAX;
	for (i=0;i<LL_LOG_SIZE;i++)
		ll_log_arr[i] = ll_vals[i]*4;
	analyze_ll_data(ll_log_arr,LL_LOG_SIZE,&day_length,&solar_noon);
	solar_noon = solar_noon + 1.0;
	declination = get_declination(3,1);
	eq_of_time = get_eq_time(3,1);
	latitude = get_latitude(day_length,-3.0,declination);
	longitude = get_longitude(solar_noon,eq_of_time);
	mem_log_ptr++;
	refresh_lcd_arrays();
	clock_lprc();
	lcd_state = 1;
	while (1)
		{
		if (timer_elapsed())
			{
			keys_new.CHAR = keys_state();
			keys.CHAR = keys.CHAR | ((keys_new.CHAR^keys_old.CHAR)&keys_new.CHAR);
			keys_old.CHAR = keys_new.CHAR;
			if (keys_new.CHAR!=0) idle_cnt = IDLE_CNT_MAX;
			rtc_read(&rtc_now);
			edit_blank_tmr++;
			if (edit_blank_tmr==10)
				{
				edit_blank_tmr=0;
				if (edit_blank==0) edit_blank = 10;
				else edit_blank=0;
				
				if (idle_cnt!=0)
					idle_cnt--;
				else
					main_state = MS_IDLE;
				}
			}
		if (main_state==MS_IDLE)
			{
			rtc_read(&rtc_now);
			display_time(lcd_array,"  ",rtc_now.hrs_t,rtc_now.hrs_o,rtc_now.min_t,rtc_now.min_o,10);
			lcd_write_chars(lcd_array,LCD_P1|LCD_X);
			shdn(lcd_state);
			}
		if (main_state==MS_CALCULATE)
			{
			if (ll_log_ptr>(LL_LOG_SIZE-5))
				{
				clock_frc();
				day = rtc_now.day_t*10 + rtc_now.day_o*1;
				month = rtc_now.mon_t*10 + rtc_now.mon_o*1;
				lcd_write_chars("calculate",0);
				analyze_ll_data(ll_log_arr,LL_LOG_SIZE,&day_length,&solar_noon);
				solar_noon = solar_noon + 0.0;
				declination = get_declination(day,month);
				eq_of_time = get_eq_time(day,month);
				latitude = get_latitude(day_length,-3.0,declination);
				longitude = get_longitude(solar_noon,eq_of_time);
				if (mem_log_ptr<MAX_EE_LOG_PTR)
					{
					prepare_mem_log(latitude,longitude,ee_array);
					ee_write_page(mem_log_ptr*EE_PAGE_SIZE,ee_array,EE_PAGE_SIZE*2);//writing 8 bytes, last 4 are only 0xFF to denote end of record
					mem_log_ptr++;										//those 4 bytes will be overwritten on next record
					}
				refresh_lcd_arrays();
				clock_lprc();
				}
			ll_log_ptr = 0;
			main_state = main_state_prev;
			}
		if (main_state==MS_UPDATE)
			{
			clock_frc();
			LDR_PWR = 1;
			main_state = main_state_prev;
			rtc_read(&rtc_now);
			//ll_log_arr[ll_log_ptr] = ll_vals[ll_log_ptr];
			ll_log_arr[ll_log_ptr] = get_adc(LDR_ADC_CHNL) / 4;
			ll_log_ptr++;
			LDR_PWR = 0;
			if ((rtc_now.min_o==0)&(rtc_now.min_t==0)&(rtc_now.hrs_o==0)&(rtc_now.hrs_t==0))
			//if (ll_log_ptr==LL_LOG_SIZE)
				{
				main_state = MS_CALCULATE;
				}
			clock_lprc();
			}
		
		if (main_state==MS_DISP_TIME)
			{
			//display_time(lcd_array,"te",rtc_now.min_t,rtc_now.min_o,rtc_now.sec_t,rtc_now.sec_o,10);
			display_time(lcd_array,"tn",rtc_now.hrs_t,rtc_now.hrs_o,rtc_now.min_t,rtc_now.min_o,10);
			lcd_write_chars(lcd_array,LCD_P1);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_DATE;
				}
			if (keys.k2)
				{
				keys.k2 = 0;
				main_state = MS_EDIT_TIME;
				rtc_read(&rtc_set);
				}
			}
		if (main_state==MS_DISP_DATE)
			{
			display_date(lcd_array,"dn",rtc_now.mon_t,rtc_now.mon_o,rtc_now.day_t,rtc_now.day_o,10);
			lcd_write_chars(lcd_array,0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_LAT;
				}
			if (keys.k2)
				{
				keys.k2 = 0;
				main_state = MS_EDIT_DATE;
				rtc_read(&rtc_set);
				}
			}
		if (main_state==MS_DISP_LAT)
			{
			lcd_write_chars(lcd_array_lat,0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_LON;
				}
			}
		if (main_state==MS_DISP_LON)
			{
			lcd_write_chars(lcd_array_lon,0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_LOG;
				}
			}
		if (main_state==MS_DISP_LOG)
			{
			lcd_write_chars(lcd_array_log,0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_SND;
				}
			}		
		if (main_state==MS_DISP_SND)
			{
			lcd_write_chars("send log",0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_LCDST;
				}
			if (keys.k2)
				{
				keys.k2 = 0;
				main_state = MS_DISP_SENDING;
				ee_read_addr = 0;
				clock_frc();
				}
			}
		if (main_state==MS_DISP_SENDING)
			{
			idle_cnt = IDLE_CNT_MAX;
			if (edit_blank==0)
				lcd_write_chars("WAIT_   ",0);
			else
				lcd_write_chars("WAIT-   ",0);
			ee_read_page(ee_read_addr*4,ee_array,4);
			if (ee_array[0]==0xFF)
				{
				main_state = MS_DISP_SND;
				clock_lprc();
				}
			else
				{
				read_mem_log(&lat_read,&lon_read,ee_array);
				sprintf(tx_str,"%d;%2.2f;%2.2f\n",ee_read_addr,lat_read,lon_read);
				usart_send_str(tx_str);
				ee_read_addr++;
				}
			if (keys.k4)
				{
				keys.k4 = 0;
				main_state = MS_DISP_SND;
				clock_lprc();
				}
			}
		if (main_state==MS_LCDST)
			{
			if (lcd_state==0)
				lcd_write_chars("lcd off ",0);
			else
				lcd_write_chars("lcd on  ",0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_TIME;
				}
			if (keys.k2)
				{
				keys.k2 = 0;
				if (lcd_state==0)
					lcd_state = 1;
				else
					lcd_state = 0;
				}
			}

		if (main_state==MS_EDIT_TIME)
			{
			display_time(lcd_array,"te",rtc_set.hrs_t,rtc_set.hrs_o,rtc_set.min_t,rtc_set.min_o,edit_ptr+edit_blank);
			lcd_write_chars(lcd_array,0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_TIME;
				}
			if (keys.k2)
				{
				keys.k2 = 0;
				edit_ptr++;
				if (edit_ptr==4) edit_ptr = 0;
				}
			if (keys.k3)
				{
				keys.k3 = 0;
				if (edit_ptr==0) {rtc_set.hrs_t++; if (rtc_set.hrs_t>2) rtc_set.hrs_t=0;}
				if (edit_ptr==1) {rtc_set.hrs_o++; if (rtc_set.hrs_o>9) rtc_set.hrs_o=0;}
				if (edit_ptr==2) {rtc_set.min_t++; if (rtc_set.min_t>5) rtc_set.min_t=0;}
				if (edit_ptr==3) {rtc_set.min_o++; if (rtc_set.min_o>9) rtc_set.min_o=0;}
				}
			if (keys.k4)
				{
				keys.k4 = 0;
				rtc_write_hm(&rtc_set);
				main_state = MS_DISP_TIME;
				}
			}
		if (main_state==MS_EDIT_DATE)
			{
			display_date(lcd_array,"de",rtc_set.mon_t,rtc_set.mon_o,rtc_set.day_t,rtc_set.day_o,edit_ptr+edit_blank);
			lcd_write_chars(lcd_array,0);
			if (keys.k1)
				{
				keys.k1 = 0;
				main_state = MS_DISP_DATE;
				}
			if (keys.k2)
				{
				keys.k2 = 0;
				edit_ptr++;
				if (edit_ptr==4) edit_ptr = 0;
				}
			if (keys.k3)
				{
				keys.k3 = 0;
				if (edit_ptr==0) {rtc_set.mon_t++; if (rtc_set.mon_t>1) rtc_set.mon_t=0;}
				if (edit_ptr==1) {rtc_set.mon_o++; if (rtc_set.mon_o>9) rtc_set.mon_o=0;}
				if (edit_ptr==2) {rtc_set.day_t++; if (rtc_set.day_t>3) rtc_set.day_t=0;}
				if (edit_ptr==3) {rtc_set.day_o++; if (rtc_set.day_o>9) rtc_set.day_o=0;}
				}
			if (keys.k4)
				{
				keys.k4 = 0;
				rtc_write_md(&rtc_set);
				main_state = MS_DISP_DATE;
				}
			}
		}
	}


void refresh_lcd_arrays (void)
	{
	sprintf(lcd_array_lat,"LA %1.1f",latitude);
	sprintf(lcd_array_lon,"LO %1.1f",longitude);
	sprintf(lcd_array_log,"LOG %4.4d",mem_log_ptr);
	}


void display_time (char * line, char * msg, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t blank)
	{
	line[0] = msg[0];
	line[1] = msg[1];
	line[2]	= ' ';
	line[3]	= ' ';
	line[4]	= '0'+v1;
	line[5]	= '0'+v2;
	line[6]	= '0'+v3;
	line[7]	= '0'+v4;
	if (blank==0) line[4] = ' ';
	if (blank==1) line[5] = ' ';
	if (blank==2) line[6] = ' ';
	if (blank==3) line[7] = ' ';
	}

void display_date (char * line, char * msg, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t blank)
	{
	line[0] = msg[0];
	line[1] = msg[1];
	line[2]	= ' ';
	line[3]	= '0'+v1;
	line[4]	= '0'+v2;
	line[5]	= '-';
	line[6]	= '0'+v3;
	line[7]	= '0'+v4;
	if (blank==0) line[3] = ' ';
	if (blank==1) line[4] = ' ';
	if (blank==2) line[6] = ' ';
	if (blank==3) line[7] = ' ';

	}


	/*
	for (i=0;i<LL_LOG_SIZE;i++)
		ll_log_arr[i] = ll_vals[i]*4;
	analyze_ll_data(ll_log_arr,LL_LOG_SIZE,&day_length,&solar_noon);
	solar_noon = solar_noon + 1.0;
	declination = get_declination(3,1);
	eq_of_time = get_eq_time(3,1);
	latitude = get_latitude(day_length,-3.0,declination);
	longitude = get_longitude(solar_noon,eq_of_time);

	lcd_write_chars("12345678",LCD_P1|LCD_P2|LCD_X);
		 * 	 */



