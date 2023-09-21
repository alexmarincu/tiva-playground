#ifndef HAL_SYSTICK_H
#define HAL_SYSTICK_H
#include <stdint.h>

void hal_SysTick_enable(void);
void hal_SysTick_disable(void);
void hal_SysTick_registerInt(void (*const fun)(void));
void hal_SysTick_unregisterInt(void);
void hal_SysTick_enableInt(void);
void hal_SysTick_disableInt(void);
void hal_SysTick_setPeriodMillis(uint16_t const periodMillis);
uint16_t hal_SysTick_getPeriodMillis(void);

#endif // HAL_SYSTICK_H
