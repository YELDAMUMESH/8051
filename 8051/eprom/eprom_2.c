#include<reg51.h>
#include<intrins.h> // supports nop function
sbit sda=P2^0;
sbit scl=P2^1;
void start();
void write(unsigned char);
void ackcheck();
void stop();
void main()
{
	start();
	write(0XA0);
	ackcheck();
	write(0X06); //ALL LED'S ON
	ackcheck();
	write('a'); //ALL LED'S OFF
	ackcheck();
	stop();
	while(1);
}
//function defination
void start()
{
	scl=1;
	sda=1;
	nop(); // no operation
	nop(); //uc takes 1 usec delay
	sda=0;
}

void write(unsigned char val)
{
	unsigned char v1,v2;
	v1=val;
	for(v2=0;v2<8;v2++)
	{
		sda=v1&0x80;
		scl=1;
	  nop(); // no operation
	  nop(); //uc takes 1 usec delay
		scl=0;
		v1=v1<<1; //left shift operation
	}
}

void ackcheck()
{
	bit c;
  sda=1;
  c=sda;
  scl=1;
 	nop(); // no operation
	nop(); //uc takes 1 usec delay
	scl=0;
	 if(c==1);
	{
		stop();
		while(1); // holding compliation
	}
}

void stop()
{
	scl=1;
	sda=0;
	nop(); // no operation
	nop(); //uc takes 1 usec delay
  scl=1;
}