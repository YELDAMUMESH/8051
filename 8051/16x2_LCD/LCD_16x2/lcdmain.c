#include <reg51.h>
#include "lcdheader.h"

sbit sw1 = P1^0;
sbit sw2 = P1^1;
sbit sw3 = P1^2;
sbit sw4 = P1^3;

sbit led1 = P1^4;
sbit led2 = P1^5;
sbit led3 = P1^6;
sbit led4 = P1^7;


void main()
{
	bit flag1,flag2,flag3,flag4;
	flag1 = flag2 =flag3 =flag4 = 0;
	sw1 = sw2 = sw3 = sw4 = 1;
	led1 = led2 = led3 = led4 = 0;
	lcdinit();
	lcdcmd(0x80);
	lcdprint("LED TEST");
	while(1)
	{
	if(sw1 == 0)
		flag1 = ~flag1;
	if(sw2 == 0)
		flag2 = ~flag2;
	if(sw3 == 0)
		flag3 = ~flag3;
	if(sw4 == 0)
		flag4 = ~flag4;
	if(flag1 == 0)
		led1 = 0;
	else 
		led1 = 1;
	if(flag2 == 0)
		led2 = 0;
	else 
		led2 = 1;
	if(flag3 == 0)
		led3 = 0;
	else 
		led3 = 1;
	if(flag4 == 0)
		led4 = 0;
	else 
		led4 = 1;
	
	lcdcmd(0x80);
	if(flag1 == 1)
		lcdprint("D1:ON ");
	else
		lcdprint("D1:OFF");
	lcdcmd(0x88);
	if(flag2 == 1)
		lcdprint("D2:ON ");
	else
		lcdprint("D2:OFF");
	lcdcmd(0xC0);
	if(flag3 == 1)
		lcdprint("D3:ON ");
	else
		lcdprint("D3:OFF");
	lcdcmd(0xC8);
  if(flag4 == 1)
		lcdprint("D4:ON ");
	else
		lcdprint("D4:OFF");	
  }
}



