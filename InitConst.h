#ifndef _INIT_CONST_H_
#define _INIT_CONST_H_	  
	   
#include <reg51.h>	 
#include <intrins.h>

#define COMMONPORTS		P0	//点阵行控
#define READPORTS 		P2	//点阵列控 红色
#define GREENPORTS 		P1  //点阵列控 绿色


//方向,独立键盘 k3 k6 k7 k8
typedef enum DIRECTION
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
}Direction;		   


//判断是否为方向
extern unsigned char IsDirection(Direction dir);

//延时
extern void DelayMs(unsigned int x);
				
//获取两个数的最大值
extern int getMax(int a,inte b);	


#endif