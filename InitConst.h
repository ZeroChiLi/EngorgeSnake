#ifndef _INIT_CONST_H_
#define _INIT_CONST_H_	  
	   
#include <reg51.h>	 
#include <intrins.h>

#define COMMONPORTS		P0	//�����п�
#define READPORTS 		P2	//�����п� ��ɫ
#define GREENPORTS 		P1  //�����п� ��ɫ


//����,�������� k3 k6 k7 k8
typedef enum DIRECTION
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
}Direction;		   


//�ж��Ƿ�Ϊ����
extern unsigned char IsDirection(Direction dir);

//��ʱ
extern void DelayMs(unsigned int x);
				
//��ȡ�����������ֵ
extern int getMax(int a,inte b);	


#endif