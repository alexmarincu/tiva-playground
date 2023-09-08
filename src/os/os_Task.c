#include "os_Task.h"
#include "os_SysTime.h"
#include <stdbool.h>

os_Task * os_Task_init(os_Task * const self, uint32_t const runRateMillis, os_Task_operationFun const operation) {
    self->startTimeAtLastRunMillis = 0;
    self->runRateMillis = runRateMillis;
    self->operation = operation;
    return self;
}

static bool os_Task_shouldRun(os_Task * const self) {
    uint32_t const elapsedTimeMillis = os_SysTime_getMillisTickCount(os_SysTime_ref()) - self->startTimeAtLastRunMillis;
    return (elapsedTimeMillis >= self->runRateMillis);
}

void os_Task_main(os_Task * const self) {
    if (os_Task_shouldRun(self)) {
        self->startTimeAtLastRunMillis = os_SysTime_getMillisTickCount(os_SysTime_ref());
        self->operation();
    }
}
