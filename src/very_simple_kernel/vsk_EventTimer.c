#include "vsk_EventTimer.h"
#include "vsk_EventTimerManager.h"

vsk_EventTimer * vsk_EventTimer_init(vsk_EventTimer * const self, vsk_Event * const event) {
    self->event = event;
    self->delayMillis = 0;
    self->periodMillis = 0;
    vsk_EventTimerManager_register(vsk_EventTimerManager_(), self);
    return self;
}

void vsk_EventTimer_arm(vsk_EventTimer * const self, uint32_t const delayMillis, uint32_t const periodMillis) {
    self->delayMillis = delayMillis;
    self->periodMillis = periodMillis;
}

void vsk_EventTimer_disarm(vsk_EventTimer * const self) {
    self->delayMillis = 0;
    self->periodMillis = 0;
}

void vsk_EventTimer_onSysTick(vsk_EventTimer * const self) {
    if (self->delayMillis != 0) {
        if (self->delayMillis <= vsk_Time_getTickPeriodMillis(vsk_Time_())) {
            self->delayMillis = self->periodMillis;
            vsk_Event_raise(self->event);
        } else {
            self->delayMillis -= vsk_Time_getTickPeriodMillis(vsk_Time_());
        }
    }
}
