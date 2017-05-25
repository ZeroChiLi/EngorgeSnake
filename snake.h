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
extern void InitSnake(Snake * snake);

//����ͷλ��
extern unsigned char SnakeSetHead(Snake * snake, Point point);

//�����忩
extern void SnakeAddBody(Snake * snake, Point point);

//��ȡͷָ��
extern Point * SnakeGetHead(Snake * snake);

//���÷���,����ͷ
extern void SnakeSetDir(Snake * snake, Direction dir);

//�ж���ײ ,����1Ϊ��ײ,�������ʳ��,�ͱ䳤
extern unsigned char SnakeCollision(Snake *snake,Food *food);

//������λ�ã�����ͷ
extern void SnakeMove(Snake *snake);

//�ƶ���ͷλ��
extern void SnakeHeadMove(Snake *snake);

#endif