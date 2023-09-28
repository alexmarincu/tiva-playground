#include "app_ev_GreenTimeoutEvent.h"

struct app_ev_GreenTimeoutEvent {
    vsk_Event event;
};

app_ev_GreenTimeoutEvent * app_ev_GreenTimeoutEvent_(void) {
    static app_ev_GreenTimeoutEvent self;
    return &self;
}

app_ev_GreenTimeoutEvent * app_ev_GreenTimeoutEvent_init(app_ev_GreenTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
