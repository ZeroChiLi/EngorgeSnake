
#include "KeyboardInput.h"


unsigned char key_Scan() 
{ 
	return GPIO_KEY; 
}

Direction getDirectionFromKey(unsigned char key)
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

unsigned char onClickRestartKey(unsigned char key)
{
	return key == 0xFE;
}
