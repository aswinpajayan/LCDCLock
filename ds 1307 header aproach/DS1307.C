
#include "includes.h"

void set_time(void)
{
	i2c_start();
	i2c_write_byte(0xD0);
	i2c_write_byte(0x00);
	i2c_write_byte(second);
	i2c_write_byte(minute);
	i2c_write_byte(hour);
	i2c_stop();
	return;
}
void set_date(void)
{
	i2c_start();
	i2c_write_byte(0xD0);
	i2c_write_byte(0x04);
	i2c_write_byte(date);	
	i2c_stop();
	return;
}	
void set_day(void)
{
	i2c_start();
	i2c_write_byte(0xD0);
	i2c_write_byte(0x03);
	i2c_write_byte(day);	
	i2c_stop();
}
	
void set_year(void)
{
	i2c_start();
	i2c_write_byte(0xD0);
	i2c_write_byte(0x06);
	i2c_write_byte(year);	
	
	i2c_stop();
	return;
}
void set_month(void)
{
	i2c_start();
	i2c_write_byte(0xD0);
	i2c_write_byte(0x05);
	i2c_write_byte(month);	
	i2c_stop();
	return;
}
void get_time(void)
{
		i2c_start();
		i2c_write_byte(0xD0);
		i2c_write_byte(0x00);
		i2c_repstart();
		i2c_write_byte(0xD1);
		second=i2c_read_byte();
		i2c_send_ack();
		minute=i2c_read_byte();
		i2c_send_ack();
		hour=i2c_read_byte();
		i2c_send_nack();
		i2c_stop();
	}
void get_date(void)
{
		i2c_start();
		i2c_write_byte(0xD0);
		i2c_write_byte(0x04);
		i2c_repstart();
		i2c_write_byte(0xD1);
		date=i2c_read_byte();
		i2c_send_ack();
		month=i2c_read_byte();
		i2c_send_ack();
		year=i2c_read_byte();
		i2c_send_nack();
		i2c_stop();
		return;
	}	
void get_day(void)
{
		i2c_start();
		i2c_write_byte(0xD0);
		i2c_write_byte(0x03);
		i2c_repstart();
		i2c_write_byte(0xD1);
		day=i2c_read_byte();
		i2c_send_nack();
		i2c_stop();
		return;
}

		
	