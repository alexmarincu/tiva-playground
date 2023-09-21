#include "BlinkyTask.h"

static void BlinkyTask_operation(BlinkyTask * const self, vsk_Event * const event);

BlinkyTask * BlinkyTask_(void) {
    static BlinkyTask self;
    return &self;
}

BlinkyTask * BlinkyTask_init(
    BlinkyTask * const self,
    utl_Queue * const eventQueue
) {
    vsk_Task_init(&self->task, (vsk_TaskOperation)BlinkyTask_operation, eventQueue);
    return self;
}

void BlinkyTask_operation(BlinkyTask * const self, vsk_Event * const event) {
    vsk_Event_dispatch(event);
}
