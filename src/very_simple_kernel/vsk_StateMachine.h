#ifndef VSK_STATEMACHINE_H
#define VSK_STATEMACHINE_H
/*............................................................................*/
typedef struct vsk_StateMachine vsk_StateMachine;
#include "vsk_State.h"
/*............................................................................*/
struct vsk_StateMachine {
    vsk_State * _state;
};
/*............................................................................*/
vsk_StateMachine * vsk_StateMachine_init(
    vsk_StateMachine * const self
);
void vsk_StateMachine_transition(
    vsk_StateMachine * const self,
    vsk_State * const state
);
#endif // VSK_STATEMACHINE_H
