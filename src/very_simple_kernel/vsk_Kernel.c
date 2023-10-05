/*............................................................................*/
#include "vsk_Kernel.h"
/*............................................................................*/
vsk_Kernel * vsk_Kernel_(void) {
    static vsk_Kernel self;
    return &self;
}
/*............................................................................*/
vsk_Kernel * vsk_Kernel_init(
    vsk_Kernel * const self,
    vsk_KernelOnStart const onStart,
    vsk_TaskSchedulerOnIdle const onIdle,
    vsk_CriticalSectionOnEnter const criticalSectionOnEnter,
    vsk_CriticalSectionOnExit const criticalSectionOnExit
) {
    self->_time = vsk_Time_init(vsk_Time_());
    self->_taskScheduler = vsk_TaskScheduler_init(vsk_TaskScheduler_(), onIdle);
    self->_eventTimerClass = vsk_EventTimerClass_init(vsk_EventTimerClass_());
    vsk_CriticalSection_init(
        vsk_CriticalSection_(),
        criticalSectionOnEnter,
        criticalSectionOnExit
    );
    self->_onStart = onStart;
    return self;
}
/*............................................................................*/
void vsk_Kernel_informTickPeriodMillis(
    vsk_Kernel * const self,
    uint16_t const tickPeriodMillis
) {
    vsk_Time_informTickPeriodMillis(self->_time, tickPeriodMillis);
}
/*............................................................................*/
void vsk_Kernel_onSysTick(
    vsk_Kernel * const self
) {
    vsk_Time_onSysTick(self->_time);
    vsk_EventTimerClass_onSysTick(self->_eventTimerClass);
}
/*............................................................................*/
void vsk_Kernel_start(
    vsk_Kernel * const self,
    ut_Array * const taskArray
) {
    self->_onStart();
    vsk_TaskScheduler_start(self->_taskScheduler, taskArray);
}
