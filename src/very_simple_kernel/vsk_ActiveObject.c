/*............................................................................*/
#include "vsk_ActiveObject.h"
/*............................................................................*/
vsk_ActiveObject * vsk_ActiveObject_init(
    vsk_ActiveObject * const self
) {
    vsk_Task_init(&self->_task);
    vsk_StateMachine_init(&self->_stateMachine, &self->_task);
    return self;
}
