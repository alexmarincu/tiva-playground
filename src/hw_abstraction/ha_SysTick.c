#include "ha_SysTick.h"
#include "ha_SysClock.h"

#include "../../lib/TivaWare/driverlib/systick.h"

typedef struct {
    uint16_t periodMillis;
} ha_SysTick;

static ha_SysTick self = { 0 };

void ha_SysTick_enable(void) {
    SysTickEnable();
}

void ha_SysTick_disable(void) {
    SysTickDisable();
}

void ha_SysTick_registerInt(ha_InterruptHandler const intHandler) {
    SysTickIntRegister(intHandler);
}

void ha_SysTick_unregisterInt(void) {
    SysTickIntUnregister();
}

void ha_SysTick_enableInt(void) {
    SysTickIntEnable();
}

void ha_SysTick_disableInt(void) {
    SysTickIntDisable();
}

void ha_SysTick_setPeriodMillis(uint16_t const periodMillis) {
    uint16_t const millisInSecond = 1000;
    uint32_t const maxTickPeriod = 16777216;
    self.periodMillis = periodMillis;
    uint16_t maxPeriodMillis =
        (maxTickPeriod / 100)                //
        * (millisInSecond / 100)             //
        / (ha_SysClock_getFrequency() / 100) //
        * 100;
    if (self.periodMillis > maxPeriodMillis) {
        self.periodMillis = maxPeriodMillis;
    }
    uint32_t tickPeriod =
        ha_SysClock_getFrequency() / millisInSecond * self.periodMillis //
        + (ha_SysClock_getFrequency() % millisInSecond) * self.periodMillis / millisInSecond;
    SysTickPeriodSet(tickPeriod);
}

uint16_t ha_SysTick_getPeriodMillis(void) {
    return self.periodMillis;
}
