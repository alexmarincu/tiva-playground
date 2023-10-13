/*............................................................................*/
#include "vsk_StateMachine.h"
#include <stddef.h>
/*............................................................................*/
vsk_StateMachine * vsk_StateMachine_init(
    vsk_StateMachine * const self
) {
    self->_state = NULL;
    return self;
}
/*............................................................................*/
void vsk_StateMachine_transition(
    vsk_StateMachine * const self,
    vsk_State * const state
) {
    if (self->_state != NULL) {
        vsk_State_onExit(self->_state);
    }
    self->_state = state;
    vsk_State_onEnter(self->_state);
}
