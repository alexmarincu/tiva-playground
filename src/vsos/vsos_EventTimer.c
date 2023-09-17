#include "vsos_EventTimer.h"
#include "vsos_EventTimerManager.h"

vsos_EventTimer * vsos_EventTimer_init(vsos_EventTimer * const self, vsos_Event * const event, vsos_Task * const task) {
    self->event = event;
    self->task = task;
    self->delayMillis = 0;
    self->periodMillis = 0;
    vsos_EventTimerManager_register(vsos_EventTimerManager_(), self);
    return self;
}

void vsos_EventTimer_arm(vsos_EventTimer * const self, uint32_t const delayMillis, uint32_t const periodMillis) {
    self->delayMillis = delayMillis;
    self->periodMillis = periodMillis;
}

void vsos_EventTimer_disarm(vsos_EventTimer * const self) {
    self->delayMillis = 0;
    self->periodMillis = 0;
}
