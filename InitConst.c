
#include "InitConst.h"


unsigned char IsDirection(Direction dir)
{
	if (dir != UP && dir != DOWN && dir != LEFT &&  dir != RIGHT)
		return 0;
	return 1;
}
