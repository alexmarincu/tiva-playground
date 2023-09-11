#include "os_Os.h"
#include "os_Scheduler.h"

struct os_Os {
    os_SysTime * sysTime;
    os_Scheduler * scheduler;
};

os_Os * os_Os_(void) {
    static os_Os self;
    return &self;
}

os_Os * os_Os_init(os_Os * const self, os_Task ** const tasks, uint8_t const taskCount) {
    self->sysTime = os_SysTime_init(os_SysTime_());
    self->scheduler = os_Scheduler_init(os_Scheduler_(), tasks, taskCount);
    os_TaskClass_init(os_TaskClass_());
    return self;
}

void os_Os_main(os_Os * const self) {
    while (1) {
        os_Scheduler_main(self->scheduler);
    }
}
