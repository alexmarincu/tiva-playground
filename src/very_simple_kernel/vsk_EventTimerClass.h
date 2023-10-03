#ifndef VSK_EVENTTIMERCLASS_H
#define VSK_EVENTTIMERCLASS_H
/*............................................................................*/
typedef struct vsk_EventTimerClass vsk_EventTimerClass;
#include "vsk_EventTimer.h"
/*............................................................................*/
struct vsk_EventTimerClass {
    vsk_EventTimer * _eventTimerHead;
};
/*............................................................................*/
vsk_EventTimerClass * vsk_EventTimerClass_(void);
vsk_EventTimerClass * vsk_EventTimerClass_init(
    vsk_EventTimerClass * const self
);
void vsk_EventTimerClass_register(
    vsk_EventTimerClass * const self,
    vsk_EventTimer * const eventTimer
);
void vsk_EventTimerClass_onSysTick(
    vsk_EventTimerClass * const self
);
#endif // VSK_EVENTTIMERCLASS_H
