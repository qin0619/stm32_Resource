#include "wdg.h"
#include "./BSP/LED/led.h"


WWDG_HandleTypeDef g_wwdg_handle;
//看门狗初始化函数
void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
	
	g_wwdg_handle.Instance=WWDG;													//寄存器基地址
	
	g_wwdg_handle.Init.Counter=tr;											//寄存器初始值
	g_wwdg_handle.Init.EWIMode=WWDG_EWI_ENABLE;					//中断开启
	g_wwdg_handle.Init.Prescaler=fprer; 								//分频值
	g_wwdg_handle.Init.Window=wr;     									//窗口值
	
	HAL_WWDG_Init(&g_wwdg_handle);
}


//msp回调函数
void  HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
	__HAL_RCC_WWDG_CLK_ENABLE();		//使能时钟
	HAL_NVIC_SetPriority(WWDG_IRQn, 2, 3);
	HAL_NVIC_EnableIRQ(WWDG_IRQn);
	
}
//中断服务函数
void WWDG_IRQHandler(void)
{
	HAL_WWDG_IRQHandler(&g_wwdg_handle);
}

//wwdg提前唤醒函数
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
	
	HAL_WWDG_Refresh(&g_wwdg_handle);
	LED1_TOGGLE();
}

