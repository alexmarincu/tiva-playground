#include "vsk_Kernel.h"
#include "vsk_EventTimer.h"
#include "vsk_TaskScheduler.h"

struct vsk_Kernel {
    vsk_Time * sysTime;
    vsk_TaskScheduler * taskScheduler;
    vsk_EventTimerClass * eventTimerManager;
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
    vsk_CriticalSectionEnter const enterCriticalSection,
    vsk_CriticalSectionExit const exitCriticalSection
) {
    self->sysTime = vsk_Time_init(vsk_Time_());
    self->taskScheduler = vsk_TaskScheduler_init(vsk_TaskScheduler_(), onIdle);
    self->eventTimerManager = vsk_EventTimerClass_init(vsk_EventTimerClass_(), self->sysTime);
    vsk_CriticalSection_init(vsk_CriticalSection_(), enterCriticalSection, exitCriticalSection);
    self->onStart = onStart;
    return self;
}

void vsk_Kernel_informTickPeriodMillis(vsk_Kernel * const self, uint16_t const tickPeriodMillis) {
    vsk_Time_informTickPeriodMillis(self->sysTime, tickPeriodMillis);
}

void vsk_Kernel_onSysTick(vsk_Kernel * const self) {
    vsk_Time_onSysTick(self->sysTime);
    vsk_EventTimerClass_onSysTick(self->eventTimerManager);
}

void vsk_Kernel_start(
    vsk_Kernel * const self,
    ut_Array * const taskArray
) {
    self->onStart();
    vsk_TaskScheduler_start(self->taskScheduler, taskArray);
}
