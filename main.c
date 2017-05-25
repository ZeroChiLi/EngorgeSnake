#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"
#include "InfraredInput.h"

void StartGame(Snake * snake,Food * food);

unsigned char UpdateByKeyboard(Snake * snake);

unsigned char UpdateByInfrared(Snake * snake);
								
void UpdateFood(Food * food);

void main(void)
{		 
	unsigned char keyNum = 0;
	Snake snake;
	Food food;

	IrInit();

	StartGame(&snake,&food);							//初始化游戏成员对象

	while (1)
	{			
		InitRedMatrix();	   							//初始化红绿点阵				
		InitGreenMatrix();	  

		SnakeMove(&snake);								//更新蛇位置

		UpdateFood(&food);								//更新食物
							 
		UpdateCol();									//更新每列数值

		ShowMatrix(1000);								//显示红绿点阵

		//检测碰撞(包括吃食物),碰到自己返回1，如果输入到重启键，返回0
		if (SnakeCollision(&snake, &food) || UpdateByKeyboard(&snake) == 0 || UpdateByInfrared(&snake) == 0)				
			StartGame(&snake,&food);
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




