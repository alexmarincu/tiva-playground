#include "vsos_Os.h"
#include "vsos_Scheduler.h"

struct vsos_Os {
    vsos_SysTime * sysTime;
    vsos_Scheduler * scheduler;
    vsos_TaskClass * taskClass;
};

vsos_Os * vsos_Os_(void) {
    static vsos_Os self;
    return &self;
}

vsos_Os * vsos_Os_init(vsos_Os * const self) {
    self->sysTime = vsos_SysTime_init(vsos_SysTime_());
    self->scheduler = vsos_Scheduler_init(vsos_Scheduler_());
    self->taskClass = vsos_TaskClass_init(vsos_TaskClass_());
    return self;
}
