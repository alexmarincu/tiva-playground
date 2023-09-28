#ifndef VSK_EVENTTIMER_H
#define VSK_EVENTTIMER_H
#include "vsk_Event.h"
#include "vsk_Task.h"
#include "vsk_Time.h"

#include <stdint.h>

typedef struct vsk_EventTimerClass vsk_EventTimerClass;
typedef struct vsk_EventTimer vsk_EventTimer;
struct vsk_EventTimer {
    vsk_EventTimerClass const * klass;
    vsk_Event * event;
    uint32_t delayMillis;
    uint32_t periodMillis;
    vsk_EventTimer * next;
};

vsk_EventTimerClass * vsk_EventTimerClass_(void);
vsk_EventTimerClass * vsk_EventTimerClass_init(vsk_EventTimerClass * const self, vsk_Time * const sysTime);
void vsk_EventTimerClass_register(vsk_EventTimerClass * const self, vsk_EventTimer * const eventTimer);
void vsk_EventTimerClass_onSysTick(vsk_EventTimerClass * const self);
vsk_EventTimer * vsk_EventTimer_init(vsk_EventTimer * const self, vsk_Event * const event);
void vsk_EventTimer_arm(vsk_EventTimer * const self, uint32_t const delayMillis, uint32_t const periodMillis);
void vsk_EventTimer_disarm(vsk_EventTimer * const self);

#endif // VSK_EVENTTIMER_H
