#include<reg51.h>
void main()
{
	TMOD=0X20;
	SCON=0X50;
	TH1=0XFD;
	TR1=1;
	while(1)
	{
		SBUF='A';
		while(TI==0);
		TI=0;
	}
}