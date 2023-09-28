#include "app_ev_LeftButtonReleaseEvent.h"

struct app_ev_LeftButtonReleaseEvent {
    vsk_Event event;
};

app_ev_LeftButtonReleaseEvent * app_ev_LeftButtonReleaseEvent_(void) {
    static app_ev_LeftButtonReleaseEvent self;
    return &self;
}

app_ev_LeftButtonReleaseEvent * app_ev_LeftButtonReleaseEvent_init(app_ev_LeftButtonReleaseEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
