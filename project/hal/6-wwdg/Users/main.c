/**
 ******************************************************************************
 * @file     main.c
 * @author   正点原子团队(ALIENTEK)
 * @version  V1.0
 * @date     2020-08-20
 * @brief    新建工程实验-HAL库版本 实验
 * @license  Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ******************************************************************************
 * @attention
 * 
 * 实验平台:正点原子 STM32F103 开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 ******************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "wdg.h"

int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    led_init();                         /* LED初始化 */
		usart_init(115200);									/* USART初始化 */
	
		if(__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET)
		{
				printf("窗口看门口复位\r\n");
				__HAL_RCC_CLEAR_RESET_FLAGS();
		}
		else
		{
		printf("外部复位\r\n");
		}
		delay_ms(500);
		//printf("在窗口期喂狗\r\n");
		wwdg_init(0x7f, 0x5f, WWDG_PRESCALER_8);
    while(1)
    { 
			delay_ms(90);
			HAL_WWDG_Refresh(&g_wwdg_handle);
			LED0_TOGGLE();
    }
}
