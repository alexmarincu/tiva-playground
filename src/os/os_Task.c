#include "os_Task.h"
#include "os_SysTime.h"

struct os_TaskClass {
    os_SysTime * sysTime;
};

os_TaskClass * os_TaskClass_(void) {
    static os_TaskClass self;
    return &self;
}

os_TaskClass * os_TaskClass_init(os_TaskClass * const self) {
    self->sysTime = os_SysTime_();
    return self;
}

os_Task * os_Task_init(os_Task * const self, os_Task_operationFun const operation) {
    self->klass = os_TaskClass_();
    self->operation = operation;
    self->state = os_TaskState_READY;
    self->lastRunTimeMillis = 0;
    self->delayMillis = 0;
    return self;
}

os_TaskState os_Task_getState(os_Task * const self) {
    return self->state;
}

void os_Task_processReady(os_Task * const self) {
    self->lastRunTimeMillis = os_SysTime_getMillisTickCount(self->klass->sysTime);
    self->operation(self);
}

void os_Task_processWaiting(os_Task * const self) {
    uint32_t const elapsedTimeMillis = os_SysTime_getMillisTickCount(self->klass->sysTime) - self->lastRunTimeMillis;
    if (elapsedTimeMillis >= self->delayMillis) {
        self->state = os_TaskState_READY;
    }
}

void os_Task_delay(os_Task * const self, uint32_t const delayMillis) {
    self->state = os_TaskState_WAITING;
    self->delayMillis = delayMillis;
}

void os_Task_delayFromLastRun(os_Task * const self, uint32_t const delayMillis) {
    os_Task_delay(self, self->lastRunTimeMillis + delayMillis - os_SysTime_getMillisTickCount(self->klass->sysTime));
}

void os_Task_suspend(os_Task * const self) {
    self->state = os_TaskState_SUSPENDED;
}

void os_Task_resume(os_Task * const self) {
    self->state = os_TaskState_READY;
}
