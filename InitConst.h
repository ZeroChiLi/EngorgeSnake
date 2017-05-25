#ifndef _INIT_CONST_H_
#define _INIT_CONST_H_	  
	   
#include <reg51.h>	 
#include <intrins.h>

#define COMMONPORTS		P0	//�����п�
#define READPORTS 		P2	//�����п� ��ɫ
#define GREENPORTS 		P3  //�����п� ��ɫ


//����,�������� k3 k6 k7 k8
typedef enum DIRECTION
{
	UP = 0xFB,
	DOWN = 0xBF,
	LEFT = 0xDF,
	RIGHT = 0x7F
}Direction;		   


//�ж��Ƿ�Ϊ����
extern unsigned char isDirection(Direction dir);

//��ʱ,��λms
extern void delayms(unsigned int c);

#endif