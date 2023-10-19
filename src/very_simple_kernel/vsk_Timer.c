/*............................................................................*/
#include "vsk_Timer.h"
#include "vsk_Assert.h"
#include "vsk_CriticalSection.h"
#include "vsk_Time.h"
/*............................................................................*/
vsk_Timer * vsk_Timer_init(
    vsk_Timer * const self,
    vsk_TimerCallback const callback
) {
    vsk_Assert_true(vsk_Assert_(), callback != NULL);
    self->_callback = callback;
    self->_delayMillis = 0;
    self->_periodMillis = 0;
    vsk_TimerSupervisor_register(vsk_TimerSupervisor_(), self);
    return self;
}
/*............................................................................*/
void vsk_Timer_arm(
    vsk_Timer * const self,
    uint32_t const delayMillis,
    uint32_t const periodMillis
) {
    vsk_Assert_true(vsk_Assert_(), delayMillis > 0);
    self->_delayMillis = delayMillis;
    self->_periodMillis = periodMillis;
}
/*............................................................................*/
void vsk_Timer_disarm(
    vsk_Timer * const self
) {
    self->_delayMillis = 0;
    self->_periodMillis = 0;
}
/*............................................................................*/
void vsk_Timer_onSysTick(
    vsk_Timer * const self
) {
    if (self->_delayMillis != 0) {
        if (self->_delayMillis <= vsk_Time_getTickPeriodMillis(vsk_Time_())) {
            self->_delayMillis = self->_periodMillis;
            self->_callback(self);
        } else {
            self->_delayMillis -= vsk_Time_getTickPeriodMillis(vsk_Time_());
        }
    }
}
