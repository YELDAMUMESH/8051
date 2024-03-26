#include<reg51.h>
void main()
{
unsigned char v;
SCON=0x50;
TMOD=0x20;
TH1=-3;
TR1=1;
while(RI==0);
P1=SBUF;
v=SBUF;
SBUF=v;
while(TI==0);
TI=0;
RI=0;
TR1=0;
}