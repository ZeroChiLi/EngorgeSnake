#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"

void startGame(Snake * snake,Food * food);

unsigned char updateByKeyboard(Snake * snake, Food * food);

void updateFood(Food * food);

void main(void)
{		 
	unsigned char keyNum = 0;
	Snake snake;
	Food food;

	startGame(&snake,&food);							//初始化游戏成员对象

	while (1)
	{			
		initRedMatrix();	   							//初始化红绿点阵				
		initGreenMatrix();	  

	//	if(updateByKeyboard(&snake,&food) == 0)			//通过键盘更新蛇方向，重启游戏。
	//		continue;

		snakeMove(&snake);								//更新蛇位置

		updateFood(&food);								//更新食物
							 
		updateCol();									//更新每列数值

		showMatrix(1000);								//显示红绿点阵

		if (snakeCollision(&snake, &food) || updateByKeyboard(&snake,&food) == 0)				//检测碰撞(包括吃食物)
			startGame(&snake,&food);
	}
}

void startGame(Snake * snake, Food * food)
{
	initSnake(snake);
	initFood(food);
}
	   
unsigned char updateByKeyboard(Snake * snake, Food * food)
{		 
	unsigned char keyNum = 0;
    keyNum = key_Scan();									//扫描键盘

	if (isDirection(getDirectionFromKey(keyNum)))		 	//判断是否为方向
		snakeSetDir(snake, getDirectionFromKey(keyNum));

	if (onClickRestartKey(keyNum))							//按了key1就是重启游戏
		return 0;
	return 1;
}

void updateFood(Food * food)
{
	if (!foodExist(food))							//判断是否存在食物,没有就加啊
		foodsetPos(food, getRandomFreePos());
	
	foodShow(food);								//显示食物
}