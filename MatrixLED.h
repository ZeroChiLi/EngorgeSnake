#ifndef _INIT_GAME_H_
#define _INIT_GAME_H_
	 					
#include "Point.h"
#include "InitConst.h"

								
//列 左至右
extern unsigned char code COL[8];									  
								  
//索引代表列,数值代表该列的当前值
extern unsigned char _currentRedCOL[8];	 

extern unsigned char _currentGreenCOL[8];

//当前红点阵是否亮着
extern unsigned char _redMatrix[8][8];

//当前绿点阵是否亮着
extern unsigned char _greenMatrix[8][8];


//初始化红点阵 左上角为原点
extern void InitRedMatrix();

//初始化绿点阵 左上角为原点
extern void InitGreenMatrix();

//初始化当前每列值
extern void InitCurrentCOL();

//添加点到红点阵
extern void AddPointToRedMat(const Point point);

//添加点到绿点阵
extern void AddPointToGreenMat(const Point point);

//更新当前每列的行值
extern void UpdateCol();

//显示当前点阵,更新时间
extern void ShowMatrix(unsigned int showTime);




#endif
				  			   