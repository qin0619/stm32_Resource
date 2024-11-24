#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
#include "iwdg.h"

 int main(void)
 {
 	vu8 key=0;	
	delay_init();	    	 //延时函数初始化	  
 	LED_Init();			     //LED端口初始化
	KEY_Init();          //初始化与按键连接的硬件接口
	BEEP_Init();         	//初始化蜂鸣器端口
	
	 delay_ms(200);
	 LED0=0;					//先点亮红灯
	IWDG_Init(4, 625); //最大溢出时间为1s
	while(1)
	{
		if(KEY_Scan(0)==WKUP_PRES)//按下
		{
				IWDG_ReloadCounter();//喂狗
		}
		
	}	 
}

