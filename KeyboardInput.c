
#include "KeyboardInput.h"


unsigned char Key_Scan() 
{ 
	return GPIO_KEY; 
}

Direction GetDirectionFromKey(unsigned char key)
{
	switch(key)
	{
	case 0xFB: 
		return UP;
	case 0xBF: 
		return DOWN;
	case 0xDF: 
		return LEFT;
	case 0x7F: 
		return RIGHT;
	}
	return NONE;
}

unsigned char OnClickRestartKey(unsigned char key)
{
	return key == 0xFE;
}
