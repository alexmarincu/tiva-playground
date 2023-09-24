#include "RedTimeoutEvent.h"

struct RedTimeoutEvent {
    vsk_Event event;
};

RedTimeoutEvent * RedTimeoutEvent_(void) {
    static RedTimeoutEvent self;
    return &self;
}

RedTimeoutEvent * RedTimeoutEvent_init(RedTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
