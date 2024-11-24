#include "./BSP/WDG/wdg.h"
#include "stm32f1xx_hal.h"

IWDG_HandleTypeDef g_iwdg_handle;

void wdg_init(uint8_t prer, uint16_t rlr)
{
	g_iwdg_handle.Init.Prescaler=prer;			//Ԥ��Ƶ
	g_iwdg_handle.Init.Reload=rlr;					//����ֵ
	g_iwdg_handle.Instance=IWDG;						//�Ĵ�������ַ
	HAL_IWDG_Init(&g_iwdg_handle);
}

void iwdg_feed(void)
{
	HAL_IWDG_Refresh(&g_iwdg_handle); 									//��������ֵ����ι��
}
