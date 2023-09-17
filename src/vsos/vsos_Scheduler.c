#include "vsos_Scheduler.h"

struct vsos_Scheduler {
    utl_Array * taskArray;
    vsos_Scheduler_onIdleFun onIdle;
};

vsos_Scheduler * vsos_Scheduler_(void) {
    static vsos_Scheduler self;
    return &self;
}

vsos_Scheduler * vsos_Scheduler_init(
    vsos_Scheduler * const self,
    vsos_Scheduler_onIdleFun const onIdle,
    utl_Array * const taskArray
) {
    self->taskArray = taskArray;
    self->onIdle = onIdle;
    return self;
}

void vsos_Scheduler_start(vsos_Scheduler * const self) {
    while (1) {
        for (uint8_t i = 0; i < utl_Array_length(self->taskArray); i++) {
            vsos_Task * task = utl_Array_get(self->taskArray, i);
            if (vsos_Task_isReady(task)) {
                vsos_Task_operation(task);
            } else {
                self->onIdle();
            }
            // switch (vsos_Task_getState(task)) {
            //     case vsos_TaskState_READY:
            //         vsos_Task_processReady(task);
            //         break;
            //     case vsos_TaskState_WAITING:
            //         vsos_Task_processWaiting(task);
            //         break;
            //     case vsos_TaskState_SUSPENDED:
            //     default:
            //         break;
            // }
        }
    }
}
