/*************************
�汾1.0
��ʵ����ʾ�ַ��Ĺ���
*************************/


#include "lcd12864_01.h"
#include <reg52.h>
#include <intrins.h>


uchar code dis1[] = {"�����¶�"};
uchar code dis2[] = {"00"};
uchar code dis3[] = {"�����ǿ"};
uchar code dis4[] = {"00"};

//12864 IO�˿ڶ���
//#define LCD_data  P0             //���ݿ�
//sbit LCD_RS  =  P3^5;            //�Ĵ���ѡ������ 
//sbit LCD_RW  =  P3^6;            //Һ����/д����
//sbit LCD_EN  =  P3^4;            //Һ��ʹ�ܿ���
//sbit LCD_PSB =  P3^7;            //��/����ʽ����
//sbit wela    =  P2^6;
//sbit dula    =  P2^7;

void delay(int ms)
{
    while(ms--)
	{
      uchar i;
	  for(i=0;i<250;i++)  
	   {
	    _nop_();			   
		_nop_();
		_nop_();
		_nop_();
	   }
	}
}	


bit lcd_busy()
 { 
                           
    bit result;
    P0=0X00;              //�ص�����ܵ��źš���ֹ������ܵ�P0���źŵ�Ӱ��
    LCD_RS = 0;
    LCD_RW = 1;
    LCD_EN = 1;
    delayNOP();
    result = (bit)(P0&0x80);
    LCD_EN = 0;
    return(result); 
 }
 
 
 
 
 
void lcd_wcmd(uchar cmd)
{   
                         
   while(lcd_busy());
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_EN = 0;
    _nop_();
    _nop_(); 
    P0 = cmd;
    delayNOP();
    LCD_EN = 1;
    delayNOP();
    LCD_EN = 0;  
}
 
 
 
void lcd_wdat(uchar dat)
{                          
   while(lcd_busy());
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_EN = 0;
    P0 = dat;
    delayNOP();
    LCD_EN = 1;
    delayNOP();
    LCD_EN = 0; 
}


void lcd_init()
{ 

    LCD_PSB = 1;         //���ڷ�ʽ
    
    lcd_wcmd(0x34);      //����ָ�����
    delay(5);
    lcd_wcmd(0x30);      //����ָ�����
    delay(5);
    lcd_wcmd(0x0C);      //��ʾ�����ع��
    delay(5);
    lcd_wcmd(0x01);      //���LCD����ʾ����
    delay(5);
}
 
 
void delay0(uchar x)    //x*0.14MS
{
  uchar i;
  while(x--)
 {
  for (i = 0; i<13; i++) {}
 }
}
 
 
void lcd_pos(uchar X,uchar Y)
{                          
   uchar  pos;
   if (X==0)
     {X=0x80;}
   else if (X==1)
     {X=0x90;}
   else if (X==2)
     {X=0x88;}
   else if (X==3)
     {X=0x98;}
   pos = X+Y ;  
   lcd_wcmd(pos);     //��ʾ��ַ
}
 
 
void lcd_drive()
{
	 uchar i;
   delay(10);                 //��ʱ
   wela=0;
	 dula=0; 
   lcd_init();                //��ʼ��LCD             
  
    lcd_pos(0,0);             //������ʾλ��Ϊ��һ�еĵ�1���ַ�
     i = 0;
    while(dis1[i] != '\0')
     {                         //��ʾ�ַ�
       lcd_wdat(dis1[i]);
       i++;
     }
    lcd_pos(1,0);             //������ʾλ��Ϊ�ڶ��еĵ�1���ַ�
     i = 0;
    while(dis2[i] != '\0')
     {
       lcd_wdat(dis2[i]);      //��ʾ�ַ�
       i++;
     }
 	 lcd_pos(2,0);             //������ʾλ��Ϊ�����еĵ�1���ַ�
     i = 0;
    while(dis3[i] != '\0')
     {
       lcd_wdat(dis3[i]);      //��ʾ�ַ�
       i++;
     }
	 lcd_pos(3,0);             //������ʾλ��Ϊ�����еĵ�1���ַ�
     i = 0;
    while(dis4[i] != '\0')
     {
       lcd_wdat(dis4[i]);      //��ʾ�ַ�
       i++;
     };
}
 
 