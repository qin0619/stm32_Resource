#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

void key_init(void){
	
	//����Ĵ���
	GPIO_InitTypeDef gpio_init_struct;
    //����ʱ��E
	__HAL_RCC_GPIOE_CLK_ENABLE();
		
	//����pb2
	gpio_init_struct.Pin = GPIO_PIN_2;
	// ����
	gpio_init_struct.Mode = GPIO_MODE_INPUT;
	//����
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	//�������
	gpio_init_struct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &gpio_init_struct);
}

uint8_t key_scan(void){
	//�����������ص��ǿ���ʱΪ�ߵ�ƽ���ʰ�������ʱΪ�͵�ƽ
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == 0)
			{
				delay_ms(10);//����
				if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == 0)
					{
						delay_ms(10);//����
						while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == 0);//���ֺ��ƽ�ָ��ߵ�ƽ
						return 1;
		      }
				}
			return 0;//δ����
}
