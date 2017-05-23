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

//��ʼ��ʳ��
extern void initFeed(Feed *feed);

//ȡ��������˺���λ��
extern unsigned char getRandomFreePos();

//����ʳ��λ��
extern void feedsetPos(Feed *feed,unsigned char pos);

//����0��ʾ������û���㹻ʳ��
extern unsigned char feedEaten(Feed *feed);

//�ж��Ƿ����ʳ��
extern unsigned char feedExist(Feed feed);

//��ʾʳ��
extern void feedShow(Feed *feed);


#endif