#ifndef VSK_STATE_H
#define VSK_STATE_H
/*............................................................................*/
typedef struct vsk_State vsk_State;
typedef void (*vsk_StateOnEnter)(
    vsk_State * const self
);
typedef void (*vsk_StateExit)(
    vsk_State * const self
);
#include "vsk_StateMachine.h"
#include <stdbool.h>
/*............................................................................*/
struct vsk_State {
    vsk_StateMachine * _stateMachine;
    vsk_StateOnEnter _onEnter;
    vsk_StateExit _onExit;
};
/*............................................................................*/
vsk_State * vsk_State_init(
    vsk_State * const self,
    vsk_StateMachine * const stateMachine
);
void vsk_State_onEnter(
    vsk_State * const self
);
void vsk_State_onExit(
    vsk_State * const self
);
#endif // VSK_STATE_H
