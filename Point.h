#ifndef _POINT_H_
#define _POINT_H_

//点对象
typedef struct POINT
{
	unsigned char x;
	unsigned char y;
}Point;


//点对象转成整数
extern unsigned char pointToInt(const Point p);

//xy坐标转换成整数值。
extern unsigned char xyToInt(const int x,const int y);

//整数转成点对象
extern Point intToPoint(unsigned char num);


#endif