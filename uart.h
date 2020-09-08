#ifndef __UART_H
#define __UART_H


#include"main.h"
#define uint unsigned int
#define uchar unsigned char

void UART_Init();  //串口通信初始化
void UART_Drive(); //串口通信驱动函数
void UART() interrupt 4;  //串口通信中断函数



#endif

