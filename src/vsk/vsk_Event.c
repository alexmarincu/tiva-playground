#include "vsk_Event.h"
#include <stddef.h>

vsk_Event * vsk_Event_init(vsk_Event * const self) {
    self->taskMessageHead = 0;
    return self;
}

void vsk_Event_raise(vsk_Event * const self) {
    for (vsk_TaskMessage * message = self->taskMessageHead; (message != 0); message = message->next) {
        vsk_Task_postMessage(message->receiver, message);
    }
}

void vsk_Event_register(vsk_Event * const self, vsk_TaskMessage * const message) {
    message->next = self->taskMessageHead;
    self->taskMessageHead = message;
}
