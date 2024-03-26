#include <reg51.h>
int main()
{
	int i;
while(1)
P2=0X06;
for(i=0;i<200;i++);
P2=0X5B;
for(i=0;i<200;i++);
P2=0X4F;
for(i=0;i<200;i++);
P2=0X66;
for(i=0;i<200;i++);
P2=0X6D;
for(i=0;i<200;i++);
}

