#ifndef VSK_TASK_H
#define VSK_TASK_H
/*............................................................................*/
typedef struct vsk_Task vsk_Task;
#include "vsk_Message.h"
#include "vsk_Queue.h"
/*............................................................................*/
struct vsk_Task {
    vsk_Queue messageQueue;
};
/*............................................................................*/
vsk_Task * vsk_Task_init(
    vsk_Task * const self
);
bool vsk_Task_isReady(
    vsk_Task * const self
);
void vsk_Task_run(
    vsk_Task * const self
);
void vsk_Task_postMessage(
    vsk_Task * const self,
    vsk_Message * const message
);

#endif // VSK_TASK_H
