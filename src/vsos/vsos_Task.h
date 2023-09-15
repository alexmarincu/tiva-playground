#ifndef VSOS_TASK_H
#define VSOS_TASK_H
#include "vsos_TaskState.h"
#include <stdint.h>

typedef struct vsos_TaskClass vsos_TaskClass;
typedef struct vsos_Task vsos_Task;
typedef void (*vsos_Task_operationFun)(vsos_Task * const self);
struct vsos_Task {
    vsos_TaskClass const * klass;
    vsos_Task_operationFun operation;
    vsos_TaskState state;
    uint32_t lastRunTimeMillis;
    uint32_t delayMillis;
};

vsos_TaskClass * vsos_TaskClass_(void);
vsos_TaskClass * vsos_TaskClass_init(vsos_TaskClass * const self);
vsos_Task * vsos_Task_init(vsos_Task * const self, vsos_Task_operationFun const operation);
vsos_TaskState vsos_Task_getState(vsos_Task * const self);
void vsos_Task_processReady(vsos_Task * const self);
void vsos_Task_processWaiting(vsos_Task * const self);
void vsos_Task_delayFromLastRun(vsos_Task * const self, uint32_t const delayMillis);
void vsos_Task_delay(vsos_Task * const self, uint32_t const delayMillis);
void vsos_Task_suspend(vsos_Task * const self);
void vsos_Task_resume(vsos_Task * const self);

#endif // VSOS_TASK_H
