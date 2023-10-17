#ifndef VSK_TASK_H
#define VSK_TASK_H
/*............................................................................*/
typedef struct vsk_Task vsk_Task;
typedef void (*vsk_TaskOperation)(void * const param);
#include <stdbool.h>
/*............................................................................*/
struct vsk_Task {
    vsk_TaskOperation _operation;
    void * _param;
    bool _isReady;
};
/*............................................................................*/
vsk_Task * vsk_Task_init(
    vsk_Task * const self,
    vsk_TaskOperation const operation,
    void * const param
);
bool vsk_Task_isReady(
    vsk_Task * const self
);
void vsk_Task_run(
    vsk_Task * const self
);
void vsk_Task_activate(
    vsk_Task * const self
);
#endif // VSK_TASK_H
