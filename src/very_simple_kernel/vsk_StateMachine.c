/*............................................................................*/
#include "vsk_StateMachine.h"
/*............................................................................*/
vsk_StateMachine * vsk_StateMachine_init(
    vsk_StateMachine * const self,
    vsk_Task * const task
) {
    self->_task = task;
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
    vsk_State_onEntry(self->_state);
}
/*............................................................................*/
vsk_Task * vsk_StateMachine_getTask(
    vsk_StateMachine * const self
) {
    return self->_task;
}
/*............................................................................*/
vsk_State * vsk_StateMachine_getState(
    vsk_StateMachine * const self
) {
    return self->_state;
}
