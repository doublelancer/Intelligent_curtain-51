//#include "main.h"
#include "uart.h"
#include "reg51.h"
#include "stdio.h"
uchar uart_flag=0;     //����ͨ�ű�־λ
uchar uart_data;     //����ͨ������λ
uchar uart_permit;   //���������־λ
uchar data_receive;  //���ݽ���
char buf_string[14];  //�������ݰ�����Ϊ14����λ

/*******************************
*����ͨ�ų�ʼ��
*******************************/

void UART_Init()
{
	SCON=0x50;			//����Ϊ������ʽ1
	TMOD=0x20;			//���ü�����������ʽ2
	PCON=0x80;			//�����ʼӱ�
	TH1=0xfd;				
	TL1=0xfd;       //���ϲ������ݾ��������
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					//�򿪼�����
}


/*************************************
*���ڷ���
**************************************/
//void PutString(uchar *TXStr)  
//{                
//    ES=0;     
//     while(*TXStr!=0) 
//    {                      
//        SBUF=*TXStr;
//        while(TI==0);
//        TI=0;    
//        TXStr++;
//    }
//    ES=1; 
//}      

/************************************
*���ڽ���
*		�������ݵȴ��ӳ٣��ȴ�ʱ��̫�ûᵼ��CPU�������ã�̫�̻����"���ݰ����ָ�",Ĭ��count=130
*************************************/
bit ReceiveString()    
{
    char * RecStr=buf_string;
    char num=0;
    unsigned char count=0;
    loop:    
    *RecStr=SBUF;
    count=0;
    RI=0;    
    if(num<13)  //���ݰ�����Ϊ14���ַ�,������������14���ַ�
    {
        num++;
        RecStr++;    
        while(!RI)
        {
            count++;
            if(count>130)return 0;   
        }
        goto loop;
    }
    return 1;
}


/*************************************
*����ͨ���жϺ���
**************************************/
void UART() interrupt 4//�����жϺ���
{
	
	if(ReceiveString())
	{
	  RI=0;
	}
}

//���ˣ����͵����ݴ������ַ�����buf_string
