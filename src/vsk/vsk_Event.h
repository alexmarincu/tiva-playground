#ifndef VSK_EVENT_H
#define VSK_EVENT_H
#include "vsk_Task.h"

typedef struct vsk_Event vsk_Event;
typedef void (*vsk_EventDispatch)(vsk_Event * const self);
struct vsk_Event {
    vsk_TaskMessage * taskMessageHead;
};

vsk_Event * vsk_Event_init(vsk_Event * const self);
void vsk_Event_raise(vsk_Event * const self);
void vsk_Event_register(vsk_Event * const self, vsk_TaskMessage * const message);

#endif // VSK_EVENT_H
