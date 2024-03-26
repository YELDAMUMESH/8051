#include<reg51.h>
#include <stdlib.h>
#include<string.h>

sbit rs = P1^2;
sbit rw = P1^3;
sbit en = P1^4;
void lcdcmd(unsigned char x);
void lcddat(unsigned char x);
void lcddis(unsigned char *x);
const char a1[12] ={"215630158024"};
const char a2[12] ={"123456789101"};
const char a3[12] ={"101987654321"};
char a[12];
unsigned char v1,v2;
void main()
{
	lcdcmd(0x38);	// Initialization of 16X2 LCD in 8bit mode 
  lcdcmd(0x0c); //Display ON Cursor OFF 
  lcdcmd(0x06); //Auto Increment cursor 
  lcdcmd(0x0F); 
	lcdcmd(0x80);
	lcddis("ENTER AADHAR NO:");
	lcdcmd(0xc0);
	SCON = 0X50;
  TMOD = 0X20;
	TH1  = -3;
	TR1  = 1;
	while(1)
	{ 
		for(v1=0;v1<12;v1++)
		{
			while(RI==0);
			a[v1]=SBUF;
			v2 = SBUF;
			SBUF = v2;
			while(TI==0);
			TI = 0;
			RI = 0;
			lcddat(a[v1]);
		}
	if(strcmp(a1,a)==0)
		{
			lcdcmd(0x01);
			lcdcmd(0x80);
			lcddis("nynita");
			lcdcmd(0xc0);
			lcddis("D.O.B : 27/11/2001");
			lcdcmd(0x94);
			lcddis("8888444412");
			lcdcmd(0xd4);
			lcddis("Female");
		}
   else if(strcmp(a2,a)==0)
		{
			lcdcmd(0x01);
			lcdcmd(0x80);
			lcddis("RAM");
			lcdcmd(0xc0);
			lcddis("D.O.B : 7/11/1995");
			lcdcmd(0x94);
			lcddis("8844441288");
			lcdcmd(0xd4);
			lcddis("Male");
		}
	 else if(strcmp(a3,a)==0)
		{
		  lcdcmd(0x01);
			lcdcmd(0x80);
			lcddis("Ramesh");
			lcdcmd(0xc0);
			lcddis("D.O.B : 20/1/2018");
			lcdcmd(0x94);
			lcddis("8888441424");
			lcdcmd(0xd4);
			lcddis("Male");
		}
		else 
		{
			lcdcmd(0x01);
			//lcdcmd(0x80);
			lcddis("Invaild");
		}
	}
}
void lcddis(unsigned char *c)
{ 
	unsigned char w;
	for(w=0;c[w]!='\0';w++)
	//while(*c);
	{
		lcddat(c[w]);
		//lcddat(*c++);
		//*c++;
	}
}
void lcdcmd(unsigned char x)
{
	int i;
	P2 = x;
	rs = 0;
	rw = 0;
	en = 1;
	for(i=0;i<5000;i++);
	en = 0;
}
void lcddat(unsigned char x)
{
	int i;
	P2 = x;
	rs = 1;
	rw = 0;
	en = 1;
	for(i=0;i<5000;i++);
	en = 0;
}