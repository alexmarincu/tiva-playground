#ifndef VSK_SYSTIME_H
#define VSK_SYSTIME_H
#include <stdint.h>

typedef struct vsk_SysTime vsk_SysTime;

vsk_SysTime * vsk_SysTime_(void);
vsk_SysTime * vsk_SysTime_init(vsk_SysTime * const self);
uint32_t vsk_SysTime_getMillisCount(vsk_SysTime * const self);
uint32_t vsk_SysTime_getOpTimeSeconds(vsk_SysTime * const self);
uint16_t vsk_SysTime_getTickPeriodMillis(vsk_SysTime * const self);
void vsk_SysTime_informTickPeriodMillis(vsk_SysTime * const self, uint16_t const tickPeriodMillis);
void vsk_SysTime_onSysTick(vsk_SysTime * const self);

#endif // VSK_SYSTIME_H
