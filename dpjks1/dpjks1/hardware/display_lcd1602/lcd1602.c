//#include"lcd1602.h"
#include "main.h"

//---------------------------------------------
void lcd_delay(uchar ms) /*LCD1602 ��ʱ*/
{
    uchar j;
    while(ms--){
        for(j=0;j<250;j++)
            {;}
        }   
}

void lcd_busy_wait() /*LCD1602 æ�ȴ�*/
{
    lcd_rs_port = 0;
    lcd_rw_port = 1;
    lcd_en_port = 1;
    lcd_data_port = 0xff;
    while (lcd_data_port&0x80);
    lcd_en_port = 0; 

}


void lcd_command_write(uchar command) /*LCD1602 ������д��*/
{
    lcd_busy_wait();
    lcd_rs_port = 0;
    lcd_rw_port = 0;
    lcd_en_port = 0;
    lcd_data_port = command;
    lcd_en_port = 1;
    lcd_en_port = 0;     
}



void lcd_system_reset() /*LCD1602 ��ʼ��*/
{
    lcd_delay(20);
    lcd_command_write(0x38);
    lcd_delay(100);
    lcd_command_write(0x38);
    lcd_delay(50);
    lcd_command_write(0x38);
    lcd_delay(10);
    lcd_command_write(0x08);
    lcd_command_write(0x01);
    lcd_command_write(0x06);
    lcd_command_write(0x0c); 
	lcd_data_port = 0xff; /*�ͷ����ݶ˿�*/
}

void lcd_char_write(uchar x_pos,y_pos,lcd_dat) /*LCD1602 �ַ�д��*/
{
    x_pos &= 0x0f; /* Xλ�÷�Χ 0~15 */
    y_pos &= 0x01; /* Yλ�÷�Χ 0~ 1 */
    if(y_pos==1) x_pos += 0x40;
    x_pos += 0x80;
    lcd_command_write(x_pos);
    lcd_busy_wait();
    lcd_rs_port = 1;
    lcd_rw_port = 0;
    lcd_en_port = 0;
    lcd_data_port = lcd_dat;
    lcd_en_port = 1;
    lcd_en_port = 0; 
	lcd_data_port = 0xff; /*�ͷ����ݶ˿�*/
}



//void main()
//{
//	uchar i;
//	uint temp; //�¶�ֵ
//	lcd_system_reset(); /*LCD1602 ��ʼ��*/
//	/////////////////////////////////////////////////////////////////
//	P0=0X00;//�ص�����ܵ��źš���ֹ������ܵ�P0���źŵ�Ӱ�졣
//	dula=1;
//	wela=0;
//	delay1();
//	dula=0;
//	wela=0;
//	delay1();
//    ////////////////////////////////////////////////////////////////
//	lcd_data_port = 0xff; /*�ͷ�P0�˿�*/
//	Set1302(time_data_buff);  /*����ʱ��*/
//	while(1){
//		Get1302(time_data_buff); /*��ȡ��ǰʱ��*/
//		temp = 	ReadTemperature(); /*��ȡ��ǰ�¶�ֵ*/
//		/*ˢ����ʾ*/
//		lcd1602_line1[3]  = mun_to_char[time_data_buff[6]/0x10];
//		lcd1602_line1[4]  = mun_to_char[time_data_buff[6]%0x10];  /*��*/
//		lcd1602_line1[6]  = mun_to_char[time_data_buff[4]/0x10];
//		lcd1602_line1[7]  = mun_to_char[time_data_buff[4]%0x10];  /*��*/
//		lcd1602_line1[9]  = mun_to_char[time_data_buff[3]/0x10];
//		lcd1602_line1[10] = mun_to_char[time_data_buff[3]%0x10];  /*��*/
//		for(i=0;i<3;i++) lcd1602_line1[i+12]=Weeks[time_data_buff[5]&0x07][i]; /*����*/
//		lcd1602_line2[2]  = mun_to_char[time_data_buff[2]/0x10];
//  		lcd1602_line2[3]  = mun_to_char[time_data_buff[2]%0x10]; /*ʱ*/
//		lcd1602_line2[5]  = mun_to_char[time_data_buff[1]/0x10];
//		lcd1602_line2[6]  = mun_to_char[time_data_buff[1]%0x10]; /*��*/
//		lcd1602_line2[8]  = mun_to_char[time_data_buff[0]/0x10];
//		lcd1602_line2[9]  = mun_to_char[time_data_buff[0]%0x10]; /*��*/
//        //------
//		lcd1602_line2[12] = mun_to_char[temp/100];
//		lcd1602_line2[13] = mun_to_char[temp%100/10];
//		lcd1602_line2[15] = mun_to_char[temp%10];  /*�¶�*/
//		//------
//		for(i=0;i<16;i++) lcd_char_write(i,0,lcd1602_line1[i]);
//	    for(i=0;i<16;i++) lcd_char_write(i,1,lcd1602_line2[i]);
//		}
//}




