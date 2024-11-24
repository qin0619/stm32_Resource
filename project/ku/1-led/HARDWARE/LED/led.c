#include "led.h"
#include "stm32f10x_gpio.h"
void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//GPIOE
	
	//PB5
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//5io��
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�Ϊ50hz
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
	
	//PE5
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//5io��
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�Ϊ50hz
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_SetBits(GPIOE, GPIO_Pin_5);
}
