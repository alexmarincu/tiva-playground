#ifndef VSK_TIME_C
#define VSK_TIME_C
#include "vsk_Time.h"
#include "../hw_abstraction/ha_SysTick.h"

struct vsk_Time {
    uint32_t volatile opTimeSeconds;
    uint32_t volatile millisCount;
    uint16_t tickPeriodMillis;
};

vsk_Time * vsk_Time_(void) {
    static vsk_Time self;
    return &self;
}

vsk_Time * vsk_Time_init(vsk_Time * const self) {
    self->opTimeSeconds = 0;
    self->millisCount = 0;
    self->tickPeriodMillis = 0;
    return self;
}

void vsk_Time_informTickPeriodMillis(vsk_Time * const self, uint16_t const tickPeriodMillis) {
    self->tickPeriodMillis = tickPeriodMillis;
    self->millisCount = -tickPeriodMillis;
}

void vsk_Time_onSysTick(vsk_Time * const self) {
    self->millisCount += self->tickPeriodMillis;
    uint16_t const millisInSecond = 1000;
    if (self->millisCount % millisInSecond == 0) {
        self->opTimeSeconds++;
    }
}

uint32_t vsk_Time_getMillisCount(vsk_Time * const self) {
    return self->millisCount;
}

uint32_t vsk_Time_getOpTimeSeconds(vsk_Time * const self) {
    return self->opTimeSeconds;
}

uint16_t vsk_Time_getTickPeriodMillis(vsk_Time * const self) {
    return self->tickPeriodMillis;
}

#endif // VSK_TIME_C
