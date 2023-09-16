#include "vsos_Task.h"
#include "vsos_SysTime.h"

struct vsos_TaskClass {
    vsos_SysTime * sysTime;
};

vsos_TaskClass * vsos_TaskClass_(void) {
    static vsos_TaskClass self;
    return &self;
}

vsos_TaskClass * vsos_TaskClass_init(vsos_TaskClass * const self) {
    self->sysTime = vsos_SysTime_();
    return self;
}

vsos_Task * vsos_Task_init(
    vsos_Task * const self,
    vsos_Task_operationFun const operation,
    utils_Queue * const eventQueue
) {
    self->klass = vsos_TaskClass_();
    self->operation = operation;
    self->eventQueue = eventQueue;
    self->state = vsos_TaskState_READY;
    self->lastRunTimeMillis = 0;
    self->delayMillis = 0;
    return self;
}

vsos_TaskState vsos_Task_getState(vsos_Task * const self) {
    return self->state;
}

void vsos_Task_processReady(vsos_Task * const self) {
    self->lastRunTimeMillis = vsos_SysTime_getMillisCount(self->klass->sysTime);
    self->operation(self);
}

void vsos_Task_processWaiting(vsos_Task * const self) {
    uint32_t const elapsedTimeMillis = vsos_SysTime_getMillisCount(self->klass->sysTime) - self->lastRunTimeMillis;
    if (elapsedTimeMillis >= self->delayMillis) {
        self->state = vsos_TaskState_READY;
    }
}

void vsos_Task_delay(vsos_Task * const self, uint32_t const delayMillis) {
    self->state = vsos_TaskState_WAITING;
    self->delayMillis = delayMillis;
}

void vsos_Task_delayFromLastRun(vsos_Task * const self, uint32_t const delayMillis) {
    vsos_Task_delay(self, self->lastRunTimeMillis + delayMillis - vsos_SysTime_getMillisCount(self->klass->sysTime));
}

void vsos_Task_suspend(vsos_Task * const self) {
    self->state = vsos_TaskState_SUSPENDED;
}

void vsos_Task_resume(vsos_Task * const self) {
    self->state = vsos_TaskState_READY;
}

void vsos_Task_post(vsos_Task * const self, vsos_Event * const event) {
    utils_Queue_enqueue(self->eventQueue, event);
}
