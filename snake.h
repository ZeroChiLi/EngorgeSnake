#ifndef _SNAKE_H_
#define _SNAKE_H_
							
#include "InitConst.h"
#include "Point.h"
#include "Food.h"

typedef struct SNAKE
{
	//�˶�����
	Direction _direction;

	//���峤�ȣ�����ͷ
	unsigned char _length;

	//����ÿ����λλ��,0Ϊͷ
	Point _body[64];
}Snake;

//Ĭ�ϳ�ʼ����
extern void initSnake(Snake * snake);

//����ͷλ��
extern unsigned char snakeSetHead(Snake * snake, Point point);

//�����忩
extern void snakeAddBody(Snake * snake, Point point);

//��ȡͷָ��
extern Point * snakeGetHead(Snake * snake);

//���÷���,����ͷ
extern void snakeSetDir(Snake * snake, Direction dir);

//�ж���ײ ,����1Ϊ��ײ,�������ʳ��,�ͱ䳤
extern unsigned char snakeCollision(Snake *snake,Food *food);

//������λ�ã�����ͷ
extern void snakeMove(Snake *snake);

//�ƶ���ͷλ��
extern void snakeHeadMove(Snake *snake);

#endif