
sbit rs = P3^6;
sbit en = P3^7;

lcdcmd(char x);
lcddata(char x);
lcdprint(char *x);
delay(int);
lcdinit()
{
	lcdcmd(0x38);
	lcdcmd(0x0c);
	lcdcmd(0x06);
	lcdcmd(0x01);
	lcdcmd(0x80);
}
lcdprint(char *c)
{
	while( *c!= '\0')
	{
		lcddata(*c);
	  *c++;
	}
}

lcdcmd(char x)
{
	int i;
	P2 = x;
	rs = 0;
	en = 1;
	for(i=0;i<5000;i++);
	en = 0;
}
lcddata(char x)
{
	int i;
	P2 = x;
	rs = 1;
	en = 1;
	for(i=0;i<5000;i++);
	en = 0;
}
delay(int k)
{
	int i,j;
	for(i = 0;i<k;i++)
	for(j = 0;j<1275;j++);
	
}









