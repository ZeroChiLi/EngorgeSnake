#ifndef _POINT_H_
#define _POINT_H_

//点对象
typedef struct POINT
{
	unsigned char x;
	unsigned char y;
}Point;

//点对象转换成整数值（8*8矩阵）
extern unsigned char PointToInt(const Point p);

//XY坐标转换成整数值
extern unsigned char XYToInt(const int x, const int y); 

//整数值转换成点对象
extern Point IntToPoint(unsigned char num);

#endif