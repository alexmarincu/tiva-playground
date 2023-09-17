#ifndef VSOS_OS_H
#define VSOS_OS_H
#include "vsos_Scheduler.h"
#include "vsos_SysTime.h"

typedef struct vsos_Os vsos_Os;
typedef void (*vsos_Os_onStartFun)(void);

vsos_Os * vsos_Os_(void);
vsos_Os * vsos_Os_init(
    vsos_Os * const self,
    vsos_Os_onStartFun const onStart,
    uint16_t const tickPeriodMillis,
    vsos_Scheduler_onIdleFun const onIdle,
    utils_Array * const taskArray
);

void vsos_Os_onSysTick(vsos_Os * const self);
void vsos_Os_start(vsos_Os * const self);

#endif // VSOS_OS_H
