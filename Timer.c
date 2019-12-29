#include<reg51.h>
sbit LED=P2^0;
void delay();
void init();
void main()
{
	init();
	while(1);
	
}
void init()
{
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void timer() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	LED=~LED;
}
