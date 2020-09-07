#include <reg52.h>
#include "intrins.h"
#include "main.h"
#include  "motordriver.h"

/*
	io�ڵĸĸ�
*/
//sbit DULA=P2^6;//����ܶ�ѡ
unsigned char MotorFlag;  //δ�����ȫ�ֱ������ɼ��̿���
unsigned char code F_Rotation[4]={0x10,0x08,0x04,0x02}; //��ת���񣬻���ɶ����� 0001 0000��0000 1000��0000 0100��0000 0010
unsigned char code B_Rotation[4]={0x02,0x04,0x08,0x10}; //��ת���񣬻���ɶ����� 0000 0010��0000 0100��0000 1000��0001 0000



/******************************************************************
*������ʱ����
******************************************************************/
void Delay(unsigned int i)//��ʱ
{
 while(i--);
}


void delay1s(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}

/******************************************************************
*������Motor
*���ܣ�����MotorFlag�����жϵ���˶�״̬
*      MotorFlag=0  �����ͣ
*      MotorFlag=1  �����ת
*      MotorFlag=2  �����ת
*@author myc
******************************************************************/
void MotorDrive()
{
	
//��ʼ������	
  unsigned char i;
  unsigned int x;

	
/*********�ص�����ܵĶ�ѡ�źš���ֹ������ܵ�P0���źŵ�Ӱ��******/
//	P0=0Xff;
//	Delay(500);
//	DULA=1;
//	Delay(500);
//	DULA=0;
/******************************************************************/
	
	
	

	if(MotorFlag==1){        //�ж���ת
	  for(x=600;x>0;x--){
      for(i=0;i<4;i++)      //4��
        { 
       P0=F_Rotation[i];  //�����Ӧ���� �������л��ɷ�ת����
       Delay(500);        //�ı�����������Ե������ת�� ,����ԽС��ת��Խ��
	    }
    }
	}
	if(MotorFlag==2){        //�жϷ�ת
     for(x=100;x>0;x--){
	     for(i=0;i<4;i++)      //4��
         {
         P0=B_Rotation[i];  //�����Ӧ���� �������л��ɷ�ת����
         Delay(500);        //�ı�����������Ե������ת�� ,����ԽС��ת��Խ��
	     }
	   }
	 }
	
	 if(MotorFlag==0){   //�жϲ����в���
	   // while(1);
	 }
	 
 }