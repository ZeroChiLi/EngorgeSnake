#include "Food.h"					  
#include "MatrixLED.h"
#include <stdlib.h> //rand()º¯Êý

void initFood(Food *food)
{					
	(*food).exist = 1;
	foodsetPos(food, getRandomFreePos());	
}

unsigned char getRandomFreePos()
{
	unsigned char i, j, freeSize = 0,freePos[64];
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (redMatrix[i][j] == 0)
				freePos[freeSize++] = xyToInt(j + 1, i + 1);
	return freePos[rand() % freeSize];
}

void foodsetPos(Food *food, unsigned char pos)
{
	(*food).position = intToPoint(pos);
	(*food).exist = 1;
}

unsigned char foodEaten(Food *food)
{
	if (!foodExist(food))
		return 0;
	(*food).exist = 0;
	initGreenMatrix();
	return 1;
}

unsigned char foodExist(Food * food) 
{ 
	return (*food).exist; 
}

void foodShow(Food *food)
{
	if (!foodExist(food))
		return;
	addPointToGreenMat((*food).position);
}

