#include<reg51.h>
void main()
{
unsigned char person[]={"Name,Address,Pin,Phno"};
unsigned char v;
SCON=0X40;
TMOD=0x20;
TH1=-4;
TR1=1;
for(v=0;person[v]!='\0';v++)
{
	SBUF=person[v];
	while(TI==0);
	TI=0;
}
TR1=0;
}
	
