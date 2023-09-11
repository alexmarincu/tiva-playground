#ifndef OS_TASKSTATE_h
#define OS_TASKSTATE_h

typedef enum {
    os_TaskState_READY,
    os_TaskState_WAITING,
    os_TaskState_SUSPENDED,
} os_TaskState;

#endif // OS_TASKSTATE_h
