#include <reg51.h>
int i,j;
void delay(unsigned int t)
{
	for(i=0;i<t;i++)
	for(j=0;j<1000;j++);
}
	sbit led1=P1^0;
	sbit led2=P1^1;
	sbit led3=P1^2;
void main()
{

	while(1)
	{
		led1=0xFF;
		led2=0x00;
		led3=0x00;
		delay(500);
		
		led1=0x00;
		led2=0xFF;
		led3=0x00;
		delay(500);
		
		led1=0x00;
		led2=0x00;
		led3=0xFF;
		delay(500);
	}
}
	