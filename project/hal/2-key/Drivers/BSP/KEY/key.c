#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

void key_init(void){
	
	//定义寄存器
	GPIO_InitTypeDef gpio_init_struct;
    //开启时钟E
	__HAL_RCC_GPIOE_CLK_ENABLE();
		
	//操纵pb2
	gpio_init_struct.Pin = GPIO_PIN_2;
	// 输入
	gpio_init_struct.Mode = GPIO_MODE_INPUT;
	//低速
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	//上拉输出
	gpio_init_struct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &gpio_init_struct);
}

uint8_t key_scan(void){
	//输入上拉，特点是空闲时为高电平，故按键按下时为低电平
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == 0)
			{
				delay_ms(10);//消抖
				if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == 0)
					{
						delay_ms(10);//消抖
						while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == 0);//松手后电平恢复高电平
						return 1;
		      }
				}
			return 0;//未按下
}
