#include "main.h"

unsigned char ReadADC(unsigned char Chl)
 {
   unsigned char Val;
   Start_I2c();               //��������
   SendByte(AddWr);             //����������ַ
     if(ack==0)return(0);
   SendByte(0x40|Chl);            //���������ӵ�ַ
     if(ack==0)return(0);
   Start_I2c();
   SendByte(AddWr+1);
      if(ack==0)return(0);
   Val=RcvByte();
   NoAck_I2c();                 //���ͷ�Ӧλ
   Stop_I2c();                  //��������
  return(Val);
 }
 /*
  num=255-ReadADC(1);//ֵȡ��ֵ��������ʾ��ǿԽС����ֵԽС
 TempData[0]=dofly_DuanMa[num/100];    
 TempData[1]=dofly_DuanMa[(num%100)/10];
 TempData[2]=dofly_DuanMa[(num%100)%10];
 */