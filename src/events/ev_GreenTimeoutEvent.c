#include "ev_GreenTimeoutEvent.h"

struct ev_GreenTimeoutEvent {
    vsk_Event event;
};

ev_GreenTimeoutEvent * ev_GreenTimeoutEvent_(void) {
    static ev_GreenTimeoutEvent self;
    return &self;
}

ev_GreenTimeoutEvent * ev_GreenTimeoutEvent_init(ev_GreenTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
