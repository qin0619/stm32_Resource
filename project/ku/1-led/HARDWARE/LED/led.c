#include "led.h"
#include "stm32f10x_gpio.h"
void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//GPIOE
	
	//PB5
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//5io口
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//速度为50hz
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
	
	//PE5
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//5io口
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//速度为50hz
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_SetBits(GPIOE, GPIO_Pin_5);
}
