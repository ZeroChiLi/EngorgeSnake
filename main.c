#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"
#include "InfraredInput.h"

void StartGame(Snake * snake,Food * food);

unsigned char UpdateByKeyboard(Snake * snake);

unsigned char UpdateByInfrared(Snake * snake);
								
void UpdateFood(Food * food);

void main(void)
{		 
	unsigned char keyNum = 0;
	Snake snake;
	Food food;

	IrInit();

	StartGame(&snake,&food);							//��ʼ����Ϸ��Ա����

	while (1)
	{			
		InitRedMatrix();	   							//��ʼ�����̵���				
		InitGreenMatrix();	  

		SnakeMove(&snake);								//������λ��

		UpdateFood(&food);								//����ʳ��
							 
		UpdateCol();									//����ÿ����ֵ

		ShowMatrix(1000);								//��ʾ���̵���

		//�����ײ(������ʳ��),�����Լ�����1��������뵽������������0
		if (SnakeCollision(&snake, &food) || UpdateByKeyboard(&snake) == 0 || UpdateByInfrared(&snake) == 0)				
			StartGame(&snake,&food);
	}
}

void StartGame(Snake * snake, Food * food)
{
	InitSnake(snake);
	InitFood(food);
}
	   
void UpdateFood(Food * food)
{
	if (!FoodExist(food))							//�ж��Ƿ����ʳ��,û�оͼӰ�
		FoodsetPos(food, GetRandomFreePos());
	
	FoodShow(food);								//��ʾʳ��
}

unsigned char UpdateByKeyboard(Snake * snake)
{		 
	unsigned char keyNum = 0;

    keyNum = Key_Scan();									//ɨ�����

	if (IsDirection(GetDirectionFromKey(keyNum)))		 	//�ж��Ƿ�Ϊ����
		SnakeSetDir(snake, GetDirectionFromKey(keyNum));

	if (OnClickRestartKey(keyNum))							//����key1����������Ϸ
		return 0;
	return 1;
}


unsigned char UpdateByInfrared(Snake * snake)
{
    unsigned char currentValue = 0;

	currentValue = GetCurrentKey();
			  
	if (IsDirection(GetDirectionFromControlValue(currentValue)))
		SnakeSetDir(snake, GetDirectionFromControlValue(currentValue));

	if (OnClickPowerControlKey(currentValue))
		return 0;
	return 1;
}




