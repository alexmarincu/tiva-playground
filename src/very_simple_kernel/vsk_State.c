/*............................................................................*/
#include "vsk_State.h"
/*............................................................................*/
vsk_State * vsk_State_init(
    vsk_State * const self,
    vsk_StateMachine * const stateMachine,
    vsk_StateOnEntry const onEntry,
    vsk_StateOnExit const onExit
) {
    self->_stateMachine = stateMachine;
    self->_onEntry = onEntry;
    self->_onExit = onExit;
    return self;
}
/*............................................................................*/
void vsk_State_onEntry(
    vsk_State * const self
) {
    self->_onEntry(self);
}
/*............................................................................*/
void vsk_State_onExit(
    vsk_State * const self
) {
    self->_onExit(self);
}
