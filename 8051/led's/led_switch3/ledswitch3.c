#include <reg51.h>
sbit led1=P2^0;
sbit sw1=P2^1;
void main()
{
	sw1=1;
	led1=0;
	while(1)
	{
		if(sw1==0)
			led1=1;
		else
			led1=0;
	}
}