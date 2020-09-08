//#include "main.h"
#include "uart.h"
#include "reg51.h"
#include "stdio.h"
uchar uart_flag=0;     //串行通信标志位
uchar uart_data;     //串行通信数据位
uchar uart_permit;   //串口允许标志位
uchar data_receive;  //数据接收
char buf_string[14];  //定义数据包长度为14个单位

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
*串口发送
**************************************/
//void PutString(uchar *TXStr)  
//{                
//    ES=0;     
//     while(*TXStr!=0) 
//    {                      
//        SBUF=*TXStr;
//        while(TI==0);
//        TI=0;    
//        TXStr++;
//    }
//    ES=1; 
//}      

/************************************
*串口接收
*		接收数据等待延迟，等待时间太久会导致CPU运算闲置，太短会出现"数据包被分割",默认count=130
*************************************/
bit ReceiveString()    
{
    char * RecStr=buf_string;
    char num=0;
    unsigned char count=0;
    loop:    
    *RecStr=SBUF;
    count=0;
    RI=0;    
    if(num<13)  //数据包长度为14个字符,尝试连续接收14个字符
    {
        num++;
        RecStr++;    
        while(!RI)
        {
            count++;
            if(count>130)return 0;   
        }
        goto loop;
    }
    return 1;
}


/*************************************
*串口通信中断函数
**************************************/
void UART() interrupt 4//串行中断函数
{
	
	if(ReceiveString())
	{
	  RI=0;
	}
}

//至此，发送的数据传入了字符数组buf_string
