#ifndef __UART_H
#define __UART_H


//#include"main.h"
#define uint unsigned int
#define uchar unsigned char

void UART_Init();  //串口通信初始化
void PutString(unsigned char *TXStr); //串口发送数据
bit ReceiveString();                  //串口接收数据


#endif

