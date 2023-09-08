#ifndef HAL_SYSTICK_h
#define HAL_SYSTICK_h
#include <stdint.h>

void hal_SysTick_enable(void);
void hal_SysTick_disable(void);
void hal_SysTick_intRegister(void (*const fun)(void));
void hal_SysTick_intUnregister(void);
void hal_SysTick_intEnable(void);
void hal_SysTick_intDisable(void);
void hal_SysTick_setPeriodMillis(uint32_t const periodMillis);
uint32_t hal_SysTick_getPeriod(void);
uint32_t hal_SysTick_getValue(void);

#endif // HAL_SYSTICK_h
