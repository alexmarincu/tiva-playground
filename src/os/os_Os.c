#include "os_Os.h"
#include "os_Scheduler.h"

os_Os * os_Os_ref(void) {
    static os_Os self;
    return &self;
}

os_Os * os_Os_init(os_Os * const self) {
    self->sysTime = os_SysTime_init(os_SysTime_ref());
    return self;
}

void os_Os_main(os_Os * const self) {
    while (1) {
        os_Scheduler_main();
    }
}
