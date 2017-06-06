#include "MatrixLED.h"
#include "Snake.h"
#include "Food.h"
#include "KeyboardInput.h"
#include "InfraredInput.h"

void StartGame(Snake * snake,Food * food);				//��ʼ���ߺ�ʳ��

unsigned char UpdateByKeyboard(Snake * snake);		   	//���ݼ����������

unsigned char UpdateByInfrared(Snake * snake);			//���ݺ���ң���������
								
void UpdateFood(Food * food);							//����ʳ��

void main(void)
{		 
	int startPeriod = 1000;								//��ʼ���� ��Խ��Խ��
	int minPeriod = 500;								//�������
	int gradient = 50;									//�Ѷ��ݶ�

	Snake snake;										//�߶���
	Food food;										   	//ʳ�����

	IrInit(); 											//����ң�س�ʼ��

	StartGame(&snake,&food);							//��ʼ����Ϸ��Ա����

	while (1)
	{			
		InitRedMatrix();	   							//��ʼ�����̵���				
		InitGreenMatrix();	  

		//�����ײ(������ʳ��),�����Լ�����1��������뵽������������0
		if (SnakeCollision(&snake, &food) || UpdateByKeyboard(&snake) == 0 || UpdateByInfrared(&snake) == 0)
		{		
			ShowExplode(500);		
			StartGame(&snake,&food);
			continue;
		}

		SnakeMove(&snake);								//������λ��

		UpdateFood(&food);								//����ʳ��
							 
		UpdateCol();									//��鲢����ÿ����ֵ

		ShowMatrix(getMax(startPeriod - snake._length * gradient,minPeriod));	//��ʾ���̵��󣬲��������ڡ�
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

