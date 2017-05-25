#ifndef _FOOD_H_
#define _FOOD_H_
					
#include "Point.h"

typedef struct Food
{
	unsigned char exist;
	Point position;
}Food;


//��ʼ��ʳ��
extern void InitFood(Food *food);

//ȡ��������˺���λ��
extern unsigned char GetRandomFreePos();

//����ʳ��λ��
extern void FoodsetPos(Food *food,unsigned char pos);

//����0��ʾ������û���㹻ʳ��
extern unsigned char FoodEaten(Food *food);

//�ж��Ƿ����ʳ��
extern unsigned char FoodExist(Food * food);

//��ʾʳ��
extern void FoodShow(Food *food);


#endif