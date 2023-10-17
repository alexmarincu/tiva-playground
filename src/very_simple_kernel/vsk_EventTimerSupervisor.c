/*............................................................................*/
#include "vsk_EventTimerSupervisor.h"
/*............................................................................*/
vsk_EventTimerSupervisor * vsk_EventTimerSupervisor_(void) {
    static vsk_EventTimerSupervisor self;
    return &self;
}
/*............................................................................*/
vsk_EventTimerSupervisor * vsk_EventTimerSupervisor_init(
    vsk_EventTimerSupervisor * const self
) {
    vsk_LinkedList_init(&self->_eventTimers);
    return self;
}
/*............................................................................*/
void vsk_EventTimerSupervisor_register(
    vsk_EventTimerSupervisor * const self,
    vsk_EventTimer * const eventTimer
) {
    vsk_LinkedList_addFirst(&self->_eventTimers, eventTimer);
}
/*............................................................................*/
static void onSysTick(vsk_EventTimer * const eventTimer) {
    vsk_EventTimer_onSysTick(eventTimer);
}
/*............................................................................*/
void vsk_EventTimerSupervisor_onSysTick(
    vsk_EventTimerSupervisor * const self
) {
    vsk_LinkedList_forEach(
        &self->_eventTimers,
        (vsk_LinkedListForEachOperation)onSysTick
    );
}
