#ifndef _FEED_H_
#define _FEED_H_
						
#include <stdlib.h>
#include "initGame.h"

typedef struct FEED
{
	unsigned char count;
	unsigned char x;
	unsigned char y;
}Feed;

//初始化食物
extern void initFeed(Feed *feed);

//取得随机除了红点的位置
extern unsigned char getRandomFreePos();

//设置食物位置
extern void feedsetPos(Feed *feed,unsigned char pos);

//返回0表示本来就没有足够食物
extern unsigned char feedEaten(Feed *feed);

//判断是否存在食物
extern unsigned char feedExist(Feed feed);

//显示食物
extern void feedShow(Feed *feed);


#endif