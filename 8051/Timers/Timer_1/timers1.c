#include <reg51.h>
int main()
{
	TMOD=0x10;
	TH1=0x3C;
	TL1=0xAF;
	TR1=1;
	while(TF1==0);
	TF1=0;
}