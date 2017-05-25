#ifndef _INIT_GAME_H_
#define _INIT_GAME_H_
	 					
#include "Point.h"
#include "InitConst.h"

								
//列 左至右
extern unsigned char code COL[8];									  

//索引代表列,数值代表该列的当前值
extern unsigned char currentRedCOL[8];

//当前红点阵是否亮着
extern unsigned char redMatrix[8][8];

//当前绿点阵是否亮着
extern unsigned char greenMatrix[8][8];


//初始化红点阵 左上角为原点
extern void initRedMatrix();

//初始化绿点阵 左上角为原点
extern void initGreenMatrix();

//初始化当前每列值
extern void initCurrentCOL();

//更新红点阵
extern void updateRedMat(const Point point);

//更新绿点阵
extern void updateGreenMat(const Point point);
extern void updateGreenMatXY(const int x,const int y);

//更新当前每列的行值
extern void updateCol();

//显示当前点阵,更新时间
extern void showMatrix(unsigned int showTime);




#endif
				  			   