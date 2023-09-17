#include "vsk_EventTimerManager.h"

vsk_EventTimerManager * vsk_EventTimerManager_(void) {
    static vsk_EventTimerManager self;
    return &self;
}

vsk_EventTimerManager * vsk_EventTimerManager_init(vsk_EventTimerManager * const self) {
    self->eventTimerHead = 0;
    return self;
}

void vsk_EventTimerManager_register(vsk_EventTimerManager * const self, vsk_EventTimer * const eventTimer) {
    eventTimer->next = self->eventTimerHead;
    self->eventTimerHead = eventTimer;
}

void vsk_EventTimerManager_onSysTick(vsk_EventTimerManager * const self) {
    for (vsk_EventTimer * eventTimer = self->eventTimerHead; (eventTimer != 0); eventTimer = eventTimer->next) {
        if (eventTimer->delayMillis != 0) {
            if (eventTimer->delayMillis == 1) {
                eventTimer->delayMillis = eventTimer->periodMillis;
                vsk_Task_postEvent(eventTimer->task, eventTimer->event);
            } else {
                eventTimer->delayMillis--;
            }
        }
    }
}
