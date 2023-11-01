/*............................................................................*/
#include "vsk_NodeClass.h"
/*............................................................................*/
#include <stdint.h>
/*............................................................................*/
#include "vsk_Assert.h"
#include "vsk_CriticalSection.h"
/*............................................................................*/
vsk_NodeClass * vsk_NodeClass_(void) {
    static vsk_NodeClass self;
    return &self;
}
/*............................................................................*/
vsk_NodeClass * vsk_NodeClass_init(
    vsk_NodeClass * const self, vsk_Node * const nodes, size_t const capacity
) {
    self->_pool.nodes = nodes;
    self->_pool.capacity = capacity;
    self->_pool.firstFree = &nodes[0];
    for (size_t i = 0; i < self->_pool.capacity; i++) {
        self->_pool.nodes[i] = (vsk_Node){ 0 };
    }
    return self;
}
/*............................................................................*/
vsk_Node * vsk_NodeClass_acquireNode(vsk_NodeClass * const self) {
    vsk_Node * node = NULL;
    vsk_Node * const endOfPool = &self->_pool.nodes[self->_pool.capacity];
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    if (self->_pool.firstFree < endOfPool) {
        node = self->_pool.firstFree;
        node->_klass = self;
        do {
            self->_pool.firstFree++;
        } while (
            (self->_pool.firstFree < endOfPool) //
            && (self->_pool.firstFree->_klass)
        );
    }
    vsk_CriticalSection_exit(vsk_CriticalSection_());
    vsk_Assert_true(vsk_Assert_(), node);
    return node;
}
