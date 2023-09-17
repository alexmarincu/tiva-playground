#ifndef VSK_EVENTTIMERMANAGER_H
#define VSK_EVENTTIMERMANAGER_H
#include "vsk_EventTimer.h"
#include <stdint.h>

typedef struct vsk_EventTimerManager vsk_EventTimerManager;
struct vsk_EventTimerManager {
    vsk_EventTimer * eventTimerHead;
};

vsk_EventTimerManager * vsk_EventTimerManager_(void);
vsk_EventTimerManager * vsk_EventTimerManager_init(vsk_EventTimerManager * const self);
void vsk_EventTimerManager_register(vsk_EventTimerManager * const self, vsk_EventTimer * const eventTimer);
void vsk_EventTimerManager_onSysTick(vsk_EventTimerManager * const self);

#endif // VSK_EVENTTIMERMANAGER_H
