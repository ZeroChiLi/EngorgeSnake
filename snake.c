#include "Snake.h"
#include "MatrixLED.h"

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
		if (headX == (*food).position.x && headY == (*food).position.y)
		{
			++(*snake)._length;
			foodEaten(food);
			return 0;
		}
	//碰撞自己身体
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
		addPointToRedMat((*snake)._body[i]);
	}

	snakeHeadMove(snake);	  
	addPointToRedMat(*snakeGetHead(snake));
}


void snakeHeadMove(Snake *snake)
{
	Point * head = snakeGetHead(snake);
	Direction dir = (*snake)._direction;

	switch (dir)
	{
	case(UP):
	{
		(*head).y = (*head).y == 1 ? 8 : (*head).y - 1;
		break;
	}
	case(DOWN):
	{
		(*head).y = (*head).y == 8 ? 1 : (*head).y + 1;
		break;
	}
	case(LEFT):
	{
		(*head).x = (*head).x == 1 ? 8 : (*head).x - 1;
		break;
	}
	case(RIGHT):
	{
		(*head).x = (*head).x == 8 ? 1 : (*head).x + 1;
		break;
	}
	default:
		break;
	}
}