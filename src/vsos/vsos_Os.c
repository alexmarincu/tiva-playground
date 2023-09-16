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

vsos_Os * vsos_Os_init(
    vsos_Os * const self,
    utils_Array * const taskArray,
    vsos_Scheduler_onIdleFun const onIdle
) {
    self->sysTime = vsos_SysTime_init(vsos_SysTime_());
    self->scheduler = vsos_Scheduler_init(vsos_Scheduler_(), taskArray, onIdle);
    self->taskClass = vsos_TaskClass_init(vsos_TaskClass_());
    return self;
}

void vsos_Os_start(vsos_Os * const self) {
    vsos_Scheduler_start(self->scheduler);
}
