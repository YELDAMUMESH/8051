#include<reg51.h>
sbit gled=P1^0;
sbit rled=P1^1;
sbit rs=P1^2;
sbit rw=P1^3;
sbit en=P1^4;
//lcd control pins
void lcdcmd(unsigned char x);
void lcddata(unsigned char x);
delay(int);
void lcddisplay(unsigned char *x);
unsigned char password[4],v1;

void main()
{
	lcdcmd(0x38);
	lcdcmd(0x0c);
	lcdcmd(0x06);
	lcdcmd(0x0F);
	lcdcmd(0x80);
	lcddisplay("enter password");
	lcdcmd(0xC0);
	SCON=0x50;
	TMOD=0x20;
	TH1= -3;
	TR1=1;
	gled=rled=0;
	while(1)
	{
		for(v1=0;v1<4;v1++)
		{
			while(RI==0);
			password[v1]=SBUF;
			RI=0;
			lcddata(password[v1]);
		}
		if(password[0]=='2'&&password[1]=='0'&&password[2]=='0'&&password[3]=='1')
		{
			gled=1;
			rled=0;
			lcdcmd(0x01);
			lcddisplay("matched");
		}
		else
		{
			rled=1;
			gled=0;
			lcdcmd(0x01);
			lcddisplay("password wrong");
		}
	}
}
void lcdcmd(unsigned char x)
{
	int i;
	P2=x;
	rs=0;
	rw=0;
	en=1;
	for(i=0;i<500;i++);
	en=0;
}
void lcddisplay(unsigned char *s)
{
	unsigned char w;
	for(w=0;s[w]!='\0';w++)
	{
		lcddata(s[w]);
	}
}
void lcddata(unsigned char dat)
{
	int i;
	P2=dat;
	rs=1;
	rw=0;
	en=1;
	for(i=0;i<500;i++);
	en=0;
}
delay (int k)
{
	int i,j;
	for(i=0;i<k;i++)
	for(j=0;j<1275;j++);
}
	
			


