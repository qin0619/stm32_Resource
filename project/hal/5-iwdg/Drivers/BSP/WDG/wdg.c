#include "./BSP/WDG/wdg.h"
#include "stm32f1xx_hal.h"

IWDG_HandleTypeDef g_iwdg_handle;

void wdg_init(uint8_t prer, uint16_t rlr)
{
	g_iwdg_handle.Init.Prescaler=prer;			//预分频
	g_iwdg_handle.Init.Reload=rlr;					//重载值
	g_iwdg_handle.Instance=IWDG;						//寄存器基地址
	HAL_IWDG_Init(&g_iwdg_handle);
}

void iwdg_feed(void)
{
	HAL_IWDG_Refresh(&g_iwdg_handle); 									//加载重载值，即喂狗
}
