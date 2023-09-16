#include "vsos_TimeEvent.h"

static vsos_TimeEvent * timeEvtHead = 0;

vsos_TimeEvent * vsos_TimeEvent_init(vsos_TimeEvent * const self, vsos_Event * const event, vsos_Task * const task) {
    self->event = event;
    self->task = task;
    self->delayMillis = 0;
    self->periodMillis = 0;
    self->next = timeEvtHead;
    timeEvtHead = self;
    return self;
}

void vsos_TimeEvent_arm(vsos_TimeEvent * const self, uint32_t const delayMillis, uint32_t const periodMillis) {
    self->delayMillis = delayMillis;
    self->periodMillis = periodMillis;
}

void vsos_TimeEvent_disarm(vsos_TimeEvent * const self) {
    self->delayMillis = 0;
    self->periodMillis = 0;
}

void vsos_TimeEvent_onSysTick(void) {
    for (vsos_TimeEvent * timeEvent = timeEvtHead; (timeEvent != 0); timeEvent = timeEvent->next) {
        if (timeEvent->delayMillis == 0) {

        } else if (timeEvent->delayMillis == 1) {
            timeEvent->delayMillis = timeEvent->periodMillis;
            vsos_Task_postEvent(timeEvent->task, timeEvent->event);
        } else {
            timeEvent->delayMillis--;
        }
    }
}
