#ifndef OS_OS_h
#define OS_OS_h
#include "os_Scheduler.h"
#include "os_SysTime.h"

typedef struct os_Os os_Os;

os_Os * os_Os_(void);
os_Os * os_Os_init(os_Os * const self, os_Task ** const tasks, uint8_t const taskCount);
void os_Os_main(os_Os * const self);

#endif // OS_OS_h
