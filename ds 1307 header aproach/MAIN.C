#include<pic.h>
#include "includes.h"
__CONFIG(HS&WDTDIS&BORDIS&LVPDIS);
void main()
{
	TRISB=0X00;
	TRISD=0x00;
	i2c_init();
	lcd_init();
	__delay_ms(1);
	second = 0x00;
	minute = 0x30;
	hour = 0x22;
	set_time();
	date = 0x14;
	set_date();
	month = 0x12;
	set_month();
	year = 0x13;
	set_year();
	day = 0x04;
	set_day();
		while(1)
	{
	       display_time();
	       if(second%2)
		display_date();
		else
		 display_day();
	

		
	}
}