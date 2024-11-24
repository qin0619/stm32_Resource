#include "iwdg.h"


void IWDG_Init(u8 prer, u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //ȡ��д����
	
	IWDG_SetPrescaler(prer);										  //����Ԥ��Ƶϵ��
	
	IWDG_SetReload(rlr);											    //������װ��ֵ
	
	IWDG_ReloadCounter();													//ι����������ֵд��Ĵ���
	
	IWDG_Enable();																//ʹ�ܿ��Ź�
}

