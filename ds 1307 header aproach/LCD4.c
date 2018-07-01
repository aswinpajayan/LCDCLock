#include "includes.h"
void lcd_init(void)
{
	E=0;
	__delay_us(15);//check by reducing the delay
	lcd_write_command(0x03);
	lcd_write_command(0x03);
	lcd_write_command(0x03);
	lcd_write_command(0x02);
	lcd_write_command(0x28);
	lcd_write_command(0x0C);
	lcd_write_command(0x06);
	return;
}
void lcd_write_command(unsigned char command)
{

	E=0;
	temp=command;
	__delay_us(1);
	RS=0;
	RW=0;
	__delay_us(1);
	E=1;
	__delay_us(1);
	temp&=0xF0;
	PORTD&=0x0F;
	PORTD|=temp;
	__delay_us(1);
	E=0;
	__delay_us(1);

	temp=command;
	__delay_us(1);
	E=1;
	__delay_us(1);
	temp<<=4;
	temp&=0xF0;
	PORTD&=0x0F;
	PORTD|=temp;
	__delay_us(1);
	E=0;
	__delay_us(2);
	return;

}
void lcd_write_byte(unsigned char byte)
{

	E=0;
	temp=byte;
	__delay_us(1);
	RS=1;
	RW=0;
	__delay_us(1);
	E=1;
	__delay_us(1);
	temp&=0xF0;
	PORTD&=0x0F;
	PORTD|=temp;
	__delay_us(1);
	E=0;
	__delay_us(1);

	temp=byte;
	__delay_us(1);
	E=1;
	__delay_us(1);
	temp<<=4;
	temp&=0xF0;
	PORTD&=0x0F;
	PORTD|=temp;
	__delay_us(1);
	E=0;
	__delay_us(2);
	return;

}
void lcd_write_word(char word[16])
{
	
	char i,data;
	for(i=0;i<16;i++)
	{
		data=(int)word[i];
		lcd_write_byte(data);
	}
	return;
}		