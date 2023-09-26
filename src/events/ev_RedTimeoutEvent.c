#include "ev_RedTimeoutEvent.h"

struct ev_RedTimeoutEvent {
    vsk_Event event;
};

ev_RedTimeoutEvent * ev_RedTimeoutEvent_(void) {
    static ev_RedTimeoutEvent self;
    return &self;
}

ev_RedTimeoutEvent * ev_RedTimeoutEvent_init(ev_RedTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
