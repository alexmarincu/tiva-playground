#ifndef VSOS_SYSTIME_H
#define VSOS_SYSTIME_H
#include <stdint.h>

typedef struct vsos_SysTime vsos_SysTime;

vsos_SysTime * vsos_SysTime_(void);
vsos_SysTime * vsos_SysTime_init(vsos_SysTime * const self, uint16_t const tickPeriodMillis);
uint32_t vsos_SysTime_getMillisCount(vsos_SysTime * const self);
uint32_t vsos_SysTime_getOpTimeSeconds(vsos_SysTime * const self);
void vsos_SysTime_onSysTick(vsos_SysTime * const self);

#endif // VSOS_SYSTIME_H
