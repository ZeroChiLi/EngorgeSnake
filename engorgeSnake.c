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

	startGame(&snake,&feed);							//��ʼ����Ϸ��Ա����

	while (1)
	{			
		initRedMatrix();	   							//��ʼ�����̵���				
		initGreenMatrix();	  

		keyNum = key_Scan();							//ɨ�����

		if (keyNum == RESTART_GAME)						//����key1����������Ϸ
		{
			startGame(&snake,&feed);
			continue;
		}
		
		if (isDirection(keyNum))					    //�ж��Ƿ�Ϊ����
			snakeSetDir(&snake, keyNum);
		
		snakeMove(&snake);								//������λ��

		if (!feedExist(feed))							//�ж��Ƿ����ʳ��,û�оͼӰ�
			feedsetPos(&feed, getRandomFreePos());
		
		feedShow(&feed);								//��ʾʳ��
							 
		updateCol();									//����ÿ����ֵ

		showMatrix(1000);								//��ʾ���̵���

		if (snakeCollision(&snake, &feed))				//�����ײ(������ʳ��)
			startGame(&snake,&feed);
	}
}

void startGame(Snake * snake, Feed * feed)
{
	initSnake(snake);
	initFeed(feed);
}
