#include "ev_BlueTimeoutEvent.h"

struct ev_BlueTimeoutEvent {
    vsk_Event event;
};

ev_BlueTimeoutEvent * ev_BlueTimeoutEvent_(void) {
    static ev_BlueTimeoutEvent self;
    return &self;
}

ev_BlueTimeoutEvent * ev_BlueTimeoutEvent_init(ev_BlueTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
