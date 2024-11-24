

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/WDG/wdg.h"




int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
		usart_init(115200);									/* usart初始化 */
		printf("请喂狗：\r\n");
	wdg_init(IWDG_PRESCALER_32, 1250);    //预分频系数为32，重载值为1250，溢出时间约为1s
	while(1)
    { 
		delay_ms(3000);
		iwdg_feed();
		printf("已喂狗：\r\n");	
    }
	}
