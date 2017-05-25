#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"

#define RESTART_GAME 0xFE

void startGame(Snake * snake,Food * food);

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

		keyNum = key_Scan();							//扫描键盘

		if (keyNum == RESTART_GAME)						//按了key1就是重启游戏
		{
			startGame(&snake,&food);
			continue;
		}
		
		if (isDirection(keyNum))					    //判断是否为方向
			snakeSetDir(&snake, keyNum);
		
		snakeMove(&snake);								//更新蛇位置
		updateRedMat((*snakeGetHead(&snake)));

		if (!foodExist(&food))							//判断是否存在食物,没有就加啊
			foodsetPos(&food, getRandomFreePos());
		
		foodShow(&food);								//显示食物
							 
		updateCol();									//更新每列数值

		showMatrix(1000);								//显示红绿点阵

		if (snakeCollision(&snake, &food))				//检测碰撞(包括吃食物)
			startGame(&snake,&food);
	}
}

void startGame(Snake * snake, Food * food)
{
	initSnake(snake);
	initFood(food);
}
