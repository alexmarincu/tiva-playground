#ifndef VSK_ACTIVEOBJECT_H
#define VSK_ACTIVEOBJECT_H
/*............................................................................*/
typedef struct vsk_ActiveObject vsk_ActiveObject;
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_ActiveObject {
    vsk_Task _task;
};
/*............................................................................*/
vsk_ActiveObject * vsk_ActiveObject_init(
    vsk_ActiveObject * const self
);
vsk_Task * vsk_ActiveObject_getTask(
    vsk_ActiveObject * const self
);
#endif // VSK_ACTIVEOBJECT_H
