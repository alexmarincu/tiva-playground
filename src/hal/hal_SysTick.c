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
    self.periodMillis = periodMillis;
    uint16_t const millisInSecond = 1000;
    SysTickPeriodSet(
        hal_SysClock_getFrequency() / millisInSecond * self.periodMillis //
        + (hal_SysClock_getFrequency() % millisInSecond) * self.periodMillis / millisInSecond
    );
}

uint16_t hal_SysTick_getPeriodMillis(void) {
    return self.periodMillis;
}
