#ifndef HA_SYSCLOCK_H
#define HA_SYSCLOCK_H
#include <stdint.h>

void ha_SysClock_setMaxFrequency(void);
uint32_t ha_SysClock_getFrequency(void);

#endif // HA_SYSCLOCK_H
