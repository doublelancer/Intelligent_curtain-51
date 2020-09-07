#include <reg52.h>
#include "intrins.h"
#include "main.h"
#include  "motordriver.h"

/*
	io口的改改
*/
//sbit DULA=P2^6;//数码管段选
unsigned char MotorFlag;  //未定义的全局变量，由键盘控制
unsigned char code F_Rotation[4]={0x10,0x08,0x04,0x02}; //正转表格，换算成二进制 0001 0000，0000 1000，0000 0100，0000 0010
unsigned char code B_Rotation[4]={0x02,0x04,0x08,0x10}; //反转表格，换算成二进制 0000 0010，0000 0100，0000 1000，0001 0000



/******************************************************************
*两个延时函数
******************************************************************/
void Delay(unsigned int i)//延时
{
 while(i--);
}


void delay1s(void)   //误差 0us
{
    unsigned char a,b,c;
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}

/******************************************************************
*函数：Motor
*功能：根据MotorFlag参数判断电机运动状态
*      MotorFlag=0  电机暂停
*      MotorFlag=1  电机正转
*      MotorFlag=2  电机反转
*@author myc
******************************************************************/
void MotorDrive()
{
	
//初始化配置	
  unsigned char i;
  unsigned int x;

	
/*********关掉数码管的段选信号。阻止数码管受到P0口信号的影响******/
//	P0=0Xff;
//	Delay(500);
//	DULA=1;
//	Delay(500);
//	DULA=0;
/******************************************************************/
	
	
	

	if(MotorFlag==1){        //判断正转
	  for(x=600;x>0;x--){
      for(i=0;i<4;i++)      //4相
        { 
       P0=F_Rotation[i];  //输出对应的相 可以自行换成反转表格
       Delay(500);        //改变这个参数可以调整电机转速 ,数字越小，转速越大
	    }
    }
	}
	if(MotorFlag==2){        //判断反转
     for(x=100;x>0;x--){
	     for(i=0;i<4;i++)      //4相
         {
         P0=B_Rotation[i];  //输出对应的相 可以自行换成反转表格
         Delay(500);        //改变这个参数可以调整电机转速 ,数字越小，转速越大
	     }
	   }
	 }
	
	 if(MotorFlag==0){   //判断不进行操作
	   // while(1);
	 }
	 
 }
