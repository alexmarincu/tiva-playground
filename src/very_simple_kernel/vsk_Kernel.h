#ifndef VSK_KERNEL_H
#define VSK_KERNEL_H
/*............................................................................*/
typedef struct vsk_Kernel vsk_Kernel;
typedef void (*vsk_KernelOnStart)(void);
#include "vsk_Assert.h"
#include "vsk_CriticalSection.h"
#include "vsk_EventTimerSupervisor.h"
#include "vsk_InboxSupervisor.h"
#include "vsk_Node.h"
#include "vsk_TaskScheduler.h"
#include "vsk_Time.h"
/*............................................................................*/
struct vsk_Kernel {
    vsk_Time * _time;
    vsk_TaskScheduler * _taskScheduler;
    vsk_EventTimerSupervisor * _eventTimerSupervisor;
    vsk_InboxSupervisor * _inboxSupervisor;
    vsk_KernelOnStart _onStart;
};
/*............................................................................*/
vsk_Kernel * vsk_Kernel_(void);
vsk_Kernel * vsk_Kernel_init(
    vsk_Kernel * const self,
    vsk_KernelOnStart const onKernelStart,
    vsk_TaskSchedulerOnIdle const onIdle,
    vsk_CriticalSectionDisableInt const disableInt,
    vsk_CriticalSectionEnableInt const enableInt,
    vsk_AssertOnFail const onAssertFail,
    vsk_Node * const nodes,
    size_t const capacity
);
void vsk_Kernel_informTickPeriodMillis(
    vsk_Kernel * const self,
    uint16_t const tickPeriodMillis
);
void vsk_Kernel_onSysTick(
    vsk_Kernel * const self
);
void vsk_Kernel_start(
    vsk_Kernel * const self
);
#endif // VSK_KERNEL_H
