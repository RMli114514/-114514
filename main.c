#include <REGX52.H>
#include "key.h"
#include "Delay.h"
#include "Timer0.h"
#include <INTRINS.H>
unsigned int num,x,flat;
void main()
{
	P2=0xFE;
	
	Timer0Init();
	
	while(1)
	{
		flat=P2;
		num=Key();
		P2=_crol_(P2,1);
		Delay(500);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//??????
	TH0 = 0xFC;		//??????
	T0Count++;
	x=3;
	if(T0Count>=1000)
	{
		T0Count=0;
		
		if(num==1)
		{
			while(x--)
			{
				P2=0;
				Delay(500);
				P2=0xFF;
				Delay(500);
			}
			P2=flat;
			
		}
		
		
	}
}