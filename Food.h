#ifndef _FOOD_H_
#define _FOOD_H_
					
#include "MatrixLED.h"

typedef struct Food
{
	unsigned char count;
	unsigned char x;
	unsigned char y;
}Food;


//初始化食物
extern void initFood(Food *food);

//取得随机除了红点的位置
extern unsigned char getRandomFreePos();

//设置食物位置
extern void foodsetPos(Food *food,unsigned char pos);

//返回0表示本来就没有足够食物
extern unsigned char foodEaten(Food *food);

//判断是否存在食物
extern unsigned char foodExist(Food * food);

//显示食物
extern void foodShow(Food *food);


#endif