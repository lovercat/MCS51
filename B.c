/*B机通信代码*/
#include<reg52.h>
sbit led1=P1^0;
sbit led2=P1^3;
sbit key1=P1^7;

unsigned char a;//定义按键次数且只能小于等于11次
/*定义延迟函数*/
void DelayUs2x(unsigned char t)
{
	while(--t);
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
	;led1=led2=1;//将所有的灯点亮
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
		DelayMs(2);
		if(key1==0)//判断按键事件
		{
			DelayMs(10);
			if(key1==0)
			{
				a++;
				if(a==11)
				{
					a=0;
				}
				while(!key1);
			}
			send(a);
		}
	}
}
/*中断事件:根据接收的字符来执行灯的亮灭*/
void rec() interrupt 4
{
	RI=0;//关闭接收中断
	switch (SBUF)
	{
		case 'X':	led1=led2=1;break;
		case 'A':	led1=0;led2=1;break;
		case 'B':	led1=1;led2=0;break;
		case 'C':	led1=led2=0;break;
	}
}






