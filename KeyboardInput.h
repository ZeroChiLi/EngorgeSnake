#ifndef _KEYBOARD_INPUT_H_
#define _KEYBOARD_INPUT_H_
	   
#include <reg51.h>
#include "InitConst.h"	 

#define GPIO_KEY		P1  //����������P1��

//��ⰴ��
extern unsigned char key_Scan();

//����ת���ɷ���
extern Direction getDirectionFromKey(unsigned char key);

//�Ƿ���������Ϸ
extern unsigned char onClickRestartKey(unsigned char key);

#endif