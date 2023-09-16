#include "vsos_Scheduler.h"

struct vsos_Scheduler {
    utils_Array * taskArray;
};

vsos_Scheduler * vsos_Scheduler_(void) {
    static vsos_Scheduler self;
    return &self;
}

vsos_Scheduler * vsos_Scheduler_init(vsos_Scheduler * const self) {
    self->taskArray = 0;
    return self;
}

void vsos_Scheduler_setTaskArray(vsos_Scheduler * const self, utils_Array * const taskArray) {
    self->taskArray = taskArray;
}

void vsos_Scheduler_start(vsos_Scheduler * const self) {
    while (1) {
        for (uint8_t i = 0; i < utils_Array_length(self->taskArray); i++) {
            vsos_Task * task = utils_Array_get(self->taskArray, i);
            switch (vsos_Task_getState(task)) {
                case vsos_TaskState_READY:
                    vsos_Task_processReady(task);
                    break;
                case vsos_TaskState_WAITING:
                    vsos_Task_processWaiting(task);
                    break;
                case vsos_TaskState_SUSPENDED:
                default:
                    break;
            }
        }
    }
}
