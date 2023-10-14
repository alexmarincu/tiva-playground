#ifndef VSK_TASK_H
#define VSK_TASK_H
/*............................................................................*/
typedef struct vsk_Task vsk_Task;
#include "vsk_Inbox.h"
#include "vsk_Message.h"
/*............................................................................*/
struct vsk_Task {
    vsk_Inbox inbox;
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
#endif // VSK_TASK_H
