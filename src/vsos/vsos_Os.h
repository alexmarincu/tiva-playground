#ifndef VSOS_OS_H
#define VSOS_OS_H
#include "vsos_Scheduler.h"
#include "vsos_SysTime.h"

typedef struct vsos_Os vsos_Os;

vsos_Os * vsos_Os_(void);
vsos_Os * vsos_Os_init(
    vsos_Os * const self,
    utils_Array * const taskArray,
    vsos_Scheduler_onIdleFun const onIdle,
    uint16_t const tickPeriodMillis
);

void vsos_Os_onSysTick(vsos_Os * const self);
void vsos_Os_start(vsos_Os * const self);

#endif // VSOS_OS_H
