/*............................................................................*/
#include "vsk_EventTimer.h"
#include "vsk_CriticalSection.h"
#include "vsk_Time.h"
/*............................................................................*/
vsk_EventTimer * vsk_EventTimer_init(
    vsk_EventTimer * const self,
    vsk_Event * const event
) {
    self->_klass = vsk_EventTimerClass_();
    self->_event = event;
    self->_delayMillis = 0;
    self->_periodMillis = 0;
    vsk_EventTimerClass_register(vsk_EventTimerClass_(), self);
    return self;
}
/*............................................................................*/
void vsk_EventTimer_arm(
    vsk_EventTimer * const self,
    uint32_t const delayMillis,
    uint32_t const periodMillis
) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    self->_delayMillis = delayMillis;
    self->_periodMillis = periodMillis;
    vsk_CriticalSection_exit(vsk_CriticalSection_());
}
/*............................................................................*/
void vsk_EventTimer_disarm(
    vsk_EventTimer * const self
) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    self->_delayMillis = 0;
    self->_periodMillis = 0;
    vsk_CriticalSection_exit(vsk_CriticalSection_());
}
/*............................................................................*/
void vsk_EventTimer_onSysTick(
    vsk_EventTimer * const self
) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    if (self->_delayMillis != 0) {
        if (self->_delayMillis <= vsk_Time_getTickPeriodMillis(vsk_Time_())) {
            self->_delayMillis = self->_periodMillis;
            vsk_CriticalSection_exit(vsk_CriticalSection_());
            vsk_Event_raise(self->_event);
        } else {
            self->_delayMillis -= vsk_Time_getTickPeriodMillis(vsk_Time_());
            vsk_CriticalSection_exit(vsk_CriticalSection_());
        }
    }
}
