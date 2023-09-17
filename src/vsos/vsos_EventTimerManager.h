#ifndef VSOS_EVENTTIMERMANAGER_H
#define VSOS_EVENTTIMERMANAGER_H
#include "vsos_EventTimer.h"
#include <stdint.h>

typedef struct vsos_EventTimerManager vsos_EventTimerManager;
struct vsos_EventTimerManager {
    vsos_EventTimer * eventTimerHead;
};

vsos_EventTimerManager * vsos_EventTimerManager_(void);
vsos_EventTimerManager * vsos_EventTimerManager_init(vsos_EventTimerManager * const self);
void vsos_EventTimerManager_register(vsos_EventTimerManager * const self, vsos_EventTimer * const eventTimer);
void vsos_EventTimerManager_onSysTick(vsos_EventTimerManager * const self);

#endif // VSOS_EVENTTIMERMANAGER_H
