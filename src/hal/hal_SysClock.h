#ifndef HAL_SYSCLOCK_H
#define HAL_SYSCLOCK_H
#include <stdint.h>

void hal_SysClock_setMaxFrequency(void);
uint32_t hal_SysClock_getFrequency(void);

#endif // HAL_SYSCLOCK_H
