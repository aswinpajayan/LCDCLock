#include "includes.h"
void i2c_init(void)
{
		SSPCON2=0X00;
	
		SSPIF=0;
		SSPADD = ((_XTAL_FREQ)/4000)/I2C_SPEED-1;
		SSPSTAT=0X80;
		SSPCON = 0X28;//ADD SSPIF =0 IF THIS CODE FAILS 
		return;
		
		
}
void i2c_start(void)
{
	SEN = 1;
	while(!SSPIF);
	SSPIF=0;
	return;
}
void i2c_repstart(void)
{
	RSEN = 1; 
	while(!SSPIF);
	SSPIF = 0;
	return;
}
void i2c_stop(void)
{
	PEN = 1; 
	while(!SSPIF);
	SSPIF =0 ;
	return;
}
void i2c_send_ack(void)
{
	ACKDT = 0;
	ACKEN = 1; 
	while(!SSPIF);
	SSPIF =0;
	return;
}
void i2c_send_nack(void)
{
	ACKDT =1;//Not Acknowledged
	ACKEN = 1;
	while(!SSPIF);
	SSPIF =0;
	return;
}
bit i2c_write_byte(unsigned char byte)
{
	SSPBUF = byte;
	while(!SSPIF);
	SSPIF = 0; 
	return ACKSTAT;
}
unsigned char i2c_read_byte(void)
{
	RCEN =1;
	while(!SSPIF);
	SSPIF = 0;
	return SSPBUF;
}
