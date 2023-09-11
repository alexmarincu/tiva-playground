#ifndef OS_SYSTIME_h
#define OS_SYSTIME_h
#include <stdint.h>

typedef struct os_SysTime os_SysTime;

os_SysTime * os_SysTime_(void);
os_SysTime * os_SysTime_init(os_SysTime * const self);
uint32_t os_SysTime_getMillisTickCount(os_SysTime * const self);
uint32_t os_SysTime_getOpTimeSeconds(os_SysTime * const self);

#endif // OS_SYSTIME_h
