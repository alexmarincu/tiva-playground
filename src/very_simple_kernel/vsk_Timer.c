/*............................................................................*/
#include "vsk_Timer.h"
#include "vsk_Assert.h"
#include "vsk_Time.h"
/*............................................................................*/
vsk_Timer * vsk_Timer_init(
    vsk_Timer * const self,
    uint32_t const delayMillis,
    uint32_t const periodMillis,
    vsk_TimerCallback const callback,
    void * const data
) {
    vsk_Assert_true(vsk_Assert_(), delayMillis > 0);
    self->_delayMillis = delayMillis;
    self->_periodMillis = periodMillis;
    self->_millisCount = 0;
    self->_callback = callback;
    self->_data = data;
    vsk_TimerSupervisor_register(vsk_TimerSupervisor_(), self);
    return self;
}
/*............................................................................*/
void vsk_Timer_start(vsk_Timer * const self) {
    self->_millisCount = self->_delayMillis;
}
/*............................................................................*/
void vsk_Timer_stop(vsk_Timer * const self) {
    self->_millisCount = 0;
}
/*............................................................................*/
void vsk_Timer_onSysTick(vsk_Timer * const self) {
    if (self->_millisCount != 0) {
        if (self->_millisCount <= vsk_Time_getTickPeriodMillis(vsk_Time_())) {
            self->_millisCount = self->_periodMillis;
            self->_callback(self);
        } else {
            self->_millisCount -= vsk_Time_getTickPeriodMillis(vsk_Time_());
        }
    }
}
