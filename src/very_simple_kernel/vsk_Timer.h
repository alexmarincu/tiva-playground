#ifndef VSK_TIMER_H
#define VSK_TIMER_H
/*............................................................................*/
typedef struct vsk_Timer vsk_Timer;
typedef void (*vsk_TimerCallback)(void * const obj);
#include "vsk_TimerSupervisor.h"
#include <stdint.h>
/*............................................................................*/
struct vsk_Timer {
    uint32_t _delayMillis;
    uint32_t _periodMillis;
    vsk_TimerCallback _callback;
    void * _obj;
    uint32_t _millisCount;
};
/*............................................................................*/
vsk_Timer * vsk_Timer_init(
    vsk_Timer * const self,
    uint32_t const delayMillis,
    uint32_t const periodMillis,
    vsk_TimerCallback const callback,
    void * const obj
);
void vsk_Timer_start(vsk_Timer * const self);
void vsk_Timer_stop(vsk_Timer * const self);
void vsk_Timer_onSysTick(vsk_Timer * const self);
#endif // VSK_TIMER_H
