#include<reg51.h>
sbit gled=P1^0;
sbit rled=P1^1;
sbit rs=P1^2;
sbit rw=P1^3;
sbit en=P1^4;
//lcd control pins
int i;
void lcdcmd(unsigned char x);
void lcddata(unsigned char x);
delay(int);
void lcddisplay(unsigned char *x);
unsigned char inputaadhar[12],v1;
int compare(const char *aadhar1,const char *aadhar2);


void main()
{
	int result;
	char *aadharnum1 = "59905285739";
  char *aadharnum2 = "64909630176";
  char *aadharnum3 = "12345678910";
	lcdcmd(0x38);
	lcdcmd(0x0c);
	lcdcmd(0x06);
	lcdcmd(0x0F);
	lcdcmd(0x80);
	lcddisplay("enter aadhar no");
	lcdcmd(0xC0);
	SCON=0x50;
	TMOD=0x20;
	TH1= -3;
	TR1=1;
	gled=rled=0;
	while(1)
	{
		for(v1=0;v1<12;v1++)
		{
			while(RI==0);
			inputaadhar[v1]=SBUF;
			RI=0;
			lcddata(inputaadhar[v1]);
		}
		 for ( i = 0; i < 12; i++) {
        if (inputaadhar[i] == aadharnum1[i])
					
		{
			gled=1;
			rled=0;
			lcdcmd(0x01);
			lcddisplay("mubin");
			delay(1000);
			lcdcmd(0xC0);
			lcddisplay("17/04/2000");
				delay(1000);
			lcdcmd(0x01);
			lcddisplay("6304631028");
				delay(1000);
			lcdcmd(0xC0);
			lcddisplay("mubin@...");
				delay(1000);
			lcdcmd(0x01);
		}
	else{
			lcdcmd(0x01);
			lcddisplay("invalid");
		}
		
		
		
		for ( i = 0; i < 12; i++) {
        if (inputaadhar[i] == aadharnum2[i]) 
				{
			gled=1;
			rled=0;
			lcddisplay("umesh");
			delay(1000);
			lcdcmd(0x01);
			lcddisplay("06/10/2001");
			delay(1000);
			lcdcmd(0xC0);
			lcddisplay("8520897985");
			delay(1000);
			lcdcmd(0x01);
			lcdcmd(0xC0);
			lcddisplay("umesh@...");
			delay(1000);
			lcdcmd(0x01);
		}
		
	else{
			lcdcmd(0x01);
			lcddisplay("invalid");
		}
		
		
for ( i = 0; i < 12; i++) {
        if (inputaadhar[i] == aadharnum3[i]) {
         
			gled=1;
			rled=0;
			lcddisplay("akhil");
			delay(1000);
			lcdcmd(0xC0);
			lcddisplay("06/11/2002");
			delay(1000);
			lcdcmd(0x01);
			lcddisplay("8520897565");
			delay(1000);
			lcdcmd(0xC0);
			lcddisplay("akhil@...");
			delay(1000);
			lcdcmd(0x01);
		}
		
		else{
			lcdcmd(0x01);
			lcddisplay("invalid");
		}
		
			
		
		
	}
}
void lcdcmd(unsigned char x)
{
	int i;
	P2=x;
	rs=0;
	rw=0;
	en=1;
	for(i=0;i<500;i++);
	en=0;
}
void lcddisplay(unsigned char *s)
{
	unsigned char w;
	for(w=0;s[w]!='\0';w++)
	{
		lcddata(s[w]);
	}
}
void lcddata(unsigned char dat)
{
	int i;
	P2=dat;
	rs=1;
	rw=0;
	en=1;
	for(i=0;i<500;i++);
	en=0;
}
delay (int k)
{
	int i,j;
	for(i=0;i<k;i++)
	for(j=0;j<1275;j++);
}

// Function to compare two Aadhar numbers
int compare(const char *aadhar1, const char *aadhar2) {
    // Assuming Aadhar numbers are 12-digit integers
    for ( i = 0; i < 12; i++) {
        if (aadhar1[i] == aadhar2[i]) {
            return 0; 
				}					
				else 
				{
					return -1;
				}// aadhar1 > aadhar2
        } // aadhar1 == aadhar2
}

	
			


