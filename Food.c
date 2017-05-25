#include "Food.h"
#include <stdlib.h> //rand()º¯Êý

void initFood(Food *food)
{
	(*food).count = 0;
	foodsetPos(food, getRandomFreePos());
}


unsigned char getRandomFreePos()
{
	unsigned char i, j, freePos[64], freeSize = 0;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (redMatrix[i][j] == 0)
				freePos[freeSize++] = xyToInt(j + 1, i + 1);
	return freePos[rand() % freeSize];
}

void foodsetPos(Food *food, unsigned char pos)
{
	(*food).x = intToPoint(pos).x;
	(*food).y = intToPoint(pos).y;
	(*food).count = 1;
}

unsigned char foodEaten(Food *food)
{
	if (!foodExist(food))
		return 0;
	(*food).count = 0;
	initGreenMatrix();
	return 1;
}

unsigned char foodExist(Food * food) { return (*food).count == 0 ? 0 : 1; }

void foodShow(Food *food)
{
	if (!foodExist(food))
		return;
	updateGreenMatXY((*food).x, (*food).y);
}

