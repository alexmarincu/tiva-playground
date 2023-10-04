#ifndef VSK_STATE_H
#define VSK_STATE_H
/*............................................................................*/
typedef struct vsk_State vsk_State;
typedef void (*vsk_StateOnEntry)(
    vsk_State * const self
);
typedef void (*vsk_StateOnExit)(
    vsk_State * const self
);
#include "vsk_StateMachine.h"
#include <stdbool.h>
/*............................................................................*/
struct vsk_State {
    vsk_StateMachine * _stateMachine;
    vsk_StateOnEntry _onEntry;
    vsk_StateOnExit _onExit;
};
/*............................................................................*/
vsk_State * vsk_State_init(
    vsk_State * const self,
    vsk_StateMachine * const stateMachine,
    vsk_StateOnEntry const onEntry,
    vsk_StateOnExit const onExit
);
void vsk_State_onEntry(
    vsk_State * const self
);
void vsk_State_onExit(
    vsk_State * const self
);
bool vsk_State_isActive(
    vsk_State * const self
);
#endif // VSK_STATE_H
