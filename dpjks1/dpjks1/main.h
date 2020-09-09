#ifndef __MAIN_H__
#define __MAIN_H__

#define uint unsigned int
#define uchar unsigned char

#include <reg52.h>
#include <intrins.h>
#include "motordriver.h"
#include "ds1302.h"
#include "18b20.h"
#include "lcd1602.h"
#include "lumination.h"
#include "i2c.h"
#include "delay.h"
#include "bt.h"
#include "lcd12864.h"
//#include "control.h"

void sys_init();
void display(void);
void motor_control(void);

extern uint MODE; //mode��0�� �Զ�ģʽ  1���ֶ��Լ�����ģʽ 
extern uint temp; //�¶�ֵ
extern uint temp1;//��ǿ
extern unsigned char MotorFlag;  
extern unsigned char MotorState; //����״̬
#endif

