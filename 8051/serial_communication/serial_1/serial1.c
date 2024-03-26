#include<reg51.h>
void main()
{
	SCON=0X40;
	TMOD=0X20;
	TH1=-3;
	TR1=1;
	SBUF='U';
while(TI==0);
TI=0;
RI=0;
while();
}	
	