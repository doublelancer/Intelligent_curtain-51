#include "reg52.h"	
#include "main.h"



/*******************************************************************************
* ������         :UartInit()
* ��������		   :���ô���
* ����           : ��
* ���         	 : ��
*******************************************************************************/
//void UartInit()
//{
//	SCON=0X50;			//����Ϊ������ʽ1
//	TMOD=0X20;			//���ü�����������ʽ2
//	PCON=0X80;			//�����ʼӱ�
//	TH1=0XF3;				//��������ʼֵ���ã�ע�Ⲩ������4800��
//	TL1=0XF3;
//	ES=1;						//�򿪽����ж�
//	EA=1;						//�����ж�
//	TR1=1;					//�򿪼�����
//}

void UartInit(void)
{
   TMOD = 0x20;  //9600
    SCON = 0x50;
    TH1 = 0xFD;
    TL1 = TH1;
    PCON = 0x00;
    EA = 1;
    ES = 1;
    TR1 = 1;
}
void uart_tx_byte(uchar str){
  SBUF=str;
	while(TI==0);
	//if(TI)  //����Ƿ��ͱ�־λ������
     TI=0;
}

//void Uart() interrupt 4
//{
//	u8 receiveData;

//	receiveData=SBUF;//��ȥ���յ�������
//	RI = 0;//��������жϱ�־λ
//	SBUF=receiveData;//�����յ������ݷ��뵽���ͼĴ���
//	while(!TI);			 //�ȴ������������
//	TI=0;						 //���������ɱ�־λ
//}

//void UART_SER (void) interrupt 4 //�����жϷ������
//{
//    unsigned char Temp;          //������ʱ���� 
//    unsigned char i;
//    if(RI)                        //�ж��ǽ����жϲ���
//     {
//	   RI=0;                      //��־λ����
//	  Temp=SBUF;                 //���뻺������ֵ
//		if(Temp=='m')
//			 {
//				 MODE=!MODE;
//				 SBUF=MODE;
//			 }
//			 
//	 if(Temp=='k')
//			 {
//				 Motor_Flag=1;
//				 SBUF=Temp;
//			 }
//	if(Temp=='b')
//			 {
//				 Motor_Flag=2;
//				 SBUF=Temp;
//			 }
//			 
//   if(Temp=='s')
//			 {
//				 ShowP=1;
//				 SBUF=Temp;
//			 }
//			 
//		if(Temp=='t')
//			 {
//				 SetTime=1;
//				 SBUF=Temp;	
//			 }
//			 
//     if(SetTime)
//		{
//	  time_buf2[i]=Temp&0x0F;
//	  i++;
//	  if(i==16)                  //��������16���ַ���Ϣ
//	   {
//	    i=0;
//		SetFlag=1;               //������ɱ�־λ��1
//		SetTime=0;
//	   }
//      SBUF=Temp; //�ѽ��յ���ֵ�ٷ��ص��Զ�
//	 }
//   
//	 }
//		//while(!TI);			 //�ȴ������������ 
//   if(TI)  //����Ƿ��ͱ�־λ������
//     TI=0;

//}

//void Usart() interrupt 4
//{
//	 
//				
//unsigned char receiveData;

//receiveData=SBUF;//��ȥ���յ�������
//	
//	
////������жϵ��ַ�����д��buf_string��	
//buf_string[length]=SBUF;
//length++;
//	
//	
//RI = 0;//��������жϱ�־λ
//SBUF=receiveData;//�����յ������ݷ��뵽���ͼĴ���
//while(!TI);			 //�ȴ������������
//TI=0;						 //���������ɱ�־λ
//				
//}