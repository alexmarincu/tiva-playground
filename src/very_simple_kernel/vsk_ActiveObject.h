#ifndef VSK_ACTIVEOBJECT_H
#define VSK_ACTIVEOBJECT_H
/*............................................................................*/
typedef struct vsk_ActiveObject vsk_ActiveObject;
#include "vsk_EventSubscription.h"
#include "vsk_StateMachine.h"
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_ActiveObject {
    struct {
        vsk_StateMachine stateMachine;
    } _super;
    struct {
        vsk_EventSubscription onStart;
    } _eventSubscriptions;
    vsk_Task _task;
};
/*............................................................................*/
vsk_ActiveObject * vsk_ActiveObject_init(
    vsk_ActiveObject * const self,
    vsk_State * const initialState
);
#endif // VSK_ACTIVEOBJECT_H
