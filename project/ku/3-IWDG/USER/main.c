#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
#include "iwdg.h"

 int main(void)
 {
 	vu8 key=0;	
	delay_init();	    	 //��ʱ������ʼ��	  
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
	BEEP_Init();         	//��ʼ���������˿�
	
	 delay_ms(200);
	 LED0=0;					//�ȵ������
	IWDG_Init(4, 625); //������ʱ��Ϊ1s
	while(1)
	{
		if(KEY_Scan(0)==WKUP_PRES)//����
		{
				IWDG_ReloadCounter();//ι��
		}
		
	}	 
}

