/*............................................................................*/
#include "ha_SysTick.h"
#include "../../lib/TivaWare/driverlib/systick.h"
#include "ha_SysClock.h"
/*............................................................................*/
ha_SysTick * ha_SysTick_(void) {
    static ha_SysTick self;
    return &self;
}
/*............................................................................*/
ha_SysTick * ha_SysTick_init(
    ha_SysTick * const self
) {
    self->_periodMillis = 0;
    return self;
}
/*............................................................................*/
void ha_SysTick_enable(
    ha_SysTick * const self
) {
    SysTickEnable();
}
/*............................................................................*/
void ha_SysTick_disable(
    ha_SysTick * const self
) {
    SysTickDisable();
}
/*............................................................................*/
void ha_SysTick_registerInt(
    ha_SysTick * const self,
    ha_InterruptHandler const intHandler
) {
    SysTickIntRegister(intHandler);
}
/*............................................................................*/
void ha_SysTick_unregisterInt(
    ha_SysTick * const self
) {
    SysTickIntUnregister();
}
/*............................................................................*/
void ha_SysTick_enableInt(
    ha_SysTick * const self
) {
    SysTickIntEnable();
}
/*............................................................................*/
void ha_SysTick_disableInt(
    ha_SysTick * const self
) {
    SysTickIntDisable();
}
/*............................................................................*/
void ha_SysTick_setPeriodMillis(
    ha_SysTick * const self,
    uint16_t const periodMillis
) {
    uint16_t const millisInSecond = 1000;
    uint32_t const maxTickPeriod = 16777216;
    self->_periodMillis = periodMillis;
    uint16_t maxPeriodMillis =
        (maxTickPeriod / 100)                //
        * (millisInSecond / 100)             //
        / (ha_SysClock_getFrequency() / 100) //
        * 100;
    if (self->_periodMillis > maxPeriodMillis) {
        self->_periodMillis = maxPeriodMillis;
    }
    uint32_t tickPeriod =
        ha_SysClock_getFrequency() / millisInSecond * self->_periodMillis     //
        + (ha_SysClock_getFrequency() % millisInSecond) * self->_periodMillis //
              / millisInSecond;
    SysTickPeriodSet(tickPeriod);
}
/*............................................................................*/
uint16_t ha_SysTick_getPeriodMillis(
    ha_SysTick * const self
) {
    return self->_periodMillis;
}
