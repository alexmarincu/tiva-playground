#include "GreenEvent.h"
#include "led.h"

struct GreenEvent {
    vsk_Event event;
};

static void GreenEvent_dispatch(GreenEvent * const self);

GreenEvent * GreenEvent_(void) {
    static GreenEvent self;
    return &self;
}

GreenEvent * GreenEvent_init(GreenEvent * const self) {
    vsk_Event_init(&self->event, (vsk_Event_dispatchFun)GreenEvent_dispatch);
    return self;
}

static void GreenEvent_dispatch(GreenEvent * const self) {
    LedSetGreen();
}
