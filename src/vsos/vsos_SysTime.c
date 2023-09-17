#include "vsos_SysTime.h"
#include "../hal/hal_SysTick.h"

struct vsos_SysTime {
    uint32_t volatile opTimeSeconds;
    uint32_t volatile millisCount;
    uint16_t tickPeriodMillis;
};

vsos_SysTime * vsos_SysTime_(void) {
    static vsos_SysTime self;
    return &self;
}

vsos_SysTime * vsos_SysTime_init(vsos_SysTime * const self, uint16_t const tickPeriodMillis) {
    self->opTimeSeconds = 0;
    self->millisCount = 0;
    self->tickPeriodMillis = tickPeriodMillis;
    return self;
}

void vsos_SysTime_onSysTick(vsos_SysTime * const self) {
    self->millisCount += self->tickPeriodMillis;
    uint16_t const millisInSecond = 1000;
    if (self->millisCount % millisInSecond == 0) {
        self->opTimeSeconds++;
    }
}

uint32_t vsos_SysTime_getMillisCount(vsos_SysTime * const self) {
    return self->millisCount;
}

uint32_t vsos_SysTime_getOpTimeSeconds(vsos_SysTime * const self) {
    return self->opTimeSeconds;
}
