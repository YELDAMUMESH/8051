#include <reg51.h>
sbit led=P1^5;
void main()
{
	int i;
	while(1)
	{
		led =1;
		for(i=0;i<5000;i++)
		{
			;
		}
		led=0;
		for(i=0;i<5000;i++)
		{
			;
		}
	}
	
}

		
	