#include "InfraredInput.h"

unsigned char IrValue[6];	  //用来存放读取到的红外值

unsigned char _time;

void IrInit()
{
	IT0=1;//下降沿触发
	EX0=1;//打开中断0允许
	EA=1;	//打开总中断

	IRIN=1;//初始化端口
}


unsigned char GetCurrentKey()
{
	return IrValue[2];
}

unsigned char OnClickPowerControlKey(unsigned char controlKey)
{
	return controlKey == 0x45;
}

Direction GetDirectionFromControlValue(unsigned char controlKey)
{
	switch(controlKey)
	{
	case 0x1c:
		return UP;	
	case 0x42:
		return LEFT;
	case 0x52:
		return DOWN;
	case 0x4a:
		return RIGHT;
	}
	return NONE;
}


void ReadIr() interrupt 0 
{
	unsigned char j,k;
	unsigned int err;
	_time=0;					 
	//DelayMs(70);

	if(IRIN==0)		//确认是否真的接收到正确的信号
	{	 
		
		err=1000;				//1000*10us=10ms,超过说明接收到错误的信号
		/*当两个条件都为真是循环，如果有一个条件为假的时候跳出循环，免得程序出错的时
		侯，程序死在这里*/	
		while((IRIN==0)&&(err>0))	//等待前面9ms的低电平过去  		
		{			
			DelayMs(1);
			err--;
		} 
		if(IRIN==1)			//如果正确等到9ms低电平
		{
			err=500;
			while((IRIN==1)&&(err>0))		 //等待4.5ms的起始高电平过去
			{
				DelayMs(1);
				err--;
			}
			for(k=0;k<4;k++)		//共有4组数据
			{				
				for(j=0;j<8;j++)	//接收一组数据
				{

					err=60;		
					while((IRIN==0)&&(err>0))//等待信号前面的560us低电平过去
					{
						DelayMs(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 //计算高电平的时间长度。
					{
						DelayMs(1);//0.14ms
						_time++;
						err--;
						if(_time>30)
						{
							EX0=1;
							return;
						}
					}
					IrValue[k]>>=1;	 //k表示第几组数据
					if(_time>=8)			//如果高电平出现大于565us，那么是1
					{
						IrValue[k]|=0x80;
					}
					_time=0;		//用完时间要重新赋值							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}