#ifndef __WDG_H
#define __WDG_H
#include "stm32f1xx_hal.h"
//��ʼ��
void wdg_init(uint8_t prer, uint16_t rlr);
//ι��
void iwdg_feed(void);
#endif
