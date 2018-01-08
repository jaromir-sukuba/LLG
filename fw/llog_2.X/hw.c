#include <xc.h>
#include "lcd.h"
#include "hw.h"

//#define		DEBUG_CLOCK		1


// CONFIG4
#pragma config DSWDTPS = DSWDTPS1F      // Deep Sleep Watchdog Timer Postscale Select bits (1:68719476736 (25.7 Days))
#pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select (DSWDT uses LPRC as reference clock)
#pragma config DSBOREN = OFF            // Deep Sleep BOR Enable bit (DSBOR Disabled)
#pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer Enable (DSWDT Disabled)
#pragma config DSSWEN = ON              // DSEN Bit Enable (Deep Sleep is controlled by the register bit DSEN)

// CONFIG3
#pragma config WPFP = WPFP127           // Write Protection Flash Page Segment Boundary (Page 127 (0x1FC00))
#pragma config VBTBOR = OFF             // VBAT BOR enable bit (VBAT BOR disabled)
#pragma config SOSCSEL = ON             // SOSC Selection bits (SOSC circuit selected)
#pragma config WDTWIN = PS25_0          // Watch Dog Timer Window Width (Watch Dog Timer Window Width is 25 percent)
#pragma config BOREN = OFF              // Brown-out Reset Enable (Brown-out Reset Disabled)
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable (Disabled)
#pragma config WPCFG = WPCFGDIS         // Write Protect Configuration Page Select (Disabled)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select (Write Protect from WPFP to the last page of memory)

// CONFIG2
#pragma config POSCMD = NONE            // Primary Oscillator Select (Primary Oscillator Disabled)
#pragma config BOREN1 = DIS             // BOR Override bit (BOR Disabled [When BOREN=0])
#pragma config IOL1WAY = OFF            // IOLOCK One-Way Set Enable bit (The IOLOCK bit can be set and cleared using the unlock sequence)
#pragma config OSCIOFCN = ON            // OSCO Pin Configuration (OSCO/CLKO/RC15 functions as port I/O (RC15))
#pragma config FCKSM = CSECMD           // Clock Switching and Fail-Safe Clock Monitor Configuration bits (Clock switching is enabled, Fail-Safe Clock Monitor is disabled)
#pragma config FNOSC = FRCDIV           // Initial Oscillator Select (Fast RC Oscillator with Postscaler (FRCDIV))
#pragma config ALTVREF = DLT_AV_DLT_CV  // Alternate VREF/CVREF Pins Selection bit (Voltage reference input, ADC =RA9/RA10 Comparator =RA9,RA10)
#pragma config IESO = ON                // Internal External Switchover (Enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler Select (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler Ratio Select (1:128)
#pragma config FWDTEN = WDT_DIS         // Watchdog Timer Enable (WDT disabled in hardware; SWDTEN bit disabled)
#pragma config WINDIS = OFF             // Windowed WDT Disable (Standard Watchdog Timer)
#pragma config ICS = PGx1               // Emulator Pin Placement Select bits (Emulator functions are shared with PGEC1/PGED1)
#pragma config LPCFG = ON               // Low power regulator control (Enabled)
#pragma config GWRP = OFF               // General Segment Write Protect (Disabled)
#pragma config GCP = OFF                // General Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (Disabled)

/*
 
 * 8M - 1100uA	-	0
 * 4M - 1050uA	-	1
 * 2M - 650uA	-	2
 * 1M - 380uA	-	3
 * 500k - 365uA	-	4
 * 250k - 300uA	-	5
 * 125k - 288uA	-	6
 * 31k - 280uA	-	7
 * 
 * 31k LPRC - 22uA
 */

void main_init (void)
	{
	CLKDIVbits.RCDIV = 3;	//1MHz

	PMD1 = 0xFFFF;
	PMD2 = 0xFFFF;
	PMD3 = 0xFDFF;
	PMD4 = 0xFFFF;
	PMD6 = 0xFFBF;
	PMD7 = 0xFFFF;

	TRISB = 0x0040;
	TRISC = 0x0000;
	TRISD = 0x0000;
	TRISE = 0x0000;
	TRISF = 0x0000;
	TRISG = 0x0000;
	MEM_CS = 1;
	TRISDbits.TRISD9 = 1;
	TRISDbits.TRISD11 = 1; 
	TRISEbits.TRISE4 = 1;
	TRISFbits.TRISF6 = 1;
	TRISFbits.TRISF5 = 1;
	ANSDbits.ANSD11 = 0;
	ANSEbits.ANSE4 = 0;	

	power_on();	
	enable_lcd();
	
	__builtin_write_RTCWEN();
	ALCFGRPTbits.AMASK = 0b0011;
	ALCFGRPTbits.ALRMEN = 1;
	RTCPWCbits.RTCLK = 0b00;
	RCFGCALbits.RTCWREN = 1;
	RCFGCALbits.RTCEN = 1;
	IEC3bits.RTCIE = 1;
	RCFGCALbits.RTCWREN = 0;
	
//	IEC0bits.INT0IE = 1;
	
	}



void enable_lcd (void)
	{
	LCDCONbits.LMUX = 0b011;
	LCDCONbits.CS = 0b01;
	LCDREFbits.LCDIRE = 1;
	LCDREFbits.LRLAP = 0x01;
	LCDREFbits.LRLBP = 0x01;
	LCDPSbits.LP = 7;
	LCDSE0bits.SE00 = 1;
	LCDSE0bits.SE01 = 1;
	LCDSE0bits.SE02 = 1;
	LCDSE0bits.SE03 = 1;
	LCDSE0bits.SE04 = 1;
	LCDSE0bits.SE05 = 1;
	LCDSE1bits.SE17 = 1;
	LCDSE1bits.SE20 = 1;
	LCDSE1bits.SE21 = 1;
	LCDSE1bits.SE22 = 1;
	LCDSE1bits.SE23 = 1;
	LCDSE1bits.SE24 = 1;
	LCDSE1bits.SE25 = 1;
	LCDSE1bits.SE26 = 1;
	LCDSE1bits.SE27 = 1;
	LCDSE3bits.SE48 = 1;
	LCDCONbits.LCDEN = 1;
	set_segs(0x0000);
	}


void clock_lprc (void)
	{
#ifndef DEBUG_CLOCK
	if (OSCCONbits.COSC!=0b101)
		{
		__builtin_write_OSCCONH(0b101);
		__builtin_write_OSCCONL(0b001);
		}
#endif
	}

void clock_frc (void)
	{
	if (OSCCONbits.COSC!=0b111)
		{
		__builtin_write_OSCCONH(0b111);
		__builtin_write_OSCCONL(0b001);
		}
	}


void rtc_read (rtc_t * rtc_val)
	{
	uint16_t tmp;
	RCFGCALbits.RTCPTR = 0;
	tmp = RTCVAL;
	rtc_val->sec_o = tmp&0xF;
	rtc_val->sec_t = (tmp>>4)&0x7;
	rtc_val->min_o = (tmp>>8)&0xF;
	rtc_val->min_t = (tmp>>12)&0x7;
	RCFGCALbits.RTCPTR = 1;
	tmp = RTCVAL;
	rtc_val->hrs_o = tmp&0xF;
	rtc_val->hrs_t = (tmp>>4)&0x7;
	RCFGCALbits.RTCPTR = 2;
	tmp = RTCVAL;
	rtc_val->day_o = tmp&0xF;
	rtc_val->day_t = (tmp>>4)&0x7;
	rtc_val->mon_o = (tmp>>8)&0xF;
	rtc_val->mon_t = (tmp>>12)&0x7;
	}

void rtc_write_hm (rtc_t * rtc_val)
	{
	uint16_t tmp,tmp2;
	tmp = rtc_val->sec_o;
	tmp = tmp | ((rtc_val->sec_t&0x07)<<4);
	tmp = tmp | ((rtc_val->min_o&0x0F)<<8);
	tmp = tmp | ((rtc_val->min_t&0x07)<<12);
	tmp2 = rtc_val->hrs_o;
	tmp2 = tmp2 | ((rtc_val->hrs_t&0x07)<<4);
	__builtin_write_RTCWEN();
	RCFGCALbits.RTCWREN = 1;
	RCFGCALbits.RTCPTR = 0;
	RTCVAL = tmp;
	RCFGCALbits.RTCPTR = 1;
	RTCVAL = tmp2;
	RCFGCALbits.RTCWREN = 0;
	}

void rtc_write_md (rtc_t * rtc_val)
	{
	unsigned int tmp;
	tmp = rtc_val->day_o;
	tmp = tmp | ((rtc_val->day_t&0x07)<<4);
	tmp = tmp | ((rtc_val->mon_o&0x0F)<<8);
	tmp = tmp | ((rtc_val->mon_t&0x07)<<12);
	__builtin_write_RTCWEN();
	RCFGCALbits.RTCWREN = 1;
	RCFGCALbits.RTCPTR = 2;
	RTCVAL = tmp;
	RCFGCALbits.RTCWREN = 0;
	}


uint8_t timer_elapsed (void)
	{
	if (IFS0bits.T1IF)
		{
		IFS0bits.T1IF = 0;
		return 1;
		}
	return 0;
	}


uint8_t keys_state (void)
	{
	uint8_t retval=0;
	if (KEY_1==0) retval = 0x01;
	if (KEY_2==0) retval = retval|0x02;
	if (KEY_3==0) retval = retval|0x04;
	if (KEY_4==0) retval = retval|0x08;
	return retval;
	}


uint8_t write_spi (uint8_t data)
	{
	uint8_t test;
	SPI1BUF = data;
	while(SPI1STATbits.SPIRBF==0);
	test = SPI1BUF;
	return test;
	}


void ee_wren (void)
	{
	MEM_CS = 0;
	write_spi(0x06);
	MEM_CS = 1;
	}

uint8_t ee_rdsr (void)
	{
	uint8_t tmp;
	MEM_CS = 0;
	write_spi(0x05);
	tmp = write_spi(0x00);
	MEM_CS = 1;
	return tmp;
	}

void ee_write_page (uint16_t addr, uint8_t * data, uint8_t len)
	{
	uint16_t i;
	ee_wren();
	MEM_CS = 0;
	write_spi(0x02);
	write_spi((addr>>8)&0xFF);
	write_spi((addr>>0)&0xFF);
	for (i=0;i<len;i++)
		write_spi(data[i]);
	MEM_CS = 1;
	}

void ee_read_page (uint16_t addr, uint8_t * data, uint8_t len)
	{
	uint16_t i;
	MEM_CS = 0;
	write_spi(0x03);
	write_spi((addr>>8)&0xFF);
	write_spi((addr>>0)&0xFF);
	for (i=0;i<len;i++)
		data[i] = write_spi(0);
	MEM_CS = 1;
	}


void shdn (uint8_t lcd_state)
	{
	AD1CON1bits.ADON = 0;
	PMD1bits.ADC1MD = 1;
	PMD1bits.T1MD = 1;
	PMD1bits.SPI1MD = 1;	
	PMD1bits.U1MD = 1;
	if (lcd_state==0)
		{
		PMD6bits.LCDMD = 1;
		}
	IFS0bits.INT0IF = 0;
	IEC0bits.INT0IE = 1;
	RCONbits.RETEN = 1;
	asm volatile ("PWRSAV #0x0000");			
	asm volatile ("NOP");	
	power_on();
	if (lcd_state==0)
		{
		PMD6bits.LCDMD = 0;
		enable_lcd();
		}
	
	}


void power_on (void)
	{
	IEC0bits.INT0IE = 0;
	PMD1bits.T1MD = 0;
	PMD1bits.SPI1MD = 0;	
	PMD1bits.U1MD = 0;
	PMD1bits.ADC1MD = 0;
	PR1 = 31*30;
	T1CONbits.TCS = 1;
	T1CONbits.TIECS = 0b10;	
	T1CONbits.TON = 1;	
	__builtin_write_OSCCONL(OSCCON & 0xbf);
	RPINR20bits.SDI1R = 17;
	RPOR8bits.RP16R = 7;
	RPOR15bits.RP30R = 8;
	RPOR0bits.RP0R = 3;
	__builtin_write_OSCCONL(OSCCON | 0x40);
	
	SPI1CON1bits.MSTEN = 1;
	SPI1CON1bits.SPRE = 0b111;
	SPI1CON1bits.PPRE = 0b11;
	SPI1CON1bits.CKE = 1;
	SPI1STATbits.SPIEN = 1;	
	
	U1BRG = (FCY / 16 / 9600) - 1;
	U1MODEbits.UARTEN = 1;
	U1STAbits.UTXEN = 1;		
	
	AD1CON1 = 0x0470;
	AD1CON2 = 0x2000;
	AD1CON3 = 0x8201;
	AD1CSSL=0;
	
	
	}


void usart_send_str (char * data)
	{
	while (*data!=0)
		write_u1(*data++);
	}

void write_u1 (unsigned char data)
{
U1TXREG = data;
while (U1STAbits.TRMT==0);
}


unsigned int get_adc(uint8_t chnl)
	{
	
		AD1CON1bits.ADON = 1;	
		AD1CHS = chnl;
		AD1CON1bits.SAMP = 1;
		while (AD1CON1bits.DONE==0);
		AD1CON1bits.ADON = 0;	
		return ADC1BUF0;	
	}