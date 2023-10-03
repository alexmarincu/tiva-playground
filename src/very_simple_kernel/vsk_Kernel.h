#ifndef VSK_KERNEL_H
#define VSK_KERNEL_H
/*............................................................................*/
typedef struct vsk_Kernel vsk_Kernel;
typedef void (*vsk_KernelOnStart)(void);
#include "vsk_CriticalSection.h"
#include "vsk_EventTimerClass.h"
#include "vsk_TaskScheduler.h"
#include "vsk_Time.h"
/*............................................................................*/
struct vsk_Kernel {
    vsk_Time * _time;
    vsk_TaskScheduler * _taskScheduler;
    vsk_EventTimerClass * _eventTimerClass;
    vsk_KernelOnStart _onStart;
};
/*............................................................................*/
vsk_Kernel * vsk_Kernel_(void);
vsk_Kernel * vsk_Kernel_init(
    vsk_Kernel * const self,
    vsk_KernelOnStart const onStart,
    vsk_TaskSchedulerOnIdle const onIdle,
    vsk_CriticalSectionEnter const enterCriticalSection,
    vsk_CriticalSectionExit const exitCriticalSection
);
void vsk_Kernel_informTickPeriodMillis(
    vsk_Kernel * const self,
    uint16_t const tickPeriodMillis
);
void vsk_Kernel_onSysTick(
    vsk_Kernel * const self
);
void vsk_Kernel_start(
    vsk_Kernel * const self,
    ut_Array * const taskArray
);
#endif // VSK_KERNEL_H
