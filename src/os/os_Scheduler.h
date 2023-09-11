#ifndef OS_SCHEDULER_h
#define OS_SCHEDULER_h
#include "os_Task.h"

typedef struct os_Scheduler os_Scheduler;

os_Scheduler * os_Scheduler_(void);
os_Scheduler * os_Scheduler_init(os_Scheduler * const self, os_Task * const tasks, uint8_t const taskCount);
void os_Scheduler_main(os_Scheduler * const self);

#endif // OS_SCHEDULER_h
