#ifndef VSK_SYSTIME_C
#define VSK_SYSTIME_C
#include "vsk_SysTime.h"
#include "../hal/hal_SysTick.h"

struct vsk_SysTime {
    uint32_t volatile opTimeSeconds;
    uint32_t volatile millisCount;
    uint16_t tickPeriodMillis;
};

vsk_SysTime * vsk_SysTime_(void) {
    static vsk_SysTime self;
    return &self;
}

vsk_SysTime * vsk_SysTime_init(vsk_SysTime * const self) {
    self->opTimeSeconds = 0;
    self->millisCount = 0;
    self->tickPeriodMillis = 0;
    return self;
}

void vsk_SysTime_informTickPeriodMillis(vsk_SysTime * const self, uint16_t const tickPeriodMillis) {
    self->tickPeriodMillis = tickPeriodMillis;
}

void vsk_SysTime_onSysTick(vsk_SysTime * const self) {
    self->millisCount += self->tickPeriodMillis;
    uint16_t const millisInSecond = 1000;
    if (self->millisCount % millisInSecond == 0) {
        self->opTimeSeconds++;
    }
}

uint32_t vsk_SysTime_getMillisCount(vsk_SysTime * const self) {
    return self->millisCount;
}

uint32_t vsk_SysTime_getOpTimeSeconds(vsk_SysTime * const self) {
    return self->opTimeSeconds;
}

uint16_t vsk_SysTime_getTickPeriodMillis(vsk_SysTime * const self) {
    return self->tickPeriodMillis;
}

#endif // VSK_SYSTIME_C
