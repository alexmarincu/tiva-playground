#ifndef VSK_TIMER_H
#define VSK_TIMER_H
/*............................................................................*/
typedef struct vsk_Timer vsk_Timer;
typedef void (*vsk_TimerCallback)(vsk_Timer * const self);
#include "vsk_TimerSupervisor.h"
#include <stdint.h>
/*............................................................................*/
struct vsk_Timer {
    vsk_TimerCallback _callback;
    uint32_t _delayMillis;
    uint32_t _periodMillis;
};
/*............................................................................*/
vsk_Timer * vsk_Timer_init(
    vsk_Timer * const self,
    vsk_TimerCallback const callback
);
void vsk_Timer_arm(
    vsk_Timer * const self,
    uint32_t const delayMillis,
    uint32_t const periodMillis
);
void vsk_Timer_disarm(
    vsk_Timer * const self
);
void vsk_Timer_onSysTick(
    vsk_Timer * const self
);
#endif // VSK_TIMER_H
