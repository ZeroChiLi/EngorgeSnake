
#include "Point.h"


unsigned char pointToInt(const Point p) 
{ 
	return (p.y - 1) * 8 + (p.x - 1); 
}

unsigned char xyToInt(const int x, const int y) 
{ 
	return (y - 1) * 8 + (x - 1); 
}

Point intToPoint(unsigned char num)
{
	Point p;
	p.x = num % 8 + 1;
	p.y = num / 8 + 1;
	return p;
}