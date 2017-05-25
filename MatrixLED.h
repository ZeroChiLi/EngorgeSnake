#ifndef _INIT_GAME_H_
#define _INIT_GAME_H_
	 					
#include "Point.h"
#include "InitConst.h"

								
//�� ������
extern unsigned char code COL[8];									  
								  
//����������,��ֵ������еĵ�ǰֵ
extern unsigned char _currentRedCOL[8];	 

extern unsigned char _currentGreenCOL[8];

//��ǰ������Ƿ�����
extern unsigned char _redMatrix[8][8];

//��ǰ�̵����Ƿ�����
extern unsigned char _greenMatrix[8][8];


//��ʼ������� ���Ͻ�Ϊԭ��
extern void InitRedMatrix();

//��ʼ���̵��� ���Ͻ�Ϊԭ��
extern void InitGreenMatrix();

//��ʼ����ǰÿ��ֵ
extern void InitCurrentCOL();

//��ӵ㵽�����
extern void AddPointToRedMat(const Point point);

//��ӵ㵽�̵���
extern void AddPointToGreenMat(const Point point);

//���µ�ǰÿ�е���ֵ
extern void UpdateCol();

//��ʾ��ǰ����,����ʱ��
extern void ShowMatrix(unsigned int showTime);




#endif
				  			   