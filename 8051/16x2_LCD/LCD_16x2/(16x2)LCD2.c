//LCD display using functions
#include <reg51.h>
//control pins
sbit rs=P3^6;
sbit en=P3^7;
sbit sw=P3^5;
lcdcmd(char);
lcddata(char);
//data pins are connected to P2
void main()
{
	lcdcmd(0x38);
	lcdcmd(0x0C);
	lcdcmd(0x06);
	lcdcmd(0x01);
	//first line address
	lcdcmd(0x80);
	lcddata('N');
	lcddata('A');
	lcddata('M');
	lcddata('S');
	lcddata('T');
	lcddata('H');
	lcddata('E');
	
	
	//second line address
	lcdcmd(0xC0);
	lcddata('B');
	lcddata('H');
	lcddata('A');
	lcddata('I');
	while(1);
	

}


//functions

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

