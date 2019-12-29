#include<reg52.h>

sbit Beep=P1^5;		//将P1.5口定义为蜂鸣器输出口

void main(void)
{
	Beep=0;			//输出低电平，使得蜂鸣器发出响声
	while(1);		//循环，使蜂鸣器一直响
}