#ifndef OS_OS_h
#define OS_OS_h
#include "os_SysTime.h"

typedef struct {
    os_SysTime * sysTime;
} os_Os;

os_Os * os_Os_ref(void);
os_Os * os_Os_init(os_Os * const self);
void os_Os_main(os_Os * const self);

#endif // OS_OS_h
