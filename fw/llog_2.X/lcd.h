void lcd_write_segments (unsigned char * data);
void lcd_write_chars (char * data, unsigned char specials);
void set_segs (unsigned int data);


#define	SEG_A	0x01
#define	SEG_B	0x02
#define	SEG_C	0x04
#define	SEG_D	0x08
#define	SEG_E	0x10
#define	SEG_F	0x20
#define	SEG_G	0x40

#define	LCD_P1	0x01
#define	LCD_P2	0x02
#define	LCD_X	0x04


#define     D1SA    LCDDATA12bits.S05C3
#define     D1SB    LCDDATA0bits.S05C0
#define     D1SC    LCDDATA8bits.S05C2
#define     D1SD    LCDDATA4bits.S04C1
#define     D1SE    LCDDATA8bits.S04C2
#define     D1SF    LCDDATA12bits.S04C3
#define     D1SG    LCDDATA0bits.S04C0

#define     D2SA    LCDDATA12bits.S03C3
#define     D2SB    LCDDATA0bits.S03C0
#define     D2SC    LCDDATA8bits.S03C2
#define     D2SD    LCDDATA4bits.S02C1
#define     D2SE    LCDDATA8bits.S02C2
#define     D2SF    LCDDATA12bits.S02C3
#define     D2SG    LCDDATA0bits.S02C0

#define     D3SA    LCDDATA12bits.S01C3
#define     D3SB    LCDDATA0bits.S01C0
#define     D3SC    LCDDATA8bits.S01C2
#define     D3SD    LCDDATA4bits.S00C1
#define     D3SE    LCDDATA8bits.S00C2
#define     D3SF    LCDDATA12bits.S00C3
#define     D3SG    LCDDATA0bits.S00C0

#define     D4SA    LCDDATA13bits.S20C3
#define     D4SB    LCDDATA1bits.S20C0
#define     D4SC    LCDDATA9bits.S20C2
#define     D4SD    LCDDATA5bits.S17C1
#define     D4SE    LCDDATA9bits.S17C2
#define     D4SF    LCDDATA13bits.S17C3
#define     D4SG    LCDDATA1bits.S17C0

#define     D5SA    LCDDATA15bits.S48C3
#define     D5SB    LCDDATA3bits.S48C0
#define     D5SC    LCDDATA11bits.S48C2
#define     D5SD    LCDDATA5bits.S27C1
#define     D5SE    LCDDATA9bits.S27C2
#define     D5SF    LCDDATA13bits.S27C3
#define     D5SG    LCDDATA1bits.S27C0

#define     D6SA    LCDDATA13bits.S26C3
#define     D6SB    LCDDATA1bits.S26C0
#define     D6SC    LCDDATA9bits.S26C2
#define     D6SD    LCDDATA5bits.S25C1
#define     D6SE    LCDDATA9bits.S25C2
#define     D6SF    LCDDATA13bits.S25C3
#define     D6SG    LCDDATA1bits.S25C0

#define     D7SA    LCDDATA13bits.S24C3
#define     D7SB    LCDDATA1bits.S24C0
#define     D7SC    LCDDATA9bits.S24C2
#define     D7SD    LCDDATA5bits.S23C1
#define     D7SE    LCDDATA9bits.S23C2
#define     D7SF    LCDDATA13bits.S23C3
#define     D7SG    LCDDATA1bits.S23C0

#define     D8SA    LCDDATA13bits.S22C3
#define     D8SB    LCDDATA1bits.S22C0
#define     D8SC    LCDDATA9bits.S22C2
#define     D8SD    LCDDATA5bits.S21C1
#define     D8SE    LCDDATA9bits.S21C2
#define     D8SF    LCDDATA13bits.S21C3
#define     D8SG    LCDDATA1bits.S21C0

#define     COL1    LCDDATA4bits.S01C1
#define     COL2    LCDDATA7bits.S48C1
#define     SYMB    LCDDATA5bits.S22C1
