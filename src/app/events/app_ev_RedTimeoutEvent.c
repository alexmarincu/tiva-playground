#include "app_ev_RedTimeoutEvent.h"

struct app_ev_RedTimeoutEvent {
    vsk_Event event;
};

app_ev_RedTimeoutEvent * app_ev_RedTimeoutEvent_(void) {
    static app_ev_RedTimeoutEvent self;
    return &self;
}

app_ev_RedTimeoutEvent * app_ev_RedTimeoutEvent_init(app_ev_RedTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
