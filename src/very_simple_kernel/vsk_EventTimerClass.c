/*............................................................................*/
#include "vsk_EventTimerClass.h"
/*............................................................................*/
vsk_EventTimerClass * vsk_EventTimerClass_(void) {
    static vsk_EventTimerClass self;
    return &self;
}
/*............................................................................*/
vsk_EventTimerClass * vsk_EventTimerClass_init(
    vsk_EventTimerClass * const self
) {
    self->_eventTimerHead = 0;
    return self;
}
/*............................................................................*/
void vsk_EventTimerClass_register(
    vsk_EventTimerClass * const self,
    vsk_EventTimer * const eventTimer
) {
    eventTimer->_next = self->_eventTimerHead;
    self->_eventTimerHead = eventTimer;
}
/*............................................................................*/
void vsk_EventTimerClass_onSysTick(
    vsk_EventTimerClass * const self
) {
    for (
        vsk_EventTimer * eventTimer = self->_eventTimerHead;
        (eventTimer != 0);
        eventTimer = eventTimer->_next
    ) {
        vsk_EventTimer_onSysTick(eventTimer);
    }
}
