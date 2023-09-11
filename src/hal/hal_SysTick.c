#include "hal_SysTick.h"
#include "../../lib/TivaWare/driverlib/systick.h"

typedef struct {
    uint32_t periodMillis;
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

void hal_SysTick_setPeriodMillis(uint32_t const periodMillis) {
    self.periodMillis = periodMillis;
    uint32_t const ucTicksPerSecond = 16777216;
    uint16_t const millisInSecond = 1000;
    SysTickPeriodSet(
        ucTicksPerSecond / millisInSecond * self.periodMillis //
        + (ucTicksPerSecond % millisInSecond) * self.periodMillis / millisInSecond
    );
}

uint32_t hal_SysTick_getPeriod(void) {
    return self.periodMillis;
}
