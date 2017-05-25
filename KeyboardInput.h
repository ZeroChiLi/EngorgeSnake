#ifndef _KEYBOARD_INPUT_H_
#define _KEYBOARD_INPUT_H_
	   
#include <reg51.h>
#include "InitConst.h"	 

#define GPIO_KEY		P1  //独立键盘用P1口

//检测按键
extern unsigned char key_Scan();

//按键转换成方向
extern Direction getDirectionFromKey(unsigned char key);

//是否按了重启游戏
extern unsigned char onClickRestartKey(unsigned char key);

#endif