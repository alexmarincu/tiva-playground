#include "LButtonPressEvent.h"

struct LButtonPressEvent {
    vsk_Event event;
};

LButtonPressEvent * LButtonPressEvent_(void) {
    static LButtonPressEvent self;
    return &self;
}

LButtonPressEvent * LButtonPressEvent_init(LButtonPressEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
