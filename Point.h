#ifndef _POINT_H_
#define _POINT_H_

//�����
typedef struct POINT
{
	unsigned char x;
	unsigned char y;
}Point;

//�����ת��������ֵ��8*8����
extern unsigned char PointToInt(const Point p);

//XY����ת��������ֵ
extern unsigned char XYToInt(const int x, const int y); 

//����ֵת���ɵ����
extern Point IntToPoint(unsigned char num);

#endif