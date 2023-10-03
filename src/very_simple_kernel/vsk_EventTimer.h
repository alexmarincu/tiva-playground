#ifndef VSK_EVENTTIMER_H
#define VSK_EVENTTIMER_H
/*............................................................................*/
typedef struct vsk_EventTimer vsk_EventTimer;
#include "vsk_Event.h"
#include "vsk_EventTimerClass.h"
#include <stdint.h>
/*............................................................................*/
struct vsk_EventTimer {
    vsk_EventTimerClass const * _klass;
    vsk_Event * _event;
    uint32_t _delayMillis;
    uint32_t _periodMillis;
    vsk_EventTimer * _next;
};
/*............................................................................*/
vsk_EventTimer * vsk_EventTimer_init(
    vsk_EventTimer * const self,
    vsk_Event * const event
);
void vsk_EventTimer_arm(
    vsk_EventTimer * const self,
    uint32_t const delayMillis,
    uint32_t const periodMillis
);
void vsk_EventTimer_disarm(
    vsk_EventTimer * const self
);
void vsk_EventTimer_onSysTick(
    vsk_EventTimer * const self
);
#endif // VSK_EVENTTIMER_H
