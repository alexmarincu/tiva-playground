#include "vsos_Os.h"
#include "vsos_Scheduler.h"
#include "vsos_TimeEvent.h"

struct vsos_Os {
    vsos_SysTime * sysTime;
    vsos_Scheduler * scheduler;
};

vsos_Os * vsos_Os_(void) {
    static vsos_Os self;
    return &self;
}

vsos_Os * vsos_Os_init(
    vsos_Os * const self,
    utils_Array * const taskArray,
    vsos_Scheduler_onIdleFun const onIdle,
    uint16_t const tickPeriodMillis
) {
    self->sysTime = vsos_SysTime_init(vsos_SysTime_(), tickPeriodMillis);
    self->scheduler = vsos_Scheduler_init(vsos_Scheduler_(), taskArray, onIdle);
    return self;
}

void vsos_Os_onSysTick(vsos_Os * const self) {
    vsos_SysTime_onSysTick(self->sysTime);
    vsos_TimeEvent_onSysTick();
}

void vsos_Os_start(vsos_Os * const self) {
    vsos_Scheduler_start(self->scheduler);
}
