#ifndef VSK_KERNEL_H
#define VSK_KERNEL_H
#include "vsk_SysTime.h"
#include "vsk_TaskScheduler.h"

typedef struct vsk_Kernel vsk_Kernel;
typedef void (*vsk_Kernel_onStartFun)(void);

vsk_Kernel * vsk_Kernel_(void);
vsk_Kernel * vsk_Kernel_init(
    vsk_Kernel * const self,
    vsk_Kernel_onStartFun const onStart,
    vsk_TaskScheduler_onIdleFun const onIdle,
    utl_Array * const taskArray
);

void vsk_Kernel_informTickPeriodMillis(vsk_Kernel * const self, uint16_t const tickPeriodMillis);
void vsk_Kernel_onSysTick(vsk_Kernel * const self);
void vsk_Kernel_start(vsk_Kernel * const self);

#endif // VSK_KERNEL_H
