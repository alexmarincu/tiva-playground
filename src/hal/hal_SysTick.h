#ifndef HAL_SYSTICK_H
#define HAL_SYSTICK_H
#include <stdint.h>

void hal_SysTick_enable(void);
void hal_SysTick_disable(void);
void hal_SysTick_intRegister(void (*const fun)(void));
void hal_SysTick_intUnregister(void);
void hal_SysTick_intEnable(void);
void hal_SysTick_intDisable(void);
void hal_SysTick_setPeriodMillis(uint32_t const periodMillis);
uint32_t hal_SysTick_getPeriodMillis(void);

#endif // HAL_SYSTICK_H
