#ifndef _LCD4_H
#define _LCD4_H


#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RB1
#define RW RB2
#define E RB4
unsigned char temp;
void lcd_write_command(unsigned char);
void lcd_init(void);
void lcd_write_byte(unsigned char);

#endif

