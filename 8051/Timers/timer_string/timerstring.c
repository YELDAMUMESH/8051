#include<reg51.h>
serialprint(char*);
void main()
{
	TMOD=0X20;
	SCON=0X50;
	TH1=0XFD;//for 9600 baud rate
	TR1=1;
	serialprint("Hello");
}
serialprint(char *str)
{
	while(*str!='\0')
	{
		SBUF=*str;
		while(TI==0);
		TI=0;
		*str++;
	}
}	