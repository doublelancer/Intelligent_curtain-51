#include "main.h"
#include "uart.h"


uchar uart_flag;     //串行通信标志位
uchar uart_data;     //串行通信数据位
uchar uart_permit;   //串口允许标志位
uchar data_receive;  //数据接收

/*******************************
*串口通信初始化
*******************************/

void UART_Init()
{
	SCON=0x50;			//设置为工作方式1
	TMOD=0x20;			//设置计数器工作方式2
	PCON=0x80;			//波特率加倍
	TH1=0xfd;				
	TL1=0xfd;       //以上参数根据具体需求改
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}


/*************************************
*串口驱动函数
*		若uart_permit=1，则正常实现接收
*   若uart_permit=0，则关闭中断


         该函数可能会根据control.c的逻辑再进行修改。
**************************************/
void UART_drive(void)
{
	
	while(uart_permit==1)
	{
		if(uart_flag==1)//如果有数据则进入这个语句
		{
			ES=0;
			usart_flag=0;
			ES=1;
		}
	}
}




/*************************************
*串口通信中断函数
**************************************/
void UART() interrupt 4//串行中断函数
{
	/******
	（尚未确定）接收到数据后的操作？
	******/
	
	uart_data=SBUF;//收取数据
	uart_flag=1;//标志置位
	RI=0;
}

