#ifndef _KEYBOARD_INPUT_H_
#define _KEYBOARD_INPUT_H_
	   
#include <reg51.h>
#include "InitConst.h"	 

#define GPIO_KEY		P3  //独立键盘用P3口

//检测按键
extern unsigned char Key_Scan();

//按键转换成方向
extern Direction GetDirectionFromKey(unsigned char key);

//是否按了重启游戏
extern unsigned char OnClickRestartKey(unsigned char key);

#endif