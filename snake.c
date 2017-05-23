#include "snake.h"

void initSnake(Snake * snake)
{
	Point p;
	p.x = 5;
	p.y = 6;
	p.dir = UP;
	(*snake)._length = 0;
	snakeSetHead(snake, p);
}

unsigned char snakeSetHead(Snake * snake, Point point)
{
	if (snake == 0)
		return 0;
	snakeAddBody(snake, point);
	return 1;
}

void snakeAddBody(Snake *snake, Point point)
{
	(*snake)._body[(*snake)._length] = point;
	++(*snake)._length;
}

Point * snakeGetHead(Snake * snake) { return &((*snake)._body[0]); }

void snakeSetDir(Snake * snake, Direction dir) 
{ 
	Direction currentDir = (*snakeGetHead(snake)).dir;
	if ((currentDir == UP && dir == DOWN) ||
		(currentDir == DOWN && dir == UP) ||
		(currentDir == LEFT && dir == RIGHT) ||
		(currentDir == RIGHT && dir == LEFT))
		return;
	(*snakeGetHead(snake)).dir = dir; 
}

unsigned char snakeCollision(Snake *snake, Feed *feed)
{
	unsigned char headX = (*snake)._body[0].x;
	unsigned char headY = (*snake)._body[0].y;
	unsigned char i = 1;
	if (feed != 0)
		if (headX == (*feed).x && headY == (*feed).y)
		{
			++(*snake)._length;
			feedEaten(feed);
			return 0;
		}

	for (; i < (*snake)._length; ++i)
		if (headX == (*snake)._body[i].x && headY == (*snake)._body[i].y)
			return 1;
	return 0;
}

void snakeMove(Snake *snake)
{
	unsigned char i = (*snake)._length - 1;
	for (; i >= 1; --i)
	{
		(*snake)._body[i] = (*snake)._body[i - 1];
		updateRedMat((*snake)._body[i]);
	}
	movePoint(snakeGetHead(snake), (*snakeGetHead(snake)).dir);
	updateRedMat((*snakeGetHead(snake)));
}
