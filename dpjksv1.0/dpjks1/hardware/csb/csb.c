//#include "csb.h"
#include "main.h"

sbit Trig = P2^6;
sbit Echo = P2^7;  //需要改引脚定义


unsigned int  time=0;
unsigned long S=0;

//void time0() interrupt 1 		 //T0中断用来计数器溢出,超过测距范围
//  {
//    flag=1;							 //中断溢出标志
//  }
	
	
 void  StartModule() 		         //启动模块
  {
	  Trig=1;			                     //启动一次模块
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
	     while(!Echo);		//当RX为零时等待
	     TR0=1;			    //开启计数
	     while(Echo);			//当RX为1计数并等待
	     TR0=0;				//关闭计数
	     time=TH0*256+TL0;
	     TH0=0;
	     TL0=0;
       S=(time*1.7)/100;     //算出来是CM
	    DelayMs(20);    //可以删除  为保持稳定而设置
	return S;
}