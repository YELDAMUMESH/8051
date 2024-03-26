#include <REGX51.H>
sbit rs=P3^6;
sbit en=P3^7;
//data pins connected to the P2
lcdcmd(char);
lcddata(char);
lcdprint(char*);
//char x[10]="hello world";


void main()
{
	lcdcmd(0x38);
	lcdcmd(0x0c);
	lcdcmd(0x06);
	lcdcmd(0x01);
	lcdcmd(0x80);

lcdprint("Ignite embedded");
lcdcmd(0xc0);
lcdprint("Ameerpet");
while(1);
}
lcdprint(char *c)
{
	while(*c!='\0')
	{
		lcddata(*c);
		*c++;
	}
}

lcdcmd(char x)
{
	int i;
	P2=x;
	rs=0;
	en=1;
	for(i=0;i<5000;i++)
	en=0;
}

lcddata(char x)
{
	int i;
	P2=x;
	rs=1;
	en=1;
	for(i=0;i<5000;i++)
	en=0;
}
	