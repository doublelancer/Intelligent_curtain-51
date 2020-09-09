//#include <reg52.h>
//#include <intrins.h>
#include "main.h"
//unsigned char time_buf[8] = {20,20,9,8,12,55,0,6};//空年月日时分秒周
//uchar data time_data_buff[]={0x00,0x00,0x09,0x01,0x01,0x03,0x14};/*格式为: 秒 分 时 日 月 星期 年 */

uchar data lcd_line1[]={" 2000/00/00 000 "};
uchar data lcd_line2[]={"  00:00:00 00.0C"};
uchar data lcd_line3[]={"光强:0-255  000 "};
uchar data lcd_line4[]={"模式:0          "};
uchar code Weeks[][3]={{"SUN"},{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"},{"SUN"}};
uchar code mun_to_char[] = {"0123456789ABCDEF"}; /*定义数字跟ASCII码的关系*/



uchar i=0;
uint temp=0; //温度值
uint temp1=0;//光强
uint timeH=0; //小时

void main(void){
//	 wela=0;
//	dula=0; 
sys_init();
lcd_data_port = 0xff; /*释放P0端口*/	
//	lcd_pos(0,0);             //设置显示位置为第一行的第1个字符
//     i = 0;


while(1){
Ds1302_Read_Time();
temp=ReadTemperature();
temp1=255-ReadADC(1);//值取差值，用于显示光强越小，数值越小
	
//--------------
RST= 1;  //  display前必须加
display();
//--------------
//	
 }
}

void motor_control()
{
	if(MODE)//自动控制模式
	{
		timeH=(time_buf[4]/0x10)*10+(time_buf[4]%0x10);
		if((timeH>=0&&timeH<6)||(timeH<=23&&timeH>20)||(timeH<=16&&timeH>13))  //21-6点  13-16点
			{				
			if(temp1>170&&temp>300)
			{
				if(MotorState=1) //如果是打开状态，关上
				{
					Motor_B();
				}
			}
		}
		else
			{
				if(temp1<170&&temp<300)
			{
				if(MotorState=0) //如果是关上状态，打开
				{
					Motor_F();
				}
			}
		
		}
	}
	else  // 手动按键或蓝牙
	{
		
	
	}
}


void sys_init()
{
	 lcd_init();    /*LCD12864 初始化*/ 
   Ds1302_Init();
	 Ds1302_Write_Time();//time_buf1[8]
	 UsartInit();
  //lcd_system_reset(); /*LCD1602 初始化*/
	MODE=0; //初始化mode 
	MotorFlag=0;  
  MotorState=0; //0： 拉上状态   1：打开状态

}



void display(void)
{
	/*刷新显示*/
    //---时间---
		lcd_line1[3]  = mun_to_char[time_buf[1]/0x10];
		lcd_line1[4]  = mun_to_char[time_buf[1]%0x10];  /*年*/
		lcd_line1[6]  = mun_to_char[time_buf[2]/0x10];
		lcd_line1[7]  = mun_to_char[time_buf[2]%0x10];  /*月*/
		lcd_line1[9]  = mun_to_char[time_buf[3]/0x10];
		lcd_line1[10] = mun_to_char[time_buf[3]%0x10];  /*日*/
		for(i=0;i<3;i++) lcd_line1[i+12]=Weeks[time_buf[7]][i]; /*星期*/
		lcd_line2[2]  = mun_to_char[time_buf[4]/0x10];
  	lcd_line2[3]  = mun_to_char[time_buf[4]%0x10]; /*时*/
		lcd_line2[5]  = mun_to_char[time_buf[5]/0x10];
		lcd_line2[6]  = mun_to_char[time_buf[5]%0x10]; /*分*/
		lcd_line2[8]  = mun_to_char[time_buf[6]/0x10];
		lcd_line2[9]  = mun_to_char[time_buf[6]%0x10]; /*秒*/
//	 //--温度--
		lcd_line2[11] = mun_to_char[temp/100];
		lcd_line2[12] = mun_to_char[temp%100/10];
		lcd_line2[14] = mun_to_char[temp%10];  /*温度*/
		//------
		//--光强--
		lcd_line3[12] = mun_to_char[temp1/100];
		lcd_line3[13] = mun_to_char[temp1%100/10];
		lcd_line3[14] = mun_to_char[(temp1%100)%10];  /*光强*/
		//------
		//--模式--
		lcd_line3[5] = mun_to_char[MODE];
		//------
//		/*l602显示*/
//		for(i=0;i<16;i++) lcd_char_write(i,0,lcd_line1[i]);
//	    for(i=0;i<16;i++) lcd_char_write(i,1,lcd_line2[i]);
		/*l2864显示*/
		lcd_pos(0,0);
		for(i=0;i<16;i++) lcd_wdat(lcd_line1[i]);
		lcd_pos(1,0);
	    for(i=0;i<16;i++) lcd_wdat(lcd_line2[i]);
		lcd_pos(2,0);
		for(i=0;i<16;i++) lcd_wdat(lcd_line3[i]);
		lcd_pos(3,0);
		for(i=0;i<16;i++) lcd_wdat(lcd_line4[i]);
		
		

//    lcd_pos(0,0);             //设置显示位置为第一行的第1个字符
//     i = 0;
//    while(lcd_line1[i] != '\0')
//     {                         //显示字符
//       lcd_wdat(lcd_line1[i]);
//       i++;
//     }
//    lcd_pos(1,0);             //设置显示位置为第二行的第1个字符
//     i = 0;
//    while(lcd_line2[i] != '\0')
//     {
//       lcd_wdat(lcd_line2[i]);      //显示字符
//       i++;
//     }
// 	 lcd_pos(2,0);             //设置显示位置为第三行的第1个字符
//     i = 0;
//    while(lcd_line3[i] != '\0')
//     {
//       lcd_wdat(lcd_line3[i]);      //显示字符
//       i++;
//     }
}