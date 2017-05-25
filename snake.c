#include "Snake.h"

void initSnake(Snake * snake)
{
	Point p;
	p.x = 5;
	p.y = 6;
	(*snake)._direction = UP;
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
	if (((*snake)._direction == UP && dir == DOWN) ||
		((*snake)._direction == DOWN && dir == UP) ||
		((*snake)._direction == LEFT && dir == RIGHT) ||
		((*snake)._direction == RIGHT && dir == LEFT))
		return;
	(*snake)._direction = dir; 
}

unsigned char snakeCollision(Snake *snake, Food *food)
{
	unsigned char headX = (*snake)._body[0].x;
	unsigned char headY = (*snake)._body[0].y;
	unsigned char i = 1;
	if (food != 0)
		if (headX == (*food).x && headY == (*food).y)
		{
			++(*snake)._length;
			foodEaten(food);
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

	snakeHeadMove(snake);
}


void snakeHeadMove(Snake *snake)
{
	Point * p = &(*snake)._body[0];
	Direction dir = (*snake)._direction;

	switch (dir)
	{
	case(UP):
	{
		(*p).y = (*p).y == 1 ? 8 : (*p).y - 1;
		break;
	}
	case(DOWN):
	{
		(*p).y = (*p).y == 8 ? 1 : (*p).y + 1;
		break;
	}
	case(LEFT):
	{
		(*p).x = (*p).x == 1 ? 8 : (*p).x - 1;
		break;
	}
	case(RIGHT):
	{
		(*p).x = (*p).x == 8 ? 1 : (*p).x + 1;
		break;
	}
	default:
		break;
	}
}