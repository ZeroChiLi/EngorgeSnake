#include "Food.h"					  
#include "MatrixLED.h"
#include <stdlib.h> //rand()º¯Êý

void InitFood(Food *food)
{					
	(*food).exist = 1;
	FoodsetPos(food, GetRandomFreePos());	
}

unsigned char GetRandomFreePos()
{
	unsigned char i, j, freeSize = 0,freePos[64];
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (_redMatrix[i][j] == 0)
				freePos[freeSize++] = XYToInt(j + 1, i + 1);
	return freePos[rand() % freeSize];
}

void FoodsetPos(Food *food, unsigned char pos)
{
	(*food).position = IntToPoint(pos);
	(*food).exist = 1;
}

unsigned char FoodEaten(Food *food)
{
	if (!FoodExist(food))
		return 0;
	(*food).exist = 0;
	InitGreenMatrix();
	return 1;
}

unsigned char FoodExist(Food * food) 
{ 
	return (*food).exist; 
}

void FoodShow(Food *food)
{
	if (!FoodExist(food))
		return;
	AddPointToGreenMat((*food).position);
}

