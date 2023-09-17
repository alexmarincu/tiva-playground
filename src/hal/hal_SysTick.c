#include "hal_SysTick.h"
#include "../../lib/TivaWare/driverlib/systick.h"
#include "hal_SysClock.h"

typedef struct {
    uint16_t periodMillis;
} hal_SysTick;

static hal_SysTick self = { 0 };

void hal_SysTick_enable(void) {
    SysTickEnable();
}

void hal_SysTick_disable(void) {
    SysTickDisable();
}

void hal_SysTick_intRegister(void (*const fun)(void)) {
    SysTickIntRegister(fun);
}

void hal_SysTick_intUnregister(void) {
    SysTickIntUnregister();
}

void hal_SysTick_intEnable(void) {
    SysTickIntEnable();
}

void hal_SysTick_intDisable(void) {
    SysTickIntDisable();
}

void hal_SysTick_setPeriodMillis(uint16_t const periodMillis) {
    uint16_t const millisInSecond = 1000;
    uint32_t const maxTickPeriod = 16777216;
    uint32_t tickPeriod =
        hal_SysClock_getFrequency() / millisInSecond * periodMillis //
        + (hal_SysClock_getFrequency() % millisInSecond) * periodMillis / millisInSecond;
    if (tickPeriod > maxTickPeriod) {
        tickPeriod = maxTickPeriod;
    }
    self.periodMillis = (tickPeriod / 100) * (millisInSecond / 100) / (hal_SysClock_getFrequency() / 100) * 100;
    SysTickPeriodSet(tickPeriod);
}

uint16_t hal_SysTick_getPeriodMillis(void) {
    return self.periodMillis;
}
