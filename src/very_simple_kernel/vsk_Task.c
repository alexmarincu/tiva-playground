/*............................................................................*/
#include "vsk_Task.h"
#include "vsk_TaskScheduler.h"
/*............................................................................*/
vsk_Task * vsk_Task_init(
    vsk_Task * const self, vsk_TaskOperation const operation, void * const obj
) {
    self->_operation = operation;
    self->_obj = obj;
    self->_isReady = false;
    vsk_TaskScheduler_register(vsk_TaskScheduler_(), self);
    return self;
}
/*............................................................................*/
bool vsk_Task_isReady(vsk_Task * const self) {
    return self->_isReady;
}
/*............................................................................*/
void vsk_Task_run(vsk_Task * const self) {
    self->_operation(self->_obj);
    self->_isReady = false;
}
/*............................................................................*/
void vsk_Task_activate(vsk_Task * const self) {
    self->_isReady = true;
}
