#include "vsk_Event.h"

vsk_EventSubscriber * vsk_EventSubscriber_init(
    vsk_EventSubscriber * const self,
    vsk_Task * const task,
    vsk_TaskMessage const message
) {
    self->task = task;
    self->message = message;
    self->next = 0;
    return self;
}
