#ifndef _INIT_GAME_H_
#define _INIT_GAME_H_
	 					
#include "Point.h"
#include "InitConst.h"

								
//�� ������
extern unsigned char code COL[8];									  

//����������,��ֵ������еĵ�ǰֵ
extern unsigned char currentRedCOL[8];

//��ǰ������Ƿ�����
extern unsigned char redMatrix[8][8];

//��ǰ�̵����Ƿ�����
extern unsigned char greenMatrix[8][8];


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

//��ʾ��ǰ����,����ʱ��
extern void showMatrix(unsigned int showTime);




#endif
				  			   