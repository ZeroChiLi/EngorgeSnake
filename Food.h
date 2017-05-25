#ifndef _FOOD_H_
#define _FOOD_H_
					
#include "MatrixLED.h"

typedef struct Food
{
	unsigned char count;
	unsigned char x;
	unsigned char y;
}Food;


//��ʼ��ʳ��
extern void initFood(Food *food);

//ȡ��������˺���λ��
extern unsigned char getRandomFreePos();

//����ʳ��λ��
extern void foodsetPos(Food *food,unsigned char pos);

//����0��ʾ������û���㹻ʳ��
extern unsigned char foodEaten(Food *food);

//�ж��Ƿ����ʳ��
extern unsigned char foodExist(Food * food);

//��ʾʳ��
extern void foodShow(Food *food);


#endif