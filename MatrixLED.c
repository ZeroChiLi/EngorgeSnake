#include "MatrixLED.h"

//ап вСжаср
unsigned char code COL[8] = { 0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe };

unsigned char _currentRedCOL[8];	 

unsigned char _currentGreenCOL[8];

unsigned char _redMatrix[8][8];

unsigned char _greenMatrix[8][8];

void InitRedMatrix()
{
	unsigned char i, j;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			_redMatrix[i][j] = 0;
}

void InitGreenMatrix()
{
	unsigned char i, j;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			_greenMatrix[i][j] = 0;
}

void InitCurrentCOL()
{
	unsigned char i;
	for (i = 0; i < 8; i++)
		_currentRedCOL[i] = 0x00;
}

void AddPointToRedMat(const Point point) 
{
	_redMatrix[point.y - 1][point.x - 1] = 1; 
}

void AddPointToGreenMat(const Point point) 
{ 
	_greenMatrix[point.y - 1][point.x - 1] = 1; 
}


void updateCol()
{
	unsigned char i, j;
	InitCurrentCOL();
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			_currentRedCOL[i] |= _redMatrix[j][i] ;
			_currentGreenCOL[i] |= _greenMatrix[j][i];
			if (j < 7)
			{
				_currentRedCOL[i] <<= 1;
				_currentGreenCOL[i] <<= 1;
			}
		}
}

void ShowMatrix(unsigned int showTime)
{
	unsigned char col,k = 0;
	for (; showTime > 0; --showTime)
		for (col = 0; col < 8; col++)
		{
			READPORTS = 0xFF;	   	
			GREENPORTS = 0xFF;	

			COMMONPORTS = _currentRedCOL[col]; 
			READPORTS = COL[col];		 

			COMMONPORTS = _currentGreenCOL[col];
			GREENPORTS = COL[col];	 
		}
}

