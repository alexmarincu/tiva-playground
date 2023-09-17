#include "BlueEvent.h"
#include "led.h"

struct BlueEvent {
    vsk_Event event;
};

static void BlueEvent_dispatch(BlueEvent * const self);

BlueEvent * BlueEvent_(void) {
    static BlueEvent self;
    return &self;
}

BlueEvent * BlueEvent_init(BlueEvent * const self) {
    vsk_Event_init(&self->event, (vsk_Event_dispatchFun)BlueEvent_dispatch);
    return self;
}

static void BlueEvent_dispatch(BlueEvent * const self) {
    LedSetBlue();
}
