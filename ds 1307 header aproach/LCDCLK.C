#include "includes.h"
#define ascii 48

void display_time(void)
{
        	
        	get_time();
        	lcd_write_command(0x83);//moves cursor to [0][3]
		temp = hour/16;//displaying tens position
		temp+= ascii;
		lcd_write_byte(temp);
		temp = hour%16;//displaying ones position
		temp+= ascii;
		lcd_write_byte(temp);
		lcd_write_byte(':');
		
		temp = minute/16;//displaying tens position
		temp+= ascii;
		lcd_write_byte(temp);
		temp = minute%16;//displaying ones position
		temp+= ascii;
		lcd_write_byte(temp);
		lcd_write_byte(':');
		
		temp = second/16;
		temp+= ascii;
		lcd_write_byte(temp);
		temp = second%16;
		temp+= ascii;
		lcd_write_byte(temp);
		return;
	
		
}
		
void display_date(void)
{
	
        	get_date();
        	lcd_write_command(0xc3);//moves cursor to [1][3]
		temp = date/16;//displaying tens position
		temp+= ascii;
		lcd_write_byte(temp);
		temp = date%16;//displaying ones position
		temp+= ascii;
		lcd_write_byte(temp);
		lcd_write_byte('/');
		
		temp = month/16;//displaying tens position
		temp+= ascii;
		lcd_write_byte(temp);
		temp = month%16;//displaying ones position
		temp+= ascii;
		lcd_write_byte(temp);
		lcd_write_byte('/');
		
		temp = year/16;
		temp+= ascii;
		lcd_write_byte(temp);
		temp = year%16;
		temp+= ascii;
		lcd_write_byte(temp);
		lcd_write_byte(' ');
		return;
		
}
void display_day(void)
{


	get_day();
	lcd_write_command(0xC3);//cursor pos to [1][3]
	switch(day)
	{
		case 01:
		{
			lcd_write_byte(' ');
			lcd_write_byte('S');
			lcd_write_byte('u');
			lcd_write_byte('n');
			break;
		}
		case 02:
		{
		
			lcd_write_byte(' ');
			lcd_write_byte('M');
			lcd_write_byte('o');
			lcd_write_byte('n');
			break;
		}
		case 03:
		{
		
			lcd_write_byte('T');
			lcd_write_byte('u');
			lcd_write_byte('e');
			lcd_write_byte('s');
			break;
		}
		case 04:
		{	
			lcd_write_byte('W');
			lcd_write_byte('e');
			lcd_write_byte('d');
			lcd_write_byte('n');
			lcd_write_byte('e');
			lcd_write_byte('s');
			break;
		}
		case 05:
		{
		       lcd_write_byte('T');
			lcd_write_byte('h');
			lcd_write_byte('u');
			lcd_write_byte('r');
			lcd_write_byte('s');
			break;
		}
		case 06:
		{
			lcd_write_byte(' ');
			lcd_write_byte('F');
			lcd_write_byte('r');
			lcd_write_byte('i');
			break;
		}
		case 07:
		{
			lcd_write_command(0xC2);
			lcd_write_byte('S');
			lcd_write_byte('a');
			lcd_write_byte('t');
			lcd_write_byte('u');
			lcd_write_byte('r');
			break;
		}
		default :
		{
		break;
		}
	
	}
		lcd_write_byte('d');
		lcd_write_byte('a');
		lcd_write_byte('y');	
		lcd_write_byte(' ');	
	return;
}