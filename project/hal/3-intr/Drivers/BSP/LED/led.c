#include "./BSP/LED/led.h"

void led_init(void){
	
	//����Ĵ���
	GPIO_InitTypeDef gpio_init_struct;
    //����ʱ��
	__HAL_RCC_GPIOB_CLK_ENABLE();
		
	//����pb5
	gpio_init_struct.Pin = GPIO_PIN_5;
	// �������
	gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
	//����
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	
	
  HAL_GPIO_Init(GPIOB, &gpio_init_struct);
	//д��Ĵ������Ĵ���B�pPin5 ������io���ˮƽ
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
}
