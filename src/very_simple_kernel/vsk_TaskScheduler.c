#include "vsk_TaskScheduler.h"

struct vsk_TaskScheduler {
    ut_Array * taskArray;
    vsk_TaskSchedulerOnIdle onIdle;
};

vsk_TaskScheduler * vsk_TaskScheduler_(void) {
    static vsk_TaskScheduler self;
    return &self;
}

vsk_TaskScheduler * vsk_TaskScheduler_init(
    vsk_TaskScheduler * const self,
    vsk_TaskSchedulerOnIdle const onIdle,
    ut_Array * const taskArray
) {
    self->taskArray = taskArray;
    self->onIdle = onIdle;
    return self;
}

void vsk_TaskScheduler_start(vsk_TaskScheduler * const self) {
    while (1) {
        for (uint8_t i = 0; i < ut_Array_length(self->taskArray); i++) {
            vsk_Task * task = ut_Array_get(self->taskArray, i);
            if (vsk_Task_isReady(task)) {
                vsk_Task_run(task);
            } else {
                self->onIdle();
            }
        }
    }
}
