//#include <reg52.h>
//#include <intrins.h>
#include "main.h"
//unsigned char time_buf[8] = {20,20,9,8,12,55,0,6};//��������ʱ������
//uchar data time_data_buff[]={0x00,0x00,0x09,0x01,0x01,0x03,0x14};/*��ʽΪ: �� �� ʱ �� �� ���� �� */

uchar data lcd_line1[]={" 2000/00/00 000 "};
uchar data lcd_line2[]={"  00:00:00 00.0C"};
uchar data lcd_line3[]={"��ǿ:0-255  000 "};
uchar data lcd_line4[]={"ģʽ:0          "};
uchar code Weeks[][3]={{"SUN"},{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"},{"SUN"}};
uchar code mun_to_char[] = {"0123456789ABCDEF"}; /*�������ָ�ASCII��Ĺ�ϵ*/



uchar i=0;
uint temp=0; //�¶�ֵ
uint temp1=0;//��ǿ
uint timeH=0; //Сʱ

void main(void){
//	 wela=0;
//	dula=0; 
sys_init();
lcd_data_port = 0xff; /*�ͷ�P0�˿�*/	
//	lcd_pos(0,0);             //������ʾλ��Ϊ��һ�еĵ�1���ַ�
//     i = 0;


while(1){
Ds1302_Read_Time();
temp=ReadTemperature();
temp1=255-ReadADC(1);//ֵȡ��ֵ��������ʾ��ǿԽС����ֵԽС
	
//--------------
RST= 1;  //  displayǰ�����
display();
//--------------
//	
 }
}

void motor_control()
{
	if(MODE)//�Զ�����ģʽ
	{
		timeH=(time_buf[4]/0x10)*10+(time_buf[4]%0x10);
		if((timeH>=0&&timeH<6)||(timeH<=23&&timeH>20)||(timeH<=16&&timeH>13))  //21-6��  13-16��
			{				
			if(temp1>170&&temp>300)
			{
				if(MotorState=1) //����Ǵ�״̬������
				{
					Motor_B();
				}
			}
		}
		else
			{
				if(temp1<170&&temp<300)
			{
				if(MotorState=0) //����ǹ���״̬����
				{
					Motor_F();
				}
			}
		
		}
	}
	else  // �ֶ�����������
	{
		
	
	}
}


void sys_init()
{
	 lcd_init();    /*LCD12864 ��ʼ��*/ 
   Ds1302_Init();
	 Ds1302_Write_Time();//time_buf1[8]
	 UsartInit();
  //lcd_system_reset(); /*LCD1602 ��ʼ��*/
	MODE=0; //��ʼ��mode 
	MotorFlag=0;  
  MotorState=0; //0�� ����״̬   1����״̬

}



void display(void)
{
	/*ˢ����ʾ*/
    //---ʱ��---
		lcd_line1[3]  = mun_to_char[time_buf[1]/0x10];
		lcd_line1[4]  = mun_to_char[time_buf[1]%0x10];  /*��*/
		lcd_line1[6]  = mun_to_char[time_buf[2]/0x10];
		lcd_line1[7]  = mun_to_char[time_buf[2]%0x10];  /*��*/
		lcd_line1[9]  = mun_to_char[time_buf[3]/0x10];
		lcd_line1[10] = mun_to_char[time_buf[3]%0x10];  /*��*/
		for(i=0;i<3;i++) lcd_line1[i+12]=Weeks[time_buf[7]][i]; /*����*/
		lcd_line2[2]  = mun_to_char[time_buf[4]/0x10];
  	lcd_line2[3]  = mun_to_char[time_buf[4]%0x10]; /*ʱ*/
		lcd_line2[5]  = mun_to_char[time_buf[5]/0x10];
		lcd_line2[6]  = mun_to_char[time_buf[5]%0x10]; /*��*/
		lcd_line2[8]  = mun_to_char[time_buf[6]/0x10];
		lcd_line2[9]  = mun_to_char[time_buf[6]%0x10]; /*��*/
//	 //--�¶�--
		lcd_line2[11] = mun_to_char[temp/100];
		lcd_line2[12] = mun_to_char[temp%100/10];
		lcd_line2[14] = mun_to_char[temp%10];  /*�¶�*/
		//------
		//--��ǿ--
		lcd_line3[12] = mun_to_char[temp1/100];
		lcd_line3[13] = mun_to_char[temp1%100/10];
		lcd_line3[14] = mun_to_char[(temp1%100)%10];  /*��ǿ*/
		//------
		//--ģʽ--
		lcd_line3[5] = mun_to_char[MODE];
		//------
//		/*l602��ʾ*/
//		for(i=0;i<16;i++) lcd_char_write(i,0,lcd_line1[i]);
//	    for(i=0;i<16;i++) lcd_char_write(i,1,lcd_line2[i]);
		/*l2864��ʾ*/
		lcd_pos(0,0);
		for(i=0;i<16;i++) lcd_wdat(lcd_line1[i]);
		lcd_pos(1,0);
	    for(i=0;i<16;i++) lcd_wdat(lcd_line2[i]);
		lcd_pos(2,0);
		for(i=0;i<16;i++) lcd_wdat(lcd_line3[i]);
		lcd_pos(3,0);
		for(i=0;i<16;i++) lcd_wdat(lcd_line4[i]);
		
		

//    lcd_pos(0,0);             //������ʾλ��Ϊ��һ�еĵ�1���ַ�
//     i = 0;
//    while(lcd_line1[i] != '\0')
//     {                         //��ʾ�ַ�
//       lcd_wdat(lcd_line1[i]);
//       i++;
//     }
//    lcd_pos(1,0);             //������ʾλ��Ϊ�ڶ��еĵ�1���ַ�
//     i = 0;
//    while(lcd_line2[i] != '\0')
//     {
//       lcd_wdat(lcd_line2[i]);      //��ʾ�ַ�
//       i++;
//     }
// 	 lcd_pos(2,0);             //������ʾλ��Ϊ�����еĵ�1���ַ�
//     i = 0;
//    while(lcd_line3[i] != '\0')
//     {
//       lcd_wdat(lcd_line3[i]);      //��ʾ�ַ�
//       i++;
//     }
}