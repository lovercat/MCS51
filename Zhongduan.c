#include<reg52.h>
#include<intrins.h>
unsigned char x=0xfe;
void delay(unsigned int timer)
{
	while(timer--);
}

void main()
{
	P2=0xff;
	EA=1;
	EX0=1;
	IT0=0;
	while(1)
	{
	}
}

void scan() interrupt 0
{

	P2=P2 & x;
	delay(10000);
	x=_crol_(x,1);
}