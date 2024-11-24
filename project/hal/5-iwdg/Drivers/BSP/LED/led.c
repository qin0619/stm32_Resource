#include "./BSP/LED/led.h"

void led_init(void){
	
	//定义寄存器
	GPIO_InitTypeDef gpio_init_struct;
    //开启时钟
	__HAL_RCC_GPIOB_CLK_ENABLE();
		
	//操纵pb5
	gpio_init_struct.Pin = GPIO_PIN_5;
	// 推挽输出
	gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
	//低速
	gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	
	
  HAL_GPIO_Init(GPIOB, &gpio_init_struct);
	//写入寄存器，寄存器BPin5 ，控制io输出水平
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
}
