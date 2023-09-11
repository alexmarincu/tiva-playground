#include "os_Scheduler.h"

struct os_Scheduler {
    os_Task ** tasks;
    uint8_t taskCount;
};

os_Scheduler * os_Scheduler_(void) {
    static os_Scheduler self;
    return &self;
}

os_Scheduler * os_Scheduler_init(os_Scheduler * const self, os_Task ** const tasks, uint8_t const taskCount) {
    self->tasks = tasks;
    self->taskCount = taskCount;
    return self;
}

void os_Scheduler_main(os_Scheduler * const self) {
    for (uint8_t i = 0; i < self->taskCount; i++) {
        os_Task * task = self->tasks[i];
        switch (os_Task_getState(task)) {
            case os_TaskState_READY:
                os_Task_processReady(task);
                break;
            case os_TaskState_WAITING:
                os_Task_processWaiting(task);
                break;
            case os_TaskState_SUSPENDED:
            default:
                break;
        }
    }
}
