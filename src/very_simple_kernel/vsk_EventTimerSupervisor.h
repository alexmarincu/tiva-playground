#ifndef VSK_EVENTTIMERSUPERVISOR_H
#define VSK_EVENTTIMERSUPERVISOR_H
/*............................................................................*/
typedef struct vsk_EventTimerSupervisor vsk_EventTimerSupervisor;
#include "vsk_EventTimer.h"
/*............................................................................*/
struct vsk_EventTimerSupervisor {
    vsk_LinkedList _eventTimers;
};
/*............................................................................*/
vsk_EventTimerSupervisor * vsk_EventTimerSupervisor_(void);
vsk_EventTimerSupervisor * vsk_EventTimerSupervisor_init(
    vsk_EventTimerSupervisor * const self
);
void vsk_EventTimerSupervisor_register(
    vsk_EventTimerSupervisor * const self,
    vsk_EventTimer * const eventTimer
);
void vsk_EventTimerSupervisor_onSysTick(
    vsk_EventTimerSupervisor * const self
);
#endif // VSK_EVENTTIMERSUPERVISOR_H
