#include "GreenEvent.h"
#include "led.h"

struct GreenEvent {
    vsos_Event event;
};

static void GreenEvent_dispatch(GreenEvent * const self);

GreenEvent * GreenEvent_(void) {
    static GreenEvent self;
    return &self;
}

GreenEvent * GreenEvent_init(GreenEvent * const self) {
    vsos_Event_init(&self->event, (vsos_Event_dispatchFun)GreenEvent_dispatch);
    return self;
}

static void GreenEvent_dispatch(GreenEvent * const self) {
    LedSetGreen();
}
