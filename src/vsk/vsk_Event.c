#include "vsk_Event.h"
#include <stddef.h>

vsk_Event * vsk_Event_init(vsk_Event * const self) {
    self->eventClientHead = 0;
    return self;
}

void vsk_Event_raise(vsk_Event * const self) {
    for (vsk_EventClient * client = self->eventClientHead; (client != 0); client = client->next) {
        vsk_Task_postMessage(client->task, &client->message);
    }
}

void vsk_Event_subscribe(vsk_Event * const self, vsk_EventClient * const client) {
    client->next = self->eventClientHead;
    self->eventClientHead = client;
}
