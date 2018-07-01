#ifndef _12C_H
#define _I2C_H


#define SDA RC4
#define SCK RC3
#define I2C_SPEED 100  //in khz

void i2c_init(void);
void i2c_start(void);
void i2c_repstart(void);
void i2c_stop(void);
void i2c_send_ack(void);
void i2c_send_nack(void);
bit i2c_write_byte(unsigned char);
unsigned char i2c_read_byte(void);

#endif