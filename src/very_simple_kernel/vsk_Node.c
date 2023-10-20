/*............................................................................*/
#include "vsk_Node.h"
#include "vsk_CriticalSection.h"
/*............................................................................*/
vsk_Node * vsk_Node_init(vsk_Node * const self, void * const item) {
    self->item = item;
    self->next = NULL;
    self->prev = NULL;
    return self;
}
/*............................................................................*/
vsk_Node * vsk_Node_release(vsk_Node * const self) {
    self->_isUsed = false;
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    if (self < self->_klass->_pool.firstFree) {
        self->_klass->_pool.firstFree = self;
    }
    vsk_CriticalSection_exit(vsk_CriticalSection_());
    return NULL;
}
