#include<reg52.h>
sbit rs = P1^0;
sbit en = P1^2;
sbit rw = P1^1;
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcddisplay(unsigned char *);
void delay();
void main()
{
	P2=0X00;
	while(1)
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
void delay()
{
	int i;
	for(i=0;i<=10000;i++);
}