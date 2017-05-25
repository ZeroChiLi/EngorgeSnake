#ifndef _SNAKE_H_
#define _SNAKE_H_
							
#include "InitConst.h"
#include "Point.h"
#include "Food.h"

typedef struct SNAKE
{
	//运动方向
	Direction _direction;

	//身体长度，包括头
	unsigned char _length;

	//身体每个部位位置,0为头
	Point _body[64];
}Snake;

//默认初始化蛇
extern void initSnake(Snake * snake);

//设置头位置
extern unsigned char snakeSetHead(Snake * snake, Point point);

//长身体咯
extern void snakeAddBody(Snake * snake, Point point);

//获取头指针
extern Point * snakeGetHead(Snake * snake);

//设置方向,依据头
extern void snakeSetDir(Snake * snake, Direction dir);

//判断碰撞 ,返回1为碰撞,如果碰到食物,就变长
extern unsigned char snakeCollision(Snake *snake,Food *food);

//更新蛇位置，包括头
extern void snakeMove(Snake *snake);

//移动的头位置
extern void snakeHeadMove(Snake *snake);

#endif