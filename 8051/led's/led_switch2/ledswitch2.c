#include <reg51.h>
sbit led1=P2^0;
sbit sw1=P2^7;
bit flag;
void main()
{
	int i;
	flag=0;
	led1=0;
	sw1=1;
	while(1)
	{
		if(sw1==0)
		{
			flag=~flag;
			while(sw1==0);
			{
				if(flag==0)
					led1=0;
				else
					led1=1;
			}
		}
	}
}
