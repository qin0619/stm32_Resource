#include "./BSP/EXTI/exti.h"
#include "./SYSTEM/delay/delay.h"

/*
	EXTI的HAL库设置步骤（外部中断）
	1、使用GPIO时钟
	2、GPIO初始化
	3、设置中断分组（仅需设置一次，且在HAL_Init已经设置过无需再次配置）
	4、设置中断优先级
	5、使能中断
	6、设置中断服务函数
*/
void exti_init(void)
{
	 //定义寄存器
	GPIO_InitTypeDef gpio_init_struct;
    //开启时钟PE
	__HAL_RCC_GPIOE_CLK_ENABLE();
		
	//操纵pe4引脚
	gpio_init_struct.Pin = GPIO_PIN_4;
	// 下降沿触发中断
	gpio_init_struct.Mode = GPIO_MODE_IT_FALLING;
	//上拉
	gpio_init_struct.Pull = GPIO_PULLUP;
	
	
  HAL_GPIO_Init(GPIOE, &gpio_init_struct);
	//设置中断优先级
	HAL_NVIC_SetPriority(EXTI4_IRQn,2,0);
	//使能中断
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
	
}
/*	 中断服务函数 EXTI4_IRQHandler
	-> HAL库中断处理公用函数 HAL_GPIO_EXTI_IRQHandler
  -> HAL库数据处理回调函数 HAL_GPIO_EXTI_Callback
*/
void EXTI4_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//消抖
	delay_ms(20);
	if(GPIO_Pin == GPIO_PIN_4)
	{
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
		{
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
		}
	}
	
	
}


