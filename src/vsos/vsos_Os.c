#include "vsos_Os.h"
#include "vsos_EventTimer.h"
#include "vsos_EventTimerManager.h"
#include "vsos_Scheduler.h"

struct vsos_Os {
    vsos_SysTime * sysTime;
    vsos_Scheduler * scheduler;
    vsos_EventTimerManager * eventTimerManager;
    vsos_Os_onStartFun onStart;
};

vsos_Os * vsos_Os_(void) {
    static vsos_Os self;
    return &self;
}

vsos_Os * vsos_Os_init(
    vsos_Os * const self,
    vsos_Os_onStartFun const onStart,
    uint16_t const tickPeriodMillis,
    vsos_Scheduler_onIdleFun const onIdle,
    utl_Array * const taskArray
) {
    self->sysTime = vsos_SysTime_init(vsos_SysTime_(), tickPeriodMillis);
    self->scheduler = vsos_Scheduler_init(vsos_Scheduler_(), onIdle, taskArray);
    self->eventTimerManager = vsos_EventTimerManager_init(vsos_EventTimerManager_());
    self->onStart = onStart;
    return self;
}

void vsos_Os_onSysTick(vsos_Os * const self) {
    vsos_SysTime_onSysTick(self->sysTime);
    vsos_EventTimerManager_onSysTick(self->eventTimerManager);
}

void vsos_Os_start(vsos_Os * const self) {
    self->onStart();
    vsos_Scheduler_start(self->scheduler);
}
