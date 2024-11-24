#include "iwdg.h"


void IWDG_Init(u8 prer, u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //取消写保护
	
	IWDG_SetPrescaler(prer);										  //设置预分频系数
	
	IWDG_SetReload(rlr);											    //设置重装载值
	
	IWDG_ReloadCounter();													//喂狗，将重载值写入寄存器
	
	IWDG_Enable();																//使能看门狗
}

