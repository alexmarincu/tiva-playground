#include "vsk_EventTimer.h"
#include "vsk_CriticalSection.h"

struct vsk_EventTimerClass {
    vsk_Time * sysTime;
    vsk_EventTimer * eventTimerHead;
};

static void vsk_EventTimer_onSysTick(vsk_EventTimer * const self);

vsk_EventTimerClass * vsk_EventTimerClass_(void) {
    static vsk_EventTimerClass self;
    return &self;
}

vsk_EventTimerClass * vsk_EventTimerClass_init(vsk_EventTimerClass * const self, vsk_Time * const sysTime) {
    self->sysTime = sysTime;
    self->eventTimerHead = 0;
    return self;
}

void vsk_EventTimerClass_register(vsk_EventTimerClass * const self, vsk_EventTimer * const eventTimer) {
    eventTimer->next = self->eventTimerHead;
    self->eventTimerHead = eventTimer;
}

void vsk_EventTimerClass_onSysTick(vsk_EventTimerClass * const self) {
    for (vsk_EventTimer * eventTimer = self->eventTimerHead; (eventTimer != 0); eventTimer = eventTimer->next) {
        vsk_EventTimer_onSysTick(eventTimer);
    }
}

vsk_EventTimer * vsk_EventTimer_init(vsk_EventTimer * const self, vsk_Event * const event) {
    self->klass = vsk_EventTimerClass_();
    self->event = event;
    self->delayMillis = 0;
    self->periodMillis = 0;
    vsk_EventTimerClass_register(vsk_EventTimerClass_(), self);
    return self;
}

void vsk_EventTimer_arm(vsk_EventTimer * const self, uint32_t const delayMillis, uint32_t const periodMillis) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    self->delayMillis = delayMillis;
    self->periodMillis = periodMillis;
    vsk_CriticalSection_exit(vsk_CriticalSection_());
}

void vsk_EventTimer_disarm(vsk_EventTimer * const self) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    self->delayMillis = 0;
    self->periodMillis = 0;
    vsk_CriticalSection_exit(vsk_CriticalSection_());
}

static void vsk_EventTimer_onSysTick(vsk_EventTimer * const self) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    if (self->delayMillis != 0) {
        if (self->delayMillis <= vsk_Time_getTickPeriodMillis(vsk_Time_())) {
            self->delayMillis = self->periodMillis;
            vsk_CriticalSection_exit(vsk_CriticalSection_());
            vsk_Event_raise(self->event);
        } else {
            self->delayMillis -= vsk_Time_getTickPeriodMillis(vsk_Time_());
            vsk_CriticalSection_exit(vsk_CriticalSection_());
        }
    }
}
