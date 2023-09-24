#ifndef VSK_EVENT_H
#define VSK_EVENT_H
#include "vsk_Task.h"

typedef struct vsk_Event vsk_Event;
typedef struct vsk_EventClient vsk_EventClient;
// typedef void (*vsk_EventMessageHandler)(vsk_Task * const self);
struct vsk_EventClient {
    vsk_Task * task;
    vsk_TaskMessage message;
    vsk_EventClient * next;
};
struct vsk_Event {
    vsk_EventClient * eventClientHead;
};

vsk_Event * vsk_Event_init(vsk_Event * const self);
void vsk_Event_raise(vsk_Event * const self);
void vsk_Event_subscribe(vsk_Event * const self, vsk_EventClient * const client);

#endif // VSK_EVENT_H
