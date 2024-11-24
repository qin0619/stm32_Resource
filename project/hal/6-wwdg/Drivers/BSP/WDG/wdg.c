#include "wdg.h"
#include "./BSP/LED/led.h"


WWDG_HandleTypeDef g_wwdg_handle;
//���Ź���ʼ������
void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
	
	g_wwdg_handle.Instance=WWDG;													//�Ĵ�������ַ
	
	g_wwdg_handle.Init.Counter=tr;											//�Ĵ�����ʼֵ
	g_wwdg_handle.Init.EWIMode=WWDG_EWI_ENABLE;					//�жϿ���
	g_wwdg_handle.Init.Prescaler=fprer; 								//��Ƶֵ
	g_wwdg_handle.Init.Window=wr;     									//����ֵ
	
	HAL_WWDG_Init(&g_wwdg_handle);
}


//msp�ص�����
void  HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
	__HAL_RCC_WWDG_CLK_ENABLE();		//ʹ��ʱ��
	HAL_NVIC_SetPriority(WWDG_IRQn, 2, 3);
	HAL_NVIC_EnableIRQ(WWDG_IRQn);
	
}
//�жϷ�����
void WWDG_IRQHandler(void)
{
	HAL_WWDG_IRQHandler(&g_wwdg_handle);
}

//wwdg��ǰ���Ѻ���
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
	
	HAL_WWDG_Refresh(&g_wwdg_handle);
	LED1_TOGGLE();
}

