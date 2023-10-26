/*............................................................................*/
#include "vsk.h"
/*............................................................................*/
#include "vsk_NodeClass.h"
#include "vsk_OnStartEvent.h"
#include "vsk_Time.h"
#include "vsk_TimerSupervisor.h"
/*............................................................................*/
void vsk_start(
    uint16_t const tickPeriodMillis,
    vsk_TaskSchedulerOnStart const onStart,
    vsk_TaskSchedulerOnIdle const onIdle,
    vsk_CriticalSectionOnEnter const onCriticalSectionEnter,
    vsk_CriticalSectionOnExit const onCriticalSectionExit,
    vsk_AssertOnFail const onAssertFail,
    vsk_Node * const nodes,
    size_t const capacity
) {
    vsk_Time_init(vsk_Time_(), tickPeriodMillis);
    vsk_TaskScheduler_init(vsk_TaskScheduler_(), onStart, onIdle);
    vsk_TimerSupervisor_init(vsk_TimerSupervisor_());
    vsk_CriticalSection_init(
        vsk_CriticalSection_(), onCriticalSectionEnter, onCriticalSectionExit
    );
    vsk_NodeClass_init(vsk_NodeClass_(), nodes, capacity);
    vsk_Assert_init(vsk_Assert_(), onAssertFail);
    vsk_OnStartEvent_init(vsk_OnStartEvent_());
    vsk_TaskScheduler_start(vsk_TaskScheduler_());
}
/*............................................................................*/
void vsk_onSysTick(void) {
    vsk_Time_onSysTick(vsk_Time_());
    vsk_TimerSupervisor_onSysTick(vsk_TimerSupervisor_());
}
