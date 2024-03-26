#include <reg51.h>
sbit Registerselect = P3^6;
sbit Enable = P3^7;
//data pins connected to the p2
void main()
{
	int i;
	P2 = 0x38;
	Registerselect = 0;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	P2=0x0C;
	Registerselect=0;
	Enable=1;
	for(i=0;i<5000;i++);
	Enable = 0;
	
	P2=0x06;
	Registerselect=0;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable = 0;
	
	P2=0x01;
	Registerselect=0;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable = 0;
	
	P2='P';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable = 0;
	
	P2='O';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable = 0;
	
	P2='T';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='T';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='I';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2=' ';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='F';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='E';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='L';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	

	
	P2='L';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='O';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='W';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;

	P2=0xC0;
	Registerselect=0;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='P';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='A';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='N';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='D';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='H';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='I';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2=' ';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='F';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='E';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='L';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='L';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='O';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
	P2='W';
	Registerselect=1;
	Enable = 1;
	for(i=0;i<5000;i++);
	Enable=0;
	
}