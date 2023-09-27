#ifndef HA_SYSTICK_H
#define HA_SYSTICK_H
#include "ha_Interrupt.h"

#include <stdint.h>

void ha_SysTick_enable(void);
void ha_SysTick_disable(void);
void ha_SysTick_registerInt(ha_InterruptHandler const intHandler);
void ha_SysTick_unregisterInt(void);
void ha_SysTick_enableInt(void);
void ha_SysTick_disableInt(void);
void ha_SysTick_setPeriodMillis(uint16_t const periodMillis);
uint16_t ha_SysTick_getPeriodMillis(void);

#endif // HA_SYSTICK_H
