#include "vsos_EventTimerManager.h"

vsos_EventTimerManager * vsos_EventTimerManager_(void) {
    static vsos_EventTimerManager self;
    return &self;
}

vsos_EventTimerManager * vsos_EventTimerManager_init(vsos_EventTimerManager * const self) {
    self->eventTimerHead = 0;
    return self;
}

void vsos_EventTimerManager_register(vsos_EventTimerManager * const self, vsos_EventTimer * const eventTimer) {
    eventTimer->next = self->eventTimerHead;
    self->eventTimerHead = eventTimer;
}

void vsos_EventTimerManager_onSysTick(vsos_EventTimerManager * const self) {
    for (vsos_EventTimer * eventTimer = self->eventTimerHead; (eventTimer != 0); eventTimer = eventTimer->next) {
        if (eventTimer->delayMillis != 0) {
            if (eventTimer->delayMillis == 1) {
                eventTimer->delayMillis = eventTimer->periodMillis;
                vsos_Task_postEvent(eventTimer->task, eventTimer->event);
            } else {
                eventTimer->delayMillis--;
            }
        }
    }
}
