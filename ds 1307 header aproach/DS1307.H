
#ifndef _DS1307_H
#define _DS1307_H



unsigned char second,minute,hour,date,day,month,year;
char temp;


void set_time(void);
void set_date(void);
void set_day(void);
void set_year(void);
void get_time(void);
void get_date(void);
void set_month(void);
void get_day(void);


#endif


