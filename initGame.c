#include "initGame.h"

//列 左至右
unsigned char code COL[8] = { 0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe };

//索引代表列,数值代表该列的当前值
unsigned char currentRedCOL[8];

unsigned char currentGreenCOL[8];

//当前红点阵是否亮着
unsigned char redMatrix[8][8];

//当前绿点阵是否亮着
unsigned char greenMatrix[8][8];

void initRedMatrix()
{
	unsigned char i, j;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			redMatrix[i][j] = 0;
}

void initGreenMatrix()
{
	unsigned char i, j;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			greenMatrix[i][j] = 0;
}

void initCurrentCOL()
{
	unsigned char i;
	for (i = 0; i < 8; i++)
		currentRedCOL[i] = 0x00;
}

void updateRedMat(const Point point) { redMatrix[point.y - 1][point.x - 1] = 1; }

void updateGreenMat(const Point point) { greenMatrix[point.y - 1][point.x - 1] = 1; }

void updateGreenMatXY(const int x, const int y) { greenMatrix[y - 1][x - 1] = 1; }

void updateCol()
{
	unsigned char i, j;
	initCurrentCOL();
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			currentRedCOL[i] |= redMatrix[j][i] ;
			currentGreenCOL[i] |= greenMatrix[j][i];
			if (j < 7)
			{
				currentRedCOL[i] <<= 1;
				currentGreenCOL[i] <<= 1;
			}
		}
}

void showMatrix(unsigned int delayTime)
{
	unsigned char col,k = 0;
	for (delayTime; delayTime > 0; --delayTime)
		for (col = 0; col < 8; col++)
		{
			READPORTS = 0xFF;
			GREENPORTS = 0xFF;

			COMMONPORTS = currentRedCOL[col]; 
			READPORTS = COL[col];		 

			COMMONPORTS = currentGreenCOL[col];
			GREENPORTS = COL[col];	 		
		}
}

void movePoint(Point *p, Direction dir)
{
	if (!isDirection(dir))
		dir = (*p).dir;
	switch (dir)
	{
	case(UP):
	{
		(*p).dir = UP;
		(*p).y = (*p).y == 1 ? 8 : (*p).y - 1;
		break;
	}
	case(DOWN):
	{
		(*p).dir = DOWN;
		(*p).y = (*p).y == 8 ? 1 : (*p).y + 1;
		break;
	}
	case(LEFT):
	{
		(*p).dir = LEFT;
		(*p).x = (*p).x == 1 ? 8 : (*p).x - 1;
		break;
	}
	case(RIGHT):
	{
		(*p).dir = RIGHT;
		(*p).x = (*p).x == 8 ? 1 : (*p).x + 1;
		break;
	}
	default:
		break;
	}
}

unsigned char key_Scan() { return GPIO_KEY; }

void delay10ms(unsigned int c)
{
	unsigned char a, b;
	for (; c > 0; c--)
		for (b = 38; b > 0; b--)
			for (a = 130; a > 0; a--);
}

unsigned char isDirection(Direction dir)
{
	if (dir != UP && dir != DOWN && dir != LEFT &&  dir != RIGHT)
		return 0;
	return 1;
}

unsigned char pointToInt(const Point p) { return (p.y - 1) * 8 + (p.x - 1); }

unsigned char xyToInt(const int x, const int y) { return (y - 1) * 8 + (x - 1); }

Point intToPoint(unsigned char num)
{
	Point p;
	p.x = num % 8 + 1;
	p.y = num / 8 + 1;
	return p;
}