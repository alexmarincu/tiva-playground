#ifndef VSOS_EVENTTIMER_H
#define VSOS_EVENTTIMER_H
#include "vsos_Event.h"
#include "vsos_Task.h"
#include <stdint.h>

typedef struct vsos_EventTimer vsos_EventTimer;
struct vsos_EventTimer {
    vsos_Event * event;
    vsos_Task * task;
    vsos_EventTimer * next;
    uint32_t delayMillis;
    uint32_t periodMillis;
};

vsos_EventTimer * vsos_EventTimer_init(vsos_EventTimer * const self, vsos_Event * const event, vsos_Task * const task);
void vsos_EventTimer_arm(vsos_EventTimer * const self, uint32_t const delayMillis, uint32_t const periodMillis);
void vsos_EventTimer_disarm(vsos_EventTimer * const self);

#endif // VSOS_EVENTTIMER_H
