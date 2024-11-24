#include "./BSP/EXTI/exti.h"
#include "./SYSTEM/delay/delay.h"

/*
	EXTI��HAL�����ò��裨�ⲿ�жϣ�
	1��ʹ��GPIOʱ��
	2��GPIO��ʼ��
	3�������жϷ��飨��������һ�Σ�����HAL_Init�Ѿ����ù������ٴ����ã�
	4�������ж����ȼ�
	5��ʹ���ж�
	6�������жϷ�����
*/
void exti_init(void)
{
	 //����Ĵ���
	GPIO_InitTypeDef gpio_init_struct;
    //����ʱ��PE
	__HAL_RCC_GPIOE_CLK_ENABLE();
		
	//����pe4����
	gpio_init_struct.Pin = GPIO_PIN_4;
	// �½��ش����ж�
	gpio_init_struct.Mode = GPIO_MODE_IT_FALLING;
	//����
	gpio_init_struct.Pull = GPIO_PULLUP;
	
	
  HAL_GPIO_Init(GPIOE, &gpio_init_struct);
	//�����ж����ȼ�
	HAL_NVIC_SetPriority(EXTI4_IRQn,2,0);
	//ʹ���ж�
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
	
}
/*	 �жϷ����� EXTI4_IRQHandler
	-> HAL���жϴ����ú��� HAL_GPIO_EXTI_IRQHandler
  -> HAL�����ݴ���ص����� HAL_GPIO_EXTI_Callback
*/
void EXTI4_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//����
	delay_ms(20);
	if(GPIO_Pin == GPIO_PIN_4)
	{
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
		{
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
		}
	}
	
	
}


