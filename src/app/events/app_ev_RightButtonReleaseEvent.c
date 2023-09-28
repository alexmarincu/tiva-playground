#include "app_ev_RightButtonReleaseEvent.h"

struct app_ev_RightButtonReleaseEvent {
    vsk_Event event;
};

app_ev_RightButtonReleaseEvent * app_ev_RightButtonReleaseEvent_(void) {
    static app_ev_RightButtonReleaseEvent self;
    return &self;
}

app_ev_RightButtonReleaseEvent * app_ev_RightButtonReleaseEvent_init(app_ev_RightButtonReleaseEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
