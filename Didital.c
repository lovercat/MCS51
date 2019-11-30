#include<reg52.h>
sbit SMG_q=P1^0;
sbit SMG_b=P1^1;
sbit SMG_s=P1^2;
sbit SMG_g=P1^3;

sbit key1=P3^7;
sbit key2=P3^6;
sbit key3=P3^5;
sbit key4=P3^4;
sbit key5=P3^3;
sbit key6=P3^2;

sbit keyt1=P1^4;
sbit keyt2=P1^5;
sbit keyt3=P1^6;

sbit keyL=P1^7;

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay()
{
	unsigned int i=1000;
	while(i--);
}
void test1(void)
{
	SMG_q=0;
	P0=0x6d;
}

void test2(void)
{
	unsigned char i=0;
	//while(1)
	{
		SMG_q=0;
		P0=table[1];
		delay();
		P0=0x00;
		SMG_q=1;
		
		SMG_b=0;
		P0=table[2];
		delay();
		P0=0x00;
		SMG_b=1;

		SMG_s=0;
		P0=table[3];
		delay();
		P0=0x00;
		SMG_s=1;

		SMG_g=0;
		P0=table[4];
		delay();
		P0=0x00;
		SMG_g=1;
	}	
}

void test3(void)
{
	P0=0x00;
	P0=0xc0;
	SMG_q=1;
	SMG_b=1;
	SMG_s=1;
	SMG_g=0;
	
	//while(1)
	{
	 	if(key1==0)
		{
			P0=0x06;
		}
		else if(key2==0)
		{
			P0=0x5b;
		}
		else if(key3==0)
		{
			P0=0x4f;
		}
		else if(key4==0)
		{
			P0=0x66;
		}
		else if(key5==0)
		{
			P0=0x6d;
		}
		else if(key6==0)
		{
			P0=0x76;
		}
		
	}
}

void love()
{
	unsigned char l[]={0x38,0x3f,0x3e,0x79};
	SMG_q=0;

	SMG_q=0;
	P0=l[3];
	delay();
	P0=0x00;
	SMG_q=1;
		
	SMG_b=0;
	P0=l[2];
	delay();
	P0=0x00;
	SMG_b=1;

	SMG_s=0;
	P0=l[1];
	delay();
	P0=0x00;
	SMG_s=1;

	SMG_g=0;
	P0=l[0];
	delay();
	P0=0x00;
	SMG_g=1;
}

//µ¼Èë°å×Ó
void test_b(void)
{
	P0=~0xc0;
	SMG_q=0;
	SMG_b=0;
	SMG_s=0;
	SMG_g=1;
	//P0=0x00;
	//while(1)
	{
	 	if(key1==0)
		{
			P0=~0x06;
		}
		else if(key2==0)
		{
			P0=~0x5b;
		}
		else if(key3==0)
		{
			P0=~0x4f;
		}
		else if(key4==0)
		{
			P0=~0x66;
		}
		else if(key5==0)
		{
			P0=~0x6d;
		}
		else if(key6==0)
		{
			P0=~0x76;
		}
		
	}
}

void main()
{
	//test3();
	while(1)
	{
		if(keyt1==0)
		{
			test1();
		}
		if(keyt2==0)
		{
			test2();
		}
		if(keyt3==0)
		{
			test3();
		}
		if(keyL==0)
		{
			love();
		}
	}
}