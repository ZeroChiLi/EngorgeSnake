#include "initGame.h"
#include "snake.h"
#include "feed.h"

#define RESTART_GAME 0xFE

void startGame(Snake * snake,Feed * feed);

void main(void)
{
	unsigned char keyNum = 0;		 
	Snake snake;
	Feed feed;

	startGame(&snake,&feed);							//初始化游戏成员对象

	while (1)
	{			
		initRedMatrix();	   							//初始化红绿点阵				
		initGreenMatrix();	  

		keyNum = key_Scan();							//扫描键盘

		if (keyNum == RESTART_GAME)						//按了key1就是重启游戏
		{
			startGame(&snake,&feed);
			continue;
		}
		
		if (isDirection(keyNum))					    //判断是否为方向
			snakeSetDir(&snake, keyNum);
		
		snakeMove(&snake);								//更新蛇位置

		if (!feedExist(feed))							//判断是否存在食物,没有就加啊
			feedsetPos(&feed, getRandomFreePos());
		
		feedShow(&feed);								//显示食物
							 
		updateCol();									//更新每列数值

		showMatrix(1000);								//显示红绿点阵

		if (snakeCollision(&snake, &feed))				//检测碰撞(包括吃食物)
			startGame(&snake,&feed);
	}
}

void startGame(Snake * snake, Feed * feed)
{
	initSnake(snake);
	initFeed(feed);
}
