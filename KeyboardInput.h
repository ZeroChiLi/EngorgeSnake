#ifndef _KEYBOARD_INPUT_H_
#define _KEYBOARD_INPUT_H_
	   
#include <reg51.h>
#include "InitConst.h"	 

#define GPIO_KEY		P3  //����������P3��

//��ⰴ��
extern unsigned char Key_Scan();

//����ת���ɷ���
extern Direction GetDirectionFromKey(unsigned char key);

//�Ƿ���������Ϸ
extern unsigned char OnClickRestartKey(unsigned char key);

#endif