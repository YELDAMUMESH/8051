#include<reg51.h>
#include<intrins.h>
sbit sda=P3^1;
sbit scl=P3^0;
//I2C BUS LINES
sbit rs = P1^0;
sbit en = P1^2;
sbit rw = P1^1;
//lcd ports
sbit s1 = P1^3;
sbit s2 = P1^4;
sbit s3 = P1^5;
sbit s4 = P1^7;
//switch ports
sbit led = P1^6;
//led port;
void start();
void stop();
void ackcheck();
void write(unsigned char);
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcddisplay(unsigned char *);
void lcdconv(unsigned char);
void description();
void delay();
void main()
{
	unsigned char x,y,z;
	s1=s2=s3=s4=1;
	led = 0;
	P2=0X00;
	description();
	while(1)
	{
		if(s1==0)
			{
				led = 1;
				lcdcmd(0x01);
				lcdcmd(0x0c);
				lcdcmd(0xc0);
				lcddisplay("PARTY     @        1");
				x=x+1;
				led=0;
				start();
				write(0xA0);
				ackcheck();
				write(0x06);
				ackcheck();
				write(0x01);
				ackcheck();
				write(x);
				ackcheck();
				stop();
				lcdcmd(0x01);
				lcdcmd(0x0c);
				lcdcmd(0x80);
				lcddisplay("THANK YOU");
				description();
			}
		if(s2==0)
			{
				led = 1;
				lcdcmd(0x01);
				lcdcmd(0x0c);
				lcdcmd(0x94);
				lcddisplay("PARTY     #        2");
				y=y+1;
				led=0;
				start();
				write(0xA0);
				ackcheck();
				write(0x06);
				ackcheck();
				write(0x02);
				ackcheck();
				write(y);
				ackcheck();
				stop();
				lcdcmd(0x01);
				lcdcmd(0x0c);
				lcdcmd(0x80);
				lcddisplay("THANK YOU");
				description();
			}
		if(s3==0)
			{
				led = 1;
				lcdcmd(0x01);
			  lcdcmd(0x0c);
				lcdcmd(0xd4);
				lcddisplay("PARTY     $        3");
				z=z+1;
				led=0;
				start();
				write(0xA0);
				ackcheck();
				write(0x06);
				ackcheck();
				write(0x03);
				ackcheck();
				write(z);
				ackcheck();
				stop();
				lcdcmd(0x01);
				lcdcmd(0x0c);
				lcdcmd(0x80);
				lcddisplay("THANK YOU");
				description();
			}
			if(s4==0)
			{
				lcdcmd(0x01);
			  lcdcmd(0x0c);
				lcdcmd(0x80);
				lcddisplay("STATISTICS");
				lcdcmd(0xc0);
				lcdcmd(0x0c);
				lcddisplay("@         :       ");
				lcdcmd(0xd2);
				lcdconv(x);
				lcdcmd(0x94);
				lcddisplay("#         :       ");
				lcdcmd(0xa6);
				lcdconv(y);
				lcdcmd(0xd4);
				lcddisplay("$         :       ");
				lcdcmd(0xe6);
				lcdconv(z);
			}
	}
}
void lcddata(unsigned char dat)
{
	P2 = dat;
	rs = 1;
	rw = 0;
	en = 1;
	delay();
	en = 0;
}
void lcdcmd(unsigned char val)
{
	P2 = val;
	rs = 0;
	rw=0;
	en = 1;
	delay();
	en = 0;
}
void lcddisplay(char *c)
{
	while( *c!= '\0')
	{
		lcddata(*c);
	  c++;
	}
}
void description()
{
	lcdcmd(0x38);//activate all crystals
	lcdcmd(0x01);//clear screen
	lcdcmd(0x06);//forward increment
	lcdcmd(0x0c);//cursor on and blinking
	lcddisplay("WELCOME");
	lcdcmd(0x01);//clear screen
	lcddisplay("ELECTRONIC VOTING...");
	lcdcmd(0x01);//clear screen
	lcdcmd(0x80);//shift cursor to the right position
	lcddisplay("REGISTER FINGERPRINT");
	lcdcmd(0x01);//clear screen
	lcdcmd(0x80);//shift cursor to the right position
	lcddisplay("REGISTRATION SUCESS");
	lcdcmd(0x01);
	lcdcmd(0x80);//shift cursor to the right position
	lcddisplay("SELECT TO VOTE");
	lcdcmd(0xc0);
	lcdcmd(0x0c);
	lcddisplay("PARTY     @        1");
	lcdcmd(0x94);
	lcddisplay("PARTY     #        2");
	lcdcmd(0xd4);
	lcddisplay("PARTY     $        3");
}
void lcdconv(unsigned char num)
{
	unsigned char q,w;
	q=num/10;
	w=num%10;
	q=q+0x30;
	w=w+0x30;
	lcddata(q);
	lcddata(w);
}
void start()
{
	scl=1;
	sda=1;
	nop();
	nop();
	sda=0;
	scl=0;
}
void write(unsigned char val)
{
	unsigned char v1,v2;
	v1=val;
	for(v2=0;v2<8;v2++)
	{
		sda=v1&0x80;
		scl=1;
		nop();
		nop();
		scl=0;
		v1=v1<<1;
	}
}
void ackcheck()
{
	bit c;
	sda=1;
	c=sda;
	scl=1;
	nop();
	nop();
	scl=0;
if(c==1)
{
	stop();
	while(1);
}
}
void stop()
{
	scl=1;
	sda=0;
	nop();
	nop();
	sda=1;
	scl=0;
}
void delay()
{
	int i;
	for(i=0;i<=10000;i++);
}