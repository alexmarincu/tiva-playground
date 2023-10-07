/*............................................................................*/
#include "vsk_TaskScheduler.h"
/*............................................................................*/
vsk_TaskScheduler * vsk_TaskScheduler_(void) {
    static vsk_TaskScheduler self;
    return &self;
}
/*............................................................................*/
vsk_TaskScheduler * vsk_TaskScheduler_init(
    vsk_TaskScheduler * const self,
    vsk_TaskSchedulerOnIdle const onIdle
) {
    self->_taskArray = NULL;
    self->_onIdle = onIdle;
    return self;
}
/*............................................................................*/
void vsk_TaskScheduler_start(
    vsk_TaskScheduler * const self,
    ut_Array * const taskArray
) {
    self->_taskArray = taskArray;
    while (1) {
        for (uint8_t i = 0; i < ut_Array_length(self->_taskArray); i++) {
            vsk_Task * task = ut_Array_get(self->_taskArray, i);
            if (vsk_Task_isReady(task)) {
                vsk_Task_run(task);
            } else {
                self->_onIdle();
            }
        }
    }
}
