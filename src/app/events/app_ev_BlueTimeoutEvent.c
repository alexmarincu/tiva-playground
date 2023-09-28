#include "app_ev_BlueTimeoutEvent.h"

struct app_ev_BlueTimeoutEvent {
    vsk_Event event;
};

app_ev_BlueTimeoutEvent * app_ev_BlueTimeoutEvent_(void) {
    static app_ev_BlueTimeoutEvent self;
    return &self;
}

app_ev_BlueTimeoutEvent * app_ev_BlueTimeoutEvent_init(app_ev_BlueTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
