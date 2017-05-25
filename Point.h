#ifndef _POINT_H_
#define _POINT_H_

//点对象
typedef struct POINT
{
	unsigned char x;
	unsigned char y;
}Point;

//点对象转换成整数值（8*8矩阵）
extern unsigned char pointToInt(const Point p);

//XY坐标转换成整数值
extern unsigned char xyToInt(const int x, const int y); 

//整数值转换成点对象
extern Point intToPoint(unsigned char num);

#endif