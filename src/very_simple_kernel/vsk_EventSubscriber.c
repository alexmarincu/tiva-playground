#include "vsk_Event.h"

vsk_EventSubscriber * vsk_EventSubscriber_init(
    vsk_EventSubscriber * const self,
    vsk_Task * const task,
    void * const recipient,
    vsk_MessageHandler const handler
) {
    self->task = task;
    vsk_Message_init(&self->message, recipient, handler);
    self->next = 0;
    return self;
}
