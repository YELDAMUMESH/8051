#include <reg51.h>
sbit led=P2^0;
sbit sw1=P2^1;
sbit sw2=P2^2;
void main()
{
	while(1)
	{
	if (sw1==0&&sw2==0)
	{
		led=1;
	}
	else
		led=0;
}
}

	