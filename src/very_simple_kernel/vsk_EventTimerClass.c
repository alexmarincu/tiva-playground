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
    vsk_LinkedList_init(&self->_eventTimers);
    return self;
}
/*............................................................................*/
void vsk_EventTimerClass_register(
    vsk_EventTimerClass * const self,
    vsk_EventTimer * const eventTimer
) {
    vsk_LinkedList_addFirst(&self->_eventTimers, eventTimer);
}
/*............................................................................*/
static bool onSysTick(void * const item, void * const data) {
    vsk_EventTimer * const eventTimer = item;
    (void)data;
    vsk_EventTimer_onSysTick(eventTimer);
    return false;
}
/*............................................................................*/
void vsk_EventTimerClass_onSysTick(
    vsk_EventTimerClass * const self
) {
    vsk_LinkedList_forEach(&self->_eventTimers, onSysTick, NULL);
}
