#ifndef VSK_STATEMACHINE_H
#define VSK_STATEMACHINE_H
/*............................................................................*/
typedef struct vsk_StateMachine vsk_StateMachine;
#include "vsk_State.h"
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_StateMachine {
    vsk_Task * _task;
    vsk_State * _state;
};
/*............................................................................*/
vsk_StateMachine * vsk_StateMachine_init(
    vsk_StateMachine * const self,
    vsk_Task * const task
);
void vsk_StateMachine_transition(
    vsk_StateMachine * const self,
    vsk_State * const state
);
vsk_Task * vsk_StateMachine_getTask(
    vsk_StateMachine * const self
);
vsk_State * vsk_StateMachine_getState(
    vsk_StateMachine * const self
);
#endif // VSK_STATEMACHINE_H
