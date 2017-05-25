
#include "InitConst.h"


unsigned char isDirection(Direction dir)
{
	if (dir != UP && dir != DOWN && dir != LEFT &&  dir != RIGHT)
		return 0;
	return 1;
}

void delayms(unsigned int c)
{
	unsigned char a, b;
	for (; c > 0; c--)
		for (b = 38; b > 0; b--)
			for (a = 13; a > 0; a--);
}
