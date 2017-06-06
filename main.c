#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"
#include "InfraredInput.h"

void StartGame(Snake * snake,Food * food);				//初始化蛇和食物

unsigned char UpdateByKeyboard(Snake * snake);		   	//根据键盘输入更新

unsigned char UpdateByInfrared(Snake * snake);			//根据红外遥控输入更新
								
void UpdateFood(Food * food);							//更新食物

void main(void)
{		 
	int startPeriod = 1000;								//初始周期 ，越大越慢
	int minPeriod = 500;								//最短周期
	int gradient = 50;									//难度梯度

	Snake snake;										//蛇对象
	Food food;										   	//食物对象

	IrInit(); 											//红瓦遥控初始化

	StartGame(&snake,&food);							//初始化游戏成员对象

	while (1)
	{			
		InitRedMatrix();	   							//初始化红绿点阵				
		InitGreenMatrix();	  

		//检测碰撞(包括吃食物),碰到自己返回1，如果输入到重启键，返回0
		if (SnakeCollision(&snake, &food) || UpdateByKeyboard(&snake) == 0 || UpdateByInfrared(&snake) == 0)
		{		
			ShowExplode(500);		
			StartGame(&snake,&food);
			continue;
		}

		SnakeMove(&snake);								//更新蛇位置

		UpdateFood(&food);								//更新食物
							 
		UpdateCol();									//检查并更新每列数值

		ShowMatrix(getMax(startPeriod - snake._length * gradient,minPeriod));	//显示红绿点阵，参数是周期。
	}
}

void StartGame(Snake * snake, Food * food)
{
	InitSnake(snake);
	InitFood(food);
}	   
void UpdateFood(Food * food)
{
	if (!FoodExist(food))							//判断是否存在食物,没有就加啊
		FoodsetPos(food, GetRandomFreePos());
	
	FoodShow(food);								//显示食物
}

unsigned char UpdateByKeyboard(Snake * snake)
{		 
	unsigned char keyNum = 0;

    keyNum = Key_Scan();									//扫描键盘

	if (IsDirection(GetDirectionFromKey(keyNum)))		 	//判断是否为方向
		SnakeSetDir(snake, GetDirectionFromKey(keyNum));

	if (OnClickRestartKey(keyNum))							//按了key1就是重启游戏
		return 0;
	return 1;
}


unsigned char UpdateByInfrared(Snake * snake)
{
    unsigned char currentValue = 0;

	currentValue = GetCurrentKey();
			  
	if (IsDirection(GetDirectionFromControlValue(currentValue)))
		SnakeSetDir(snake, GetDirectionFromControlValue(currentValue));

	if (OnClickPowerControlKey(currentValue))
		return 0;
	return 1;
}

