/*............................................................................*/
#include "vsk_Kernel.h"
#include "vsk_NodeClass.h"
#include "vsk_OnStartEvent.h"
/*............................................................................*/
vsk_Kernel * vsk_Kernel_(void) {
    static vsk_Kernel self;
    return &self;
}
/*............................................................................*/
vsk_Kernel * vsk_Kernel_init(
    vsk_Kernel * const self,
    vsk_KernelOnStart const onKernelStart,
    vsk_TaskSchedulerOnIdle const onIdle,
    vsk_CriticalSectionOnEnter const onCriticalSectionEnter,
    vsk_CriticalSectionOnExit const onCriticalSectionExit,
    vsk_AssertOnFail const onAssertFail,
    vsk_Node * const nodes,
    size_t const capacity
) {
    self->_time = vsk_Time_init(vsk_Time_());
    self->_taskScheduler = vsk_TaskScheduler_init(vsk_TaskScheduler_(), onIdle);
    self->_eventTimerSupervisor = vsk_EventTimerSupervisor_init(vsk_EventTimerSupervisor_());
    self->_inboxSupervisor = vsk_InboxSupervisor_init(vsk_InboxSupervisor_());
    vsk_CriticalSection_init(
        vsk_CriticalSection_(),
        onCriticalSectionEnter,
        onCriticalSectionExit
    );
    vsk_NodeClass_init(vsk_NodeClass_(), nodes, capacity);
    vsk_Assert_init(vsk_Assert_(), onAssertFail);
    vsk_OnStartEvent_init(vsk_OnStartEvent_());
    self->_onStart = onKernelStart;
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
    vsk_EventTimerSupervisor_onSysTick(self->_eventTimerSupervisor);
    vsk_InboxSupervisor_onSysTick(self->_inboxSupervisor);
}
/*............................................................................*/
void vsk_Kernel_start(
    vsk_Kernel * const self
) {
    self->_onStart();
    vsk_Event_raise((vsk_Event *)vsk_OnStartEvent_());
    vsk_TaskScheduler_start(self->_taskScheduler);
}
