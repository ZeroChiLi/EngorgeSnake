#ifndef _POINT_H_
#define _POINT_H_

//�����
typedef struct POINT
{
	unsigned char x;
	unsigned char y;
}Point;


//�����ת������
extern unsigned char pointToInt(const Point p);

//xy����ת��������ֵ��
extern unsigned char xyToInt(const int x,const int y);

//����ת�ɵ����
extern Point intToPoint(unsigned char num);


#endif