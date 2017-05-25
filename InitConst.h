#ifndef _INIT_CONST_H_
#define _INIT_CONST_H_	  
	   
#include <reg51.h>	 
#include <intrins.h>

#define COMMONPORTS		P0	//点阵行控
#define READPORTS 		P2	//点阵列控 红色
#define GREENPORTS 		P3  //点阵列控 绿色


//方向,独立键盘 k3 k6 k7 k8
typedef enum DIRECTION
{
	UP = 0xFB,
	DOWN = 0xBF,
	LEFT = 0xDF,
	RIGHT = 0x7F
}Direction;		   


//判断是否为方向
extern unsigned char isDirection(Direction dir);

//延时,单位ms
extern void delayms(unsigned int c);

#endif