#ifndef OS_TASK_h
#define OS_TASK_h
#include "os_TaskState.h"
#include <stdint.h>

typedef struct os_TaskClass os_TaskClass;
typedef struct os_Task os_Task;
typedef void (*os_Task_operationFun)(os_Task * const self);
struct os_Task {
    os_TaskClass const * klass;
    os_Task_operationFun operation;
    os_TaskState state;
    uint32_t lastRunTimeMillis;
    uint32_t delayMillis;
};

os_TaskClass * os_TaskClass_(void);
os_TaskClass * os_TaskClass_init(os_TaskClass * const self);
os_Task * os_Task_init(os_Task * const self, os_Task_operationFun const operation);
os_TaskState os_Task_getState(os_Task * const self);
void os_Task_processReady(os_Task * const self);
void os_Task_processWaiting(os_Task * const self);
void os_Task_delayFromLastRun(os_Task * const self, uint32_t const delayMillis);
void os_Task_delay(os_Task * const self, uint32_t const delayMillis);
void os_Task_suspend(os_Task * const self);
void os_Task_resume(os_Task * const self);

#endif // OS_TASK_h
