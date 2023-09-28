#include "app_ev_LeftButtonPressEvent.h"

struct app_ev_LeftButtonPressEvent {
    vsk_Event event;
};

app_ev_LeftButtonPressEvent * app_ev_LeftButtonPressEvent_(void) {
    static app_ev_LeftButtonPressEvent self;
    return &self;
}

app_ev_LeftButtonPressEvent * app_ev_LeftButtonPressEvent_init(app_ev_LeftButtonPressEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
