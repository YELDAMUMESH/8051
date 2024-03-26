#include <reg51.h>
sbit led1=P1^0;
sbit led2=P1^1;
sbit sw1=P1^2;
sbit sw2=P1^3;
int main()
{
while(1)
{
	if(sw1==0)
	{
		led1=0;
	}
	else
		led1=1;
	
	
	if(sw2==0)
	{
		led2=0;
	}
	else
		led2=1;
	
}
}