#include "vsk_Kernel.h"
#include "vsk_EventTimer.h"
#include "vsk_EventTimerManager.h"
#include "vsk_TaskScheduler.h"

struct vsk_Kernel {
    vsk_SysTime * sysTime;
    vsk_TaskScheduler * taskScheduler;
    vsk_EventTimerManager * eventTimerManager;
    vsk_KernelOnStart onStart;
};

vsk_Kernel * vsk_Kernel_(void) {
    static vsk_Kernel self;
    return &self;
}

vsk_Kernel * vsk_Kernel_init(
    vsk_Kernel * const self,
    vsk_KernelOnStart const onStart,
    vsk_TaskSchedulerOnIdle const onIdle,
    utl_Array * const taskArray
) {
    self->sysTime = vsk_SysTime_init(vsk_SysTime_());
    self->taskScheduler = vsk_TaskScheduler_init(vsk_TaskScheduler_(), onIdle, taskArray);
    self->eventTimerManager = vsk_EventTimerManager_init(vsk_EventTimerManager_(), self->sysTime);
    self->onStart = onStart;
    return self;
}

void vsk_Kernel_informTickPeriodMillis(vsk_Kernel * const self, uint16_t const tickPeriodMillis) {
    vsk_SysTime_informTickPeriodMillis(self->sysTime, tickPeriodMillis);
}

void vsk_Kernel_onSysTick(vsk_Kernel * const self) {
    vsk_SysTime_onSysTick(self->sysTime);
    vsk_EventTimerManager_onSysTick(self->eventTimerManager);
}

void vsk_Kernel_start(vsk_Kernel * const self) {
    self->onStart();
    vsk_TaskScheduler_start(self->taskScheduler);
}
