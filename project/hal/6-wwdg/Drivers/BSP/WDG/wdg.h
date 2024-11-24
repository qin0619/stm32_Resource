#ifndef __WDG_H
#define __WDG_H

#include "stm32f1xx_hal.h"

extern WWDG_HandleTypeDef g_wwdg_handle;
//≥ı ºªØ
void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer);

#endif
