#include "stm32f10x.h"

void My_USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;
	
	//1����ʼ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��GPIOA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//ʹ�ܴ���1
	
	//2����ʼ��gpio
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;//��������
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;//����
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);
	
	//3�����ڳ�ʼ��
	USART_InitStrue.USART_BaudRate=115200;
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//��ʹ��Ӳ����
	USART_InitStrue.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//ʹ�ܽ����뷢��
	USART_InitStrue.USART_Parity=USART_Parity_No;//������У��
	USART_InitStrue.USART_StopBits=USART_StopBits_1;//ֹͣλΪ1
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;//���ݳ���Ϊ8
	
	USART_Init(USART1, &USART_InitStrue);
	
	//ʹ�ܴ���
	USART_Cmd(USART1, ENABLE);
	
	//�򿪴��� �����жϣ������յ����ݺ�ͻ��Զ�ִ����Ӧ���жϷ�����
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	//��ʼ���жϣ������ж����ȼ�
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn;//����ͨ����usart1
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;//����ͨ��
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStrue);
}
 
//��д�жϷ�����
void USART1_IRQHandler(void)
{
	u8 res;
	//�ж��ж����ͣ���ȡ״̬,��һ������ȷ���ж�ͨ�����ڶ�����ȷ���ж�����
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		res=USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}
}

int main(void)
 {	
	
	 //����NVIC����
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 
	 My_USART1_Init();
	 
	 while(1);
	 
 }

 
 
 
 
 
 
 
 