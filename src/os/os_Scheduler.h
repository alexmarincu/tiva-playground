#ifndef OS_SCHEDULER_h
#define OS_SCHEDULER_h
#include "os_Task.h"

void os_Scheduler_setTasks(os_Task * const tasks, uint8_t const count);
void os_Scheduler_main(void);

#endif // OS_SCHEDULER_h
