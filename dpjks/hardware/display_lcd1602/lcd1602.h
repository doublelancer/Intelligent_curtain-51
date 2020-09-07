#ifndef __LCD1602_H__
#define __LCD1602_H__

#include <reg52.h>
#include <intrins.h>
#include "main.h"
sbit lcd_rs_port = P3^5;  /*定义LCD控制端口*/
sbit lcd_rw_port = P3^6;
sbit lcd_en_port = P3^4;
#endif