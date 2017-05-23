#ifndef _INIT_GAME_H_
#define _INIT_GAME_H_
	 						   
#include <reg51.h>	 
#include <intrins.h>
				  
#define GPIO_KEY		P1  //独立键盘用P1口

#define COMMONPORTS		P0
#define READPORTS 		P2
#define GREENPORTS 		P3
								
//列 左至右
extern unsigned char code COL[8];									  

//索引代表列,数值代表该列的当前值
extern unsigned char currentRedCOL[8];

//当前红点阵是否亮着
extern unsigned char redMatrix[8][8];

//当前绿点阵是否亮着
extern unsigned char greenMatrix[8][8];

//方向,独立键盘 k3 k6 k7 k8
typedef enum DIRECTION
{
	UP = 0xFB,
	DOWN = 0xBF,
	LEFT = 0xDF,
	RIGHT = 0x7F
}Direction;

//点对象
typedef struct POINT
{
	Direction dir;
	unsigned char x;
	unsigned char y;
}Point;

//延时10ms
extern void delay10ms(unsigned int c);

//检测按键
extern unsigned char key_Scan();

//移动的点,按键
extern void movePoint(Point *p, Direction dir);

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

//显示当前点阵
extern void showMatrix(unsigned int delayTime);

//判断是否为方向
extern unsigned char isDirection(Direction dir);

//xy坐标转成整数
extern unsigned char pointToInt(const Point p);

extern unsigned char xyToInt(const int x,const int y);

//整数转成xy坐标
extern Point intToPoint(unsigned char num);


#endif
				  			   