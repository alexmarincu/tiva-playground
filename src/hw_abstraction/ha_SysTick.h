#ifndef HA_SYSTICK_H
#define HA_SYSTICK_H
/*............................................................................*/
typedef struct ha_SysTick ha_SysTick;
#include "ha_Interrupt.h"
#include <stdint.h>
/*............................................................................*/
struct ha_SysTick {
    uint16_t _periodMillis;
};
/*............................................................................*/
ha_SysTick * ha_SysTick_(void);
ha_SysTick * ha_SysTick_init(ha_SysTick * const self);
void ha_SysTick_enable(ha_SysTick * const self);
void ha_SysTick_disable(ha_SysTick * const self);
void ha_SysTick_registerInt(
    ha_SysTick * const self, ha_InterruptHandler const intHandler
);
void ha_SysTick_unregisterInt(ha_SysTick * const self);
void ha_SysTick_enableInt(ha_SysTick * const self);
void ha_SysTick_disableInt(ha_SysTick * const self);
void ha_SysTick_setPeriodMillis(
    ha_SysTick * const self, uint16_t const periodMillis
);
uint16_t ha_SysTick_getPeriodMillis(ha_SysTick * const self);
#endif // HA_SYSTICK_H
