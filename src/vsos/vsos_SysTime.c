#include "vsos_SysTime.h"
#include "../hal/hal_SysTick.h"

struct vsos_SysTime {
    uint32_t volatile opTimeSeconds;
    uint32_t volatile millisCount;
};

vsos_SysTime * vsos_SysTime_(void) {
    static vsos_SysTime self;
    return &self;
}

vsos_SysTime * vsos_SysTime_init(vsos_SysTime * const self) {
    self->opTimeSeconds = 0;
    self->millisCount = 0;
    return self;
}

static void vsos_SysTime_increment(vsos_SysTime * const self, uint32_t const periodMillis) {
    self->millisCount += periodMillis;
    if (self->millisCount % 1000 == 0) {
        self->opTimeSeconds++;
    }
}

void vsos_SysTime_onSysTick(vsos_SysTime * const self, uint32_t const periodMillis) {
    vsos_SysTime_increment(self, periodMillis);
}

uint32_t vsos_SysTime_getMillisCount(vsos_SysTime * const self) {
    return self->millisCount;
}

uint32_t vsos_SysTime_getOpTimeSeconds(vsos_SysTime * const self) {
    return self->opTimeSeconds;
}
