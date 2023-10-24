/*............................................................................*/
#include "vsk_TimerSupervisor.h"
/*............................................................................*/
vsk_TimerSupervisor * vsk_TimerSupervisor_(void) {
    static vsk_TimerSupervisor self;
    return &self;
}
/*............................................................................*/
vsk_TimerSupervisor * vsk_TimerSupervisor_init(
    vsk_TimerSupervisor * const self
) {
    vsk_LinkedList_init(&self->_timers);
    return self;
}
/*............................................................................*/
void vsk_TimerSupervisor_register(
    vsk_TimerSupervisor * const self, vsk_Timer * const timer
) {
    vsk_LinkedList_addLast(&self->_timers, timer);
}
/*............................................................................*/
static void vsk_onSysTick(vsk_Timer * const timer) {
    vsk_Timer_onSysTick(timer);
}
/*............................................................................*/
void vsk_TimerSupervisor_onSysTick(vsk_TimerSupervisor * const self) {
    vsk_LinkedList_forEach(
        &self->_timers, (vsk_LinkedListForEachOperation)vsk_onSysTick
    );
}
