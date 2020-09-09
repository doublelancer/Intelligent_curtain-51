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

extern uint MODE; //mode：0； 自动模式  1；手动以及蓝牙模式 
extern uint temp; //温度值
extern uint temp1;//光强
extern unsigned char MotorFlag;  
extern unsigned char MotorState; //窗帘状态
#endif

