/*A机通讯程序*/
#include<reg52.h>
sbit led1=P1^0;
sbit led2=P1^3;
sbit key1=P1^7;

unsigned char a;//定义按键次数，按键次数只能小于等于4次
/*将数码管显示的数字按顺序存储到数组中*/
unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
/*定义延迟函数*/
void DelayUs2x(unsigned char t)
{
	while(t--);
} 

void DelayMs(unsigned char t)
{
	while(t--)
	{
		DelayUs2x(245);
		DelayUs2x(245);
	}
}
/*将待发送数据信号存到sbuf中*/
void send(unsigned char dat)
{
	SBUF=dat;
	while(!TI);
	TI=0;
}

void main()
{
	led1=led2=1;//将所有的灯点亮
	P0=0x00;
	SCON=0x50;//工作方式1，打开允许接收控制位
	TMOD=0x20;//将定时器设置为工作方式2
	TH1=0xfd;//设置计数次数
	TL1=0xfd;
	TR1=1;//打开定时器1
	EA=1;//开启总中断
	ES=1;//打开串口中断
	while(1)
	{
		DelayMs(5);
		/*判断按键是否被按下，并通过按下的次数来发送字符*/
		if(key1==0)
		{
			DelayMs(10);
			if(key1==0)
			{
				a++;
				if(a==4)
					a=0;
				while(!key1);
			}
			
		}
		switch(a)
		{
			case 0: send('X');led1=led2=1;break;
			case 1: send('A');led1=0;led2=1;break;
			case 2: send('B');led2=0;led1=1;break;
			case 3: send('C');led1=0;led2=0;break;
		}
	}
	
}
/*中断函数：通过接收的字符在数码管上显示*/
void rec() interrupt 4
{
	RI=0;//关闭接收中断，并处理接收字符
	if(SBUF>=0 && SBUF<=9)
		P0=table[SBUF];
	else
		P0=0x00;
}


