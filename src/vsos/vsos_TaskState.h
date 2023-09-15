#ifndef VSOS_TASKSTATE_H
#define VSOS_TASKSTATE_H

typedef enum {
    vsos_TaskState_READY,
    vsos_TaskState_WAITING,
    vsos_TaskState_SUSPENDED,
} vsos_TaskState;

#endif // VSOS_TASKSTATE_H
