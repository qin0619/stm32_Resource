

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/WDG/wdg.h"




int main(void)
{
    HAL_Init();                         /* ��ʼ��HAL�� */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
    delay_init(72);                     /* ��ʱ��ʼ�� */
		usart_init(115200);									/* usart��ʼ�� */
		printf("��ι����\r\n");
	wdg_init(IWDG_PRESCALER_32, 1250);    //Ԥ��Ƶϵ��Ϊ32������ֵΪ1250�����ʱ��ԼΪ1s
	while(1)
    { 
		delay_ms(3000);
		iwdg_feed();
		printf("��ι����\r\n");	
    }
	}
