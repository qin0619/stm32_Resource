#include "stm32f10x.h"

void My_USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;
	
	//1、初始化时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能GPIOA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//使能串口1
	
	//2、初始化gpio
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;//浮空
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);
	
	//3、串口初始化
	USART_InitStrue.USART_BaudRate=115200;
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//不使用硬件流
	USART_InitStrue.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//使能接受与发送
	USART_InitStrue.USART_Parity=USART_Parity_No;//不适用校验
	USART_InitStrue.USART_StopBits=USART_StopBits_1;//停止位为1
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;//数据长度为8
	
	USART_Init(USART1, &USART_InitStrue);
	
	//使能串口
	USART_Cmd(USART1, ENABLE);
	
	//打开串口 接收中断，当接收到数据后就会自动执行相应的中断服务函数
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	//初始化中断，配置中断优先级
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn;//设置通道，usart1
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;//开启通道
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStrue);
}
 
//重写中断服务函数
void USART1_IRQHandler(void)
{
	u8 res;
	//判断中断类型，获取状态,第一个参数确定中断通道，第二个是确定中断类型
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		res=USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}
}

int main(void)
 {	
	
	 //设置NVIC分组
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 
	 My_USART1_Init();
	 
	 while(1);
	 
 }

 
 
 
 
 
 
 
 