#include"reg52.h"
#ifndef __LCD12864_01_H
#define __LCD12864_01_H

#define uchar unsigned char
#define uint  unsigned int

//12864 IO�˿ڶ���
#define LCD_data  P0;             //���ݿ�
sbit LCD_RS  =  P3^5;            //�Ĵ���ѡ������ 
sbit LCD_RW  =  P3^6;            //Һ����/д����
sbit LCD_EN  =  P3^4;            //Һ��ʹ�ܿ���
sbit LCD_PSB =  P3^7;            //��/����ʽ����
sbit wela    =  P2^6;
sbit dula    =  P2^7;

#define delayNOP();  {_nop_();_nop_();_nop_();_nop_();}


void delay0(uchar x);  //x*0.14MS
void beep();
void  dataconv();
void lcd_pos(uchar X,uchar Y);  //ȷ����ʾλ��
void delay(int ms);
bit lcd_busy();                 //���lcdæ״̬
void lcd_wcmd(uchar cmd);       //дָ�����ݵ�lcd
void lcd_wdat(uchar dat);       //д��ʾ���ݵ�lcd
void lcd_init();                //lcd��ʼ���趨
void lcd_drive();               //lcd�������к���





#endif

