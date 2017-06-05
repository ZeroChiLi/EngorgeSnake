#include "InfraredInput.h"

unsigned char IrValue[6];	  //������Ŷ�ȡ���ĺ���ֵ

unsigned char _time;

void IrInit()
{
	IT0=1;//�½��ش���
	EX0=1;//���ж�0����
	EA=1;	//�����ж�

	IRIN=1;//��ʼ���˿�
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

	if(IRIN==0)		//ȷ���Ƿ���Ľ��յ���ȷ���ź�
	{	 
		
		err=1000;				//1000*10us=10ms,����˵�����յ�������ź�
		/*������������Ϊ����ѭ���������һ������Ϊ�ٵ�ʱ������ѭ������ó�������ʱ
		�������������*/	
		while((IRIN==0)&&(err>0))	//�ȴ�ǰ��9ms�ĵ͵�ƽ��ȥ  		
		{			
			DelayMs(1);
			err--;
		} 
		if(IRIN==1)			//�����ȷ�ȵ�9ms�͵�ƽ
		{
			err=500;
			while((IRIN==1)&&(err>0))		 //�ȴ�4.5ms����ʼ�ߵ�ƽ��ȥ
			{
				DelayMs(1);
				err--;
			}
			for(k=0;k<4;k++)		//����4������
			{				
				for(j=0;j<8;j++)	//����һ������
				{

					err=60;		
					while((IRIN==0)&&(err>0))//�ȴ��ź�ǰ���560us�͵�ƽ��ȥ
					{
						DelayMs(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 //����ߵ�ƽ��ʱ�䳤�ȡ�
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
					IrValue[k]>>=1;	 //k��ʾ�ڼ�������
					if(_time>=8)			//����ߵ�ƽ���ִ���565us����ô��1
					{
						IrValue[k]|=0x80;
					}
					_time=0;		//����ʱ��Ҫ���¸�ֵ							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}