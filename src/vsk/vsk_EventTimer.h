#ifndef VSK_EVENTTIMER_H
#define VSK_EVENTTIMER_H
#include "vsk_Event.h"
#include "vsk_Task.h"
#include <stdint.h>

typedef struct vsk_EventTimer vsk_EventTimer;
struct vsk_EventTimer {
    vsk_Event * event;
    vsk_Task * task;
    vsk_EventTimer * next;
    uint32_t delayMillis;
    uint32_t periodMillis;
};

vsk_EventTimer * vsk_EventTimer_init(vsk_EventTimer * const self, vsk_Event * const event, vsk_Task * const task);
void vsk_EventTimer_arm(vsk_EventTimer * const self, uint32_t const delayMillis, uint32_t const periodMillis);
void vsk_EventTimer_disarm(vsk_EventTimer * const self);

#endif // VSK_EVENTTIMER_H
