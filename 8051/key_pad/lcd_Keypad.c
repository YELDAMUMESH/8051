#include <reg51.h>
#include "lcdheader.h"

sbit r0 = P1^0;
sbit r1 = P1^1;
sbit r2 = P1^2;
sbit r3 = P1^3;

sbit c0 = P1^4;
sbit c1 = P1^5;
sbit c2 = P1^6;
sbit c3 = P1^7;

char keypad[4][4] = {'F','B','7','3',  'E','A','6','2',   'D','9','5','1',  'C','8','4','0'};
void main()
{
	int i,j;
	lcdinit();
	lcdcmd(0x80);
	lcdprint("KeypadTest :");
	while(1)
	{
	r0 = r1 = r2 = r3 = 1;
	c0 = c1 = c2 = c3 = 0;
	while(r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1);
	if(r0 == 0) i=0;
	if(r1 == 0) i=1;
	if(r2 == 0) i=2;
	if(r3 == 0) i=3;
	
	r0 = r1 = r2 = r3 = 0;
	c0 = c1 = c2 = c3 = 1;
	while(c0 == 1 && c1 == 1 && c2 == 1 && c3 == 1);
	if(c0 == 0) j=0;
	if(c1 == 0) j=1;
	if(c2 == 0) j=2;
	if(c3 == 0) j=3;
	
		lcdcmd(0xC0);
		lcddata(keypad[i][j]);
	}
	
}