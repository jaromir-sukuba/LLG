#include	"lcd.h"
#include <xc.h>



/*
 
 aa
f  b
f  b
 gg
e  c
e  c
 dd
 */

const unsigned char digit_table[10] = {
//    pgfedcba	  pgfedcba
	0b00111111, 0b00000110,
	0b01011011, 0b01001111,
	0b01100110, 0b01101101,
	0b01111101, 0b00000111,
	0b01111111, 0b01101111,
};

const unsigned char alpha_table[26]= {
//    pgfedcba	  pgfedcba
	0b01110111,	0b01111100,		//A, b 1
	0b01011000,	0b01011110,		//c, d 2
	0b01111001,	0b01110001,		//e, f 3
	0b01101111,	0b01110100,		//g, h 4
	0b00000110,	0b00001110,		//i, j 5
	0b01110110,	0b00111000,		//k, l 6
	0b00110111,	0b01010100,		//m, n 7
	0b01011100,	0b01110011,		//o, p 8
	0b01100111,	0b01010000,		//q, r 9
	0b01101101,	0b01111000,		//s, t 10
	0b00011100,	0b00011100,		//u, v 11
	0b01111110,	0b01110110,		//w, x 12
	0b01101110,	0b01011011,		//y, z 13
};

const unsigned char sym_table[2]= {
//    pgfedcba	  pgfedcba
	0b00001000,	0b01000000,		//_, - 1
};



void lcd_write_chars (char * data, unsigned char specials)
	{
	unsigned char i,tmp,tmp2;
	unsigned char segs[9];
	for (i=0;i<8;i++)
		{
		tmp = data[i];
		if ((tmp>='0')&(tmp<='9')) tmp2 = digit_table[tmp-'0'];
		else if ((tmp>='a')&(tmp<='z')) tmp2 = alpha_table[tmp-'a'];
		else if ((tmp>='A')&(tmp<='Z')) tmp2 = alpha_table[tmp-'A'];
		else if (tmp=='.') tmp2 = sym_table[0];
		else if (tmp=='_') tmp2 = sym_table[0];
		else if (tmp=='-') tmp2 = sym_table[1];
		else tmp2 = 0;
		segs[7-i] = tmp2;
		}
	lcd_write_segments(segs);
	if (specials&LCD_P1) COL1 = 1;else COL1 = 0;
	if (specials&LCD_P2) COL2 = 1;else COL2 = 0;
	if (specials&LCD_X) SYMB = 1;else SYMB = 0;
	}

void lcd_write_segments (unsigned char * data)
	{
	if (data[0]&SEG_A)	D1SA = 1; else D1SA = 0;
	if (data[0]&SEG_B)	D1SB = 1; else D1SB = 0;
	if (data[0]&SEG_C)	D1SC = 1; else D1SC = 0;
	if (data[0]&SEG_D)	D1SD = 1; else D1SD = 0;
	if (data[0]&SEG_E)	D1SE = 1; else D1SE = 0;
	if (data[0]&SEG_F)	D1SF = 1; else D1SF = 0;
	if (data[0]&SEG_G)	D1SG = 1; else D1SG = 0;

	if (data[1]&SEG_A)	D2SA = 1; else D2SA = 0;
	if (data[1]&SEG_B)	D2SB = 1; else D2SB = 0;
	if (data[1]&SEG_C)	D2SC = 1; else D2SC = 0;
	if (data[1]&SEG_D)	D2SD = 1; else D2SD = 0;
	if (data[1]&SEG_E)	D2SE = 1; else D2SE = 0;
	if (data[1]&SEG_F)	D2SF = 1; else D2SF = 0;
	if (data[1]&SEG_G)	D2SG = 1; else D2SG = 0;

	if (data[2]&SEG_A)	D3SA = 1; else D3SA = 0;
	if (data[2]&SEG_B)	D3SB = 1; else D3SB = 0;
	if (data[2]&SEG_C)	D3SC = 1; else D3SC = 0;
	if (data[2]&SEG_D)	D3SD = 1; else D3SD = 0;
	if (data[2]&SEG_E)	D3SE = 1; else D3SE = 0;
	if (data[2]&SEG_F)	D3SF = 1; else D3SF = 0;
	if (data[2]&SEG_G)	D3SG = 1; else D3SG = 0;
	
	if (data[3]&SEG_A)	D4SA = 1; else D4SA = 0;
	if (data[3]&SEG_B)	D4SB = 1; else D4SB = 0;
	if (data[3]&SEG_C)	D4SC = 1; else D4SC = 0;
	if (data[3]&SEG_D)	D4SD = 1; else D4SD = 0;
	if (data[3]&SEG_E)	D4SE = 1; else D4SE = 0;
	if (data[3]&SEG_F)	D4SF = 1; else D4SF = 0;
	if (data[3]&SEG_G)	D4SG = 1; else D4SG = 0;
	
	if (data[4]&SEG_A)	D5SA = 1; else D5SA = 0;
	if (data[4]&SEG_B)	D5SB = 1; else D5SB = 0;
	if (data[4]&SEG_C)	D5SC = 1; else D5SC = 0;
	if (data[4]&SEG_D)	D5SD = 1; else D5SD = 0;
	if (data[4]&SEG_E)	D5SE = 1; else D5SE = 0;
	if (data[4]&SEG_F)	D5SF = 1; else D5SF = 0;
	if (data[4]&SEG_G)	D5SG = 1; else D5SG = 0;

	if (data[5]&SEG_A)	D6SA = 1; else D6SA = 0;
	if (data[5]&SEG_B)	D6SB = 1; else D6SB = 0;
	if (data[5]&SEG_C)	D6SC = 1; else D6SC = 0;
	if (data[5]&SEG_D)	D6SD = 1; else D6SD = 0;
	if (data[5]&SEG_E)	D6SE = 1; else D6SE = 0;
	if (data[5]&SEG_F)	D6SF = 1; else D6SF = 0;
	if (data[5]&SEG_G)	D6SG = 1; else D6SG = 0;

	if (data[6]&SEG_A)	D7SA = 1; else D7SA = 0;
	if (data[6]&SEG_B)	D7SB = 1; else D7SB = 0;
	if (data[6]&SEG_C)	D7SC = 1; else D7SC = 0;
	if (data[6]&SEG_D)	D7SD = 1; else D7SD = 0;
	if (data[6]&SEG_E)	D7SE = 1; else D7SE = 0;
	if (data[6]&SEG_F)	D7SF = 1; else D7SF = 0;
	if (data[6]&SEG_G)	D7SG = 1; else D7SG = 0;

	if (data[7]&SEG_A)	D8SA = 1; else D8SA = 0;
	if (data[7]&SEG_B)	D8SB = 1; else D8SB = 0;
	if (data[7]&SEG_C)	D8SC = 1; else D8SC = 0;
	if (data[7]&SEG_D)	D8SD = 1; else D8SD = 0;
	if (data[7]&SEG_E)	D8SE = 1; else D8SE = 0;
	if (data[7]&SEG_F)	D8SF = 1; else D8SF = 0;
	if (data[7]&SEG_G)	D8SG = 1; else D8SG = 0;
	
	
	}


void set_segs (unsigned int data)
	{
	LCDDATA0 = data;
	LCDDATA1 = data;
	LCDDATA2 = data;
	LCDDATA3 = data;
	LCDDATA4 = data;
	LCDDATA5 = data;
	LCDDATA6 = data;
	LCDDATA7 = data;
	LCDDATA8 = data;
	LCDDATA9 = data;
	LCDDATA10 = data;
	LCDDATA11 = data;
	LCDDATA12 = data;
	LCDDATA13 = data;
	LCDDATA14 = data;
	LCDDATA15 = data;	
	}