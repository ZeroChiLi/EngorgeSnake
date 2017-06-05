
#include "InitConst.h"


unsigned char IsDirection(Direction dir)
{
	if (dir != UP && dir != DOWN && dir != LEFT &&  dir != RIGHT)
		return 0;
	return 1;
}

void DelayMs(unsigned int x)
{
	unsigned char i;
	while(x--)
		for (i = 0; i<13; i++);
}						
		 
unsigned char getMax(unsigned char a,unsigned char b)
{
	return a > b ? a : b;
}			