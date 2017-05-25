#ifndef _FOOD_H_
#define _FOOD_H_
					
#include "Point.h"

typedef struct Food
{
	unsigned char exist;
	Point position;
}Food;


//初始化食物
extern void InitFood(Food *food);

//取得随机除了红点的位置
extern unsigned char GetRandomFreePos();

//设置食物位置
extern void FoodsetPos(Food *food,unsigned char pos);

//返回0表示本来就没有足够食物
extern unsigned char FoodEaten(Food *food);

//判断是否存在食物
extern unsigned char FoodExist(Food * food);

//显示食物
extern void FoodShow(Food *food);


#endif