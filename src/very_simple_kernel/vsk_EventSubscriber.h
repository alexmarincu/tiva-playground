#ifndef VSK_EVENTSUBSCRIBER_H
#define VSK_EVENTSUBSCRIBER_H
#include "vsk_Task.h"

typedef struct vsk_EventSubscriber vsk_EventSubscriber;
struct vsk_EventSubscriber {
    vsk_Task * task;
    vsk_TaskMessage message;
    vsk_EventSubscriber * next;
};

vsk_EventSubscriber * vsk_EventSubscriber_init(
    vsk_EventSubscriber * const self,
    vsk_Task * const task,
    vsk_TaskMessage const message
);

#endif // VSK_EVENTSUBSCRIBER_H
