#ifndef _INIT_GAME_H_
#define _INIT_GAME_H_
	 						   
#include <reg51.h>	 
#include <intrins.h>
				  
#define GPIO_KEY		P1  //����������P1��

#define COMMONPORTS		P0
#define READPORTS 		P2
#define GREENPORTS 		P3
								
//�� ������
extern unsigned char code COL[8];									  

//����������,��ֵ������еĵ�ǰֵ
extern unsigned char currentRedCOL[8];

//��ǰ������Ƿ�����
extern unsigned char redMatrix[8][8];

//��ǰ�̵����Ƿ�����
extern unsigned char greenMatrix[8][8];

//����,�������� k3 k6 k7 k8
typedef enum DIRECTION
{
	UP = 0xFB,
	DOWN = 0xBF,
	LEFT = 0xDF,
	RIGHT = 0x7F
}Direction;

//�����
typedef struct POINT
{
	Direction dir;
	unsigned char x;
	unsigned char y;
}Point;

//��ʱ10ms
extern void delay10ms(unsigned int c);

//��ⰴ��
extern unsigned char key_Scan();

//�ƶ��ĵ�,����
extern void movePoint(Point *p, Direction dir);

//��ʼ������� ���Ͻ�Ϊԭ��
extern void initRedMatrix();

//��ʼ���̵��� ���Ͻ�Ϊԭ��
extern void initGreenMatrix();

//��ʼ����ǰÿ��ֵ
extern void initCurrentCOL();

//���º����
extern void updateRedMat(const Point point);

//�����̵���
extern void updateGreenMat(const Point point);
extern void updateGreenMatXY(const int x,const int y);

//���µ�ǰÿ�е���ֵ
extern void updateCol();

//��ʾ��ǰ����
extern void showMatrix(unsigned int delayTime);

//�ж��Ƿ�Ϊ����
extern unsigned char isDirection(Direction dir);

//xy����ת������
extern unsigned char pointToInt(const Point p);

extern unsigned char xyToInt(const int x,const int y);

//����ת��xy����
extern Point intToPoint(unsigned char num);


#endif
				  			   