/*............................................................................*/
#include "vsk_ActiveObject.h"
/*............................................................................*/
vsk_ActiveObject * vsk_ActiveObject_init(
    vsk_ActiveObject * const self
) {
    vsk_Task_init(&self->_task);
    return self;
}
/*............................................................................*/
vsk_Task * vsk_ActiveObject_getTask(
    vsk_ActiveObject * const self
) {
    return &self->_task;
}
