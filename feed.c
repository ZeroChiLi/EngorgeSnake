#include "feed.h"

void initFeed(Feed *feed)
{
	(*feed).count = 0;
	feedsetPos(feed, getRandomFreePos());
}


unsigned char getRandomFreePos()
{
	unsigned char i, j, freePos[64], freeSize = 0;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (redMatrix[i][j] == 0)
				freePos[freeSize++] = xyToInt(j + 1, i + 1);
	return freePos[rand() % freeSize];
}

void feedsetPos(Feed *feed, unsigned char pos)
{
	(*feed).x = intToPoint(pos).x;
	(*feed).y = intToPoint(pos).y;
	(*feed).count = 1;
}

unsigned char feedEaten(Feed *feed)
{
	if (!feedExist(*feed))
		return 0;
	(*feed).count = 0;
	initGreenMatrix();
	return 1;
}

unsigned char feedExist(Feed feed) { return feed.count == 0 ? 0 : 1; }

void feedShow(Feed *feed)
{
	if (!feedExist(*feed))
		return;
	updateGreenMatXY((*feed).x, (*feed).y);
}

