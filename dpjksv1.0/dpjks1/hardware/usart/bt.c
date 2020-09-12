#include "reg52.h"	
#include "main.h"



/*******************************************************************************
* 函数名         :UartInit()
* 函数功能		   :设置串口
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
//void UartInit()
//{
//	SCON=0X50;			//设置为工作方式1
//	TMOD=0X20;			//设置计数器工作方式2
//	PCON=0X80;			//波特率加倍
//	TH1=0XF3;				//计数器初始值设置，注意波特率是4800的
//	TL1=0XF3;
//	ES=1;						//打开接收中断
//	EA=1;						//打开总中断
//	TR1=1;					//打开计数器
//}

void UartInit(void)
{
   TMOD = 0x20;  //9600
    SCON = 0x50;
    TH1 = 0xFD;
    TL1 = TH1;
    PCON = 0x00;
    EA = 1;
    ES = 1;
    TR1 = 1;
}
void uart_tx_byte(uchar str){
  SBUF=str;
	while(TI==0);
	//if(TI)  //如果是发送标志位，清零
     TI=0;
}

//void Uart() interrupt 4
//{
//	u8 receiveData;

//	receiveData=SBUF;//出去接收到的数据
//	RI = 0;//清除接收中断标志位
//	SBUF=receiveData;//将接收到的数据放入到发送寄存器
//	while(!TI);			 //等待发送数据完成
//	TI=0;						 //清除发送完成标志位
//}

//void UART_SER (void) interrupt 4 //串行中断服务程序
//{
//    unsigned char Temp;          //定义临时变量 
//    unsigned char i;
//    if(RI)                        //判断是接收中断产生
//     {
//	   RI=0;                      //标志位清零
//	  Temp=SBUF;                 //读入缓冲区的值
//		if(Temp=='m')
//			 {
//				 MODE=!MODE;
//				 SBUF=MODE;
//			 }
//			 
//	 if(Temp=='k')
//			 {
//				 Motor_Flag=1;
//				 SBUF=Temp;
//			 }
//	if(Temp=='b')
//			 {
//				 Motor_Flag=2;
//				 SBUF=Temp;
//			 }
//			 
//   if(Temp=='s')
//			 {
//				 ShowP=1;
//				 SBUF=Temp;
//			 }
//			 
//		if(Temp=='t')
//			 {
//				 SetTime=1;
//				 SBUF=Temp;	
//			 }
//			 
//     if(SetTime)
//		{
//	  time_buf2[i]=Temp&0x0F;
//	  i++;
//	  if(i==16)                  //连续接收16个字符信息
//	   {
//	    i=0;
//		SetFlag=1;               //接收完成标志位置1
//		SetTime=0;
//	   }
//      SBUF=Temp; //把接收到的值再发回电脑端
//	 }
//   
//	 }
//		//while(!TI);			 //等待发送数据完成 
//   if(TI)  //如果是发送标志位，清零
//     TI=0;

//}

//void Usart() interrupt 4
//{
//	 
//				
//unsigned char receiveData;

//receiveData=SBUF;//出去接收到的数据
//	
//	
////将这次中断的字符内容写入buf_string中	
//buf_string[length]=SBUF;
//length++;
//	
//	
//RI = 0;//清除接收中断标志位
//SBUF=receiveData;//将接收到的数据放入到发送寄存器
//while(!TI);			 //等待发送数据完成
//TI=0;						 //清除发送完成标志位
//				
//}