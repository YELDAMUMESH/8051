#include <REGX51.H>
sbit rs=P3^6;
sbit en=P3^7;
sbit sw1=P1^0;
sbit sw2=P1^1;
sbit sw3=P1^2;
sbit sw4=P1^3;
sbit led1=P1^4;
sbit led2=P1^5;
sbit led3=P1^6;
sbit led4=P1^7;
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
	
	sw1=1,sw2=1,sw3=1,sw4=1;
	led1=led2=led3=led4=0;
	while(1);
	
if(sw1==1){
	led1=1;
lcdprint("D1:ON");
}
else{
	led1=0;
	lcdprint("D1:OFF");
}

if(sw2==1){
	led2=1;
	lcdprint("D2:ON");
}
else{
	led2=0;
	lcdprint("D2:OFF");
}

if(sw3==1){
	led3=1;
	lcdprint("D3:ON");
}
else{
	led3=0;
	lcdprint("D3:OFF");
}

if(sw4==1){
	led4=1;
	lcdprint("D4:ON");
}
else{
	led4=0;
	lcdprint("D4:OFF");
}

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