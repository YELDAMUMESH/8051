#include<reg51.h>
sbit led=P2^0;
void delay(unsigned int);
void main()
{
	while(1)
	{
		led=0;
		delay(1000);
		led=1;
		delay(1000);
	}
}


//function for delay

void delay(unsigned int i)
{
	int count=0;
	for(count=0;count<20;count++)
	{
		TMOD=0x10;
		TH1=0xFC;
		TL1=0x17;
		TR1=1;
		while(TF1==0);
		TF1=0;
		TR1=0;
	}
}
		