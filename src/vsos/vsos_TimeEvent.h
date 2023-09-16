#ifndef VSOS_TIMEEVENT_H
#define VSOS_TIMEEVENT_H
#include "vsos_Event.h"
#include "vsos_Task.h"
#include <stdint.h>

typedef struct vsos_TimeEvent vsos_TimeEvent;
struct vsos_TimeEvent {
    vsos_Event * event;
    vsos_Task * task;
    vsos_TimeEvent * next;
    uint32_t delayMillis;
    uint32_t periodMillis;
};

vsos_TimeEvent * vsos_TimeEvent_init(vsos_TimeEvent * const self, vsos_Event * const event, vsos_Task * const task);
void vsos_TimeEvent_arm(vsos_TimeEvent * const self, uint32_t const delayMillis, uint32_t const periodMillis);
void vsos_TimeEvent_disarm(vsos_TimeEvent * const self);
void vsos_TimeEvent_onSysTick(void);

#endif // VSOS_TIMEEVENT_H
