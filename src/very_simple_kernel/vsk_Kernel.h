#ifndef VSK_KERNEL_H
#define VSK_KERNEL_H
#include "vsk_TaskScheduler.h"
#include "vsk_Time.h"

typedef struct vsk_Kernel vsk_Kernel;
typedef void (*vsk_KernelOnStart)(void);

vsk_Kernel * vsk_Kernel_(void);
vsk_Kernel * vsk_Kernel_init(
    vsk_Kernel * const self,
    vsk_KernelOnStart const onStart,
    vsk_TaskSchedulerOnIdle const onIdle,
    ut_Array * const taskArray
);

void vsk_Kernel_informTickPeriodMillis(vsk_Kernel * const self, uint16_t const tickPeriodMillis);
void vsk_Kernel_onSysTick(vsk_Kernel * const self);
void vsk_Kernel_start(vsk_Kernel * const self);

#endif // VSK_KERNEL_H
