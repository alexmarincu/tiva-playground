#ifndef VSOS_TASK_H
#define VSOS_TASK_H
#include "../utils/utils_Queue.h"
#include "vsos_Event.h"
#include <stdint.h>

typedef struct vsos_Task vsos_Task;
typedef void (*vsos_Task_operationFun)(vsos_Task * const self, vsos_Event * const event);
struct vsos_Task {
    vsos_Task_operationFun operation;
    utils_Queue * eventQueue;
};

vsos_Task * vsos_Task_init(
    vsos_Task * const self,
    vsos_Task_operationFun const operation,
    utils_Queue * const eventQueue
);
bool vsos_Task_isReady(vsos_Task * const self);
void vsos_Task_operation(vsos_Task * const self);
void vsos_Task_postEvent(vsos_Task * const self, vsos_Event * const event);

#endif // VSOS_TASK_H
