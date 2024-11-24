#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "delay.h"
#include "dht11.h"
#include "oled.h"

/*****************���絥Ƭ�����******************
											STM32
 * ��Ŀ			:	1.DHT11�¶�ʪ�ȴ�����ʵ��                     
 * �汾			: V1.0
 * ����			: 2024.8.4
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	�ο�DHT11.h							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	���� 

**********************BEGIN***********************/

u8 temp;
u8 humi;

int main(void)
{ 
	
  SystemInit();//����ϵͳʱ��Ϊ72M	
	delay_init(72);
	LED_Init();
	LED_On();

	USART1_Config();//���ڳ�ʼ��
	OLED_Init();
	
	printf("Start \n");
	delay_ms(1000);
	while(DHT11_Init())
	{
		printf("DHT11 Error \r\n");
		delay_ms(1000);
	}
	//��ʾ���¶ȣ���
	OLED_ShowChinese(1,1, 0);
	OLED_ShowChinese(1,2, 1);
	OLED_ShowChar(1, 5, ':');
	OLED_ShowChar(1, 9, 'C');	
	//��ʾ��ʪ�ȣ���
	OLED_ShowChinese(2,1, 2);
	OLED_ShowChinese(2,2, 1);
	OLED_ShowChar(2, 5, ':');	
	OLED_ShowChar(2, 9, '%');
	
  while (1)
  {
		DHT11_Read_Data(&temp,&humi);//
		printf("temp %d ,humi %d\r\n",temp,humi);
		LED_Toggle();
		delay_ms(1000);
		//��ʾ�¶�����
		OLED_ShowNum(1,6,temp,2);
		//��ʾʪ������
		OLED_ShowNum(2,6,humi,2);
  }
}



