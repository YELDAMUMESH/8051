#include <reg51.h>
int i,j;
void delay(unsigned int t)
{
	for(i=0;i<t;i++)
	for(j=0;j<1000;j++);
}
sbit led1=P1^0;
sbit led2=P1^1;
void main()
{
	int i;
	while(1)
	{
		led1=1;
		led2=0;
    delay(100);
    led1=0;
    led2=1;
    delay(100);
	}
}	