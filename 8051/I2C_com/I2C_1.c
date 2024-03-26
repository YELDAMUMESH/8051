#include<reg51.h>
#include<intrins.h> // supports nop function
sbit sda=P2^0;
sbit scl=P2^1;
void start();
void write(unsigned char);
void ackcheck();
void stop();
void delay();
void main()
{
	start();
	write(0X40);
	ackcheck();
	while(1)
	{
		write(0X55); //ALL LED'S ON
		ackcheck();
		delay();
		write(0Xaa); //ALL LED'S OFF
		ackcheck();
		delay();
	}
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

void delay()
{
	unsigned char v3;
	for(v3=0;v3<6000;v3++);
}