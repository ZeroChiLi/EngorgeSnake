#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"

#define RESTART_GAME 0xFE

void startGame(Snake * snake,Food * food);

void main(void)
{
	unsigned char keyNum = 0;		 
	Snake snake;
	Food food;

	startGame(&snake,&food);							//��ʼ����Ϸ��Ա����

	while (1)
	{			
		initRedMatrix();	   							//��ʼ�����̵���				
		initGreenMatrix();	  

		keyNum = key_Scan();							//ɨ�����

		if (keyNum == RESTART_GAME)						//����key1����������Ϸ
		{
			startGame(&snake,&food);
			continue;
		}
		
		if (isDirection(keyNum))					    //�ж��Ƿ�Ϊ����
			snakeSetDir(&snake, keyNum);
		
		snakeMove(&snake);								//������λ��
		updateRedMat((*snakeGetHead(&snake)));

		if (!foodExist(&food))							//�ж��Ƿ����ʳ��,û�оͼӰ�
			foodsetPos(&food, getRandomFreePos());
		
		foodShow(&food);								//��ʾʳ��
							 
		updateCol();									//����ÿ����ֵ

		showMatrix(1000);								//��ʾ���̵���

		if (snakeCollision(&snake, &food))				//�����ײ(������ʳ��)
			startGame(&snake,&food);
	}
}

void startGame(Snake * snake, Food * food)
{
	initSnake(snake);
	initFood(food);
}
