//#include "csb.h"
#include "main.h"

sbit Trig = P2^6;
sbit Echo = P2^7;  //��Ҫ�����Ŷ���


unsigned int  time=0;
unsigned long S=0;

//void time0() interrupt 1 		 //T0�ж��������������,������෶Χ
//  {
//    flag=1;							 //�ж������־
//  }
	
	
 void  StartModule() 		         //����ģ��
  {
	  Trig=1;			                     //����һ��ģ��
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  Trig=0;
  }
	
// void delayms(unsigned int ms)
//{
//	unsigned char i=100,j;
//	for(;ms;ms--)
//	{
//		while(--i)
//		{
//			j=10;
//			while(--j);
//		}
//	}
//}

unsigned long getdistance(){
	StartModule();
	     while(!Echo);		//��RXΪ��ʱ�ȴ�
	     TR0=1;			    //��������
	     while(Echo);			//��RXΪ1�������ȴ�
	     TR0=0;				//�رռ���
	     time=TH0*256+TL0;
	     TH0=0;
	     TL0=0;
       S=(time*1.7)/100;     //�������CM
	    DelayMs(20);    //����ɾ��  Ϊ�����ȶ�������
	return S;
}