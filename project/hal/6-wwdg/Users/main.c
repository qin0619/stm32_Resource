/**
 ******************************************************************************
 * @file     main.c
 * @author   ����ԭ���Ŷ�(ALIENTEK)
 * @version  V1.0
 * @date     2020-08-20
 * @brief    �½�����ʵ��-HAL��汾 ʵ��
 * @license  Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ******************************************************************************
 * @attention
 * 
 * ʵ��ƽ̨:����ԭ�� STM32F103 ������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 ******************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "wdg.h"

int main(void)
{
    HAL_Init();                         /* ��ʼ��HAL�� */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
    delay_init(72);                     /* ��ʱ��ʼ�� */
    led_init();                         /* LED��ʼ�� */
		usart_init(115200);									/* USART��ʼ�� */
	
		if(__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET)
		{
				printf("���ڿ��ſڸ�λ\r\n");
				__HAL_RCC_CLEAR_RESET_FLAGS();
		}
		else
		{
		printf("�ⲿ��λ\r\n");
		}
		delay_ms(500);
		//printf("�ڴ�����ι��\r\n");
		wwdg_init(0x7f, 0x5f, WWDG_PRESCALER_8);
    while(1)
    { 
			delay_ms(90);
			HAL_WWDG_Refresh(&g_wwdg_handle);
			LED0_TOGGLE();
    }
}
