#include "BlinkyTask.h"

static void BlinkyTask_operation(BlinkyTask * const self, vsos_Event * const event);

BlinkyTask * BlinkyTask_(void) {
    static BlinkyTask self;
    return &self;
}

BlinkyTask * BlinkyTask_init(
    BlinkyTask * const self,
    utl_Queue * const eventQueue
) {
    vsos_Task_init(&self->task, (vsos_Task_operationFun)BlinkyTask_operation, eventQueue);
    return self;
}

void BlinkyTask_operation(BlinkyTask * const self, vsos_Event * const event) {
    vsos_Event_dispatch(event);
}
