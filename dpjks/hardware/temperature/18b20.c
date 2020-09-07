#include "main.h"
#include"18b20.h"
//DS18B20��ʱ����
void delay(unsigned int i)
{
	while(i--);
}

//DS18B20��ʼ������
void Init_DS18B20(void)
{
	unsigned char x=0;
	DQ = 1; //DQ��λ
	delay(8); //������ʱ
	DQ = 0; //��Ƭ����DQ����
	delay(80); //��ȷ��ʱ ���� 480us
	DQ = 1; //��������
	delay(14);
	x=DQ; //������ʱ�� ���x=0���ʼ���ɹ� x=1���ʼ��ʧ��
	delay(20);
}

//DS18B20��һ���ֽ�
uchar ReadOneChar(void)
{
	unsigned char i=0;
	unsigned char dat = 0;
	for (i=8;i>0;i--){
		DQ = 0; // �������ź�
		dat>>=1;
		DQ = 1; // �������ź�
		if(DQ)  dat|=0x80;
		delay(4);
		}
	return(dat);
}

//DS18B20дһ���ֽ�
void WriteOneChar(unsigned char dat)
{
	unsigned char i=0;
	for (i=8; i>0; i--){
		DQ = 0;
		DQ = dat&0x01;
		delay(5);
		DQ = 1;
		dat>>=1;
		}
}

//DS18B20��ȡ�¶�
uint ReadTemperature(void)
{
	unsigned char a=0;
	unsigned char b=0;
	unsigned int t=0;
	float tt=0;
	Init_DS18B20();
	WriteOneChar(0xCC); // ����������кŵĲ���
	WriteOneChar(0x44); // �����¶�ת��
	Init_DS18B20();
	WriteOneChar(0xCC); //����������кŵĲ���
	WriteOneChar(0xBE); //��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
	a=ReadOneChar();
	b=ReadOneChar();
	t=b;
	t<<=8;
	t=t|a;
	tt=t*0.0625; //���¶ȵĸ�λ���λ�ϲ�
	t= tt*10+0.5; //�Խ������4��5��
	return(t);
}