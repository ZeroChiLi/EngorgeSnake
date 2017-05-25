#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"

void startGame(Snake * snake,Food * food);

unsigned char updateByKeyboard(Snake * snake, Food * food);

void updateFood(Food * food);

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

	//	if(updateByKeyboard(&snake,&food) == 0)			//ͨ�����̸����߷���������Ϸ��
	//		continue;

		snakeMove(&snake);								//������λ��

		updateFood(&food);								//����ʳ��
							 
		updateCol();									//����ÿ����ֵ

		showMatrix(1000);								//��ʾ���̵���

		if (snakeCollision(&snake, &food) || updateByKeyboard(&snake,&food) == 0)				//�����ײ(������ʳ��)
			startGame(&snake,&food);
	}
}

void startGame(Snake * snake, Food * food)
{
	initSnake(snake);
	initFood(food);
}
	   
unsigned char updateByKeyboard(Snake * snake, Food * food)
{		 
	unsigned char keyNum = 0;
    keyNum = key_Scan();									//ɨ�����

	if (isDirection(getDirectionFromKey(keyNum)))		 	//�ж��Ƿ�Ϊ����
		snakeSetDir(snake, getDirectionFromKey(keyNum));

	if (onClickRestartKey(keyNum))							//����key1����������Ϸ
		return 0;
	return 1;
}

void updateFood(Food * food)
{
	if (!foodExist(food))							//�ж��Ƿ����ʳ��,û�оͼӰ�
		foodsetPos(food, getRandomFreePos());
	
	foodShow(food);								//��ʾʳ��
}