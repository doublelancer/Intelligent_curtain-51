#ifndef __UART_H
#define __UART_H


#include"main.h"
#define uint unsigned int
#define uchar unsigned char

void UART_Init();  //����ͨ�ų�ʼ��
void UART_Drive(); //����ͨ����������
void UART() interrupt 4;  //����ͨ���жϺ���



#endif

