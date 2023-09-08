#include "os_SysTime.h"
#include "../hal/hal_SysTick.h"

os_SysTime * os_SysTime_ref(void) {
    static os_SysTime self;
    return &self;
}

static void sysTickInt(void) {
    os_SysTime * self = os_SysTime_ref();
    self->millisTickCount++;
    if (self->millisTickCount % 1000 == 0) {
        self->opTimeSeconds++;
    }
}

os_SysTime * os_SysTime_init(os_SysTime * const self) {
    self->opTimeSeconds = 0;
    self->millisTickCount = 0;
    hal_SysTick_intRegister(sysTickInt);
    hal_SysTick_intEnable();
    hal_SysTick_setPeriodMillis(1);
    hal_SysTick_enable();
    return self;
}

uint32_t os_SysTime_getMillisTickCount(os_SysTime * const self) {
    return self->millisTickCount;
}

uint32_t os_SysTime_getOpTimeSeconds(os_SysTime * const self) {
    return self->opTimeSeconds;
}
