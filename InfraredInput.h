#ifndef _INFRARED_INPUT_H_
#define _INFRARED_INPUT_H_
 		 
#include <reg51.h>
#include "InitConst.h"

sbit IRIN = P3^2;

	
extern void DelayMs(unsigned int x);

extern void IrInit();				
		 
extern void ReadIr();

extern unsigned char GetCurrentKey();
							   
extern unsigned char OnClickPowerControlKey(unsigned char controlKey);

extern Direction GetDirectionFromControlValue(unsigned char value);

#endif