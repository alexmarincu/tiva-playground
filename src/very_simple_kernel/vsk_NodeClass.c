/*............................................................................*/
#include "vsk_NodeClass.h"
#include "vsk_Assert.h"
#include <stdint.h>
/*............................................................................*/
vsk_NodeClass * vsk_NodeClass_(void) {
    static vsk_NodeClass self;
    return &self;
}
/*............................................................................*/
vsk_NodeClass * vsk_NodeClass_init(
    vsk_NodeClass * const self,
    vsk_Node * const nodes,
    size_t const capacity
) {
    self->_pool.nodes = nodes;
    self->_pool.capacity = capacity;
    self->_pool.firstFree = &nodes[0];
    return self;
}
/*............................................................................*/
vsk_Node * vsk_NodeClass_acquireNode(
    vsk_NodeClass * const self
) {
    vsk_Node * node = NULL;
    vsk_Node * endOfPool =
        (vsk_Node *)((uint8_t *)self->_pool.nodes //
                     + (sizeof(vsk_Node) * self->_pool.capacity));
    if (self->_pool.firstFree < endOfPool) {
        node = self->_pool.firstFree;
        node->_klass = self;
        node->_isUsed = true;
        do {
            self->_pool.firstFree =
                (vsk_Node *)((uint8_t *)self->_pool.firstFree + //
                             sizeof(vsk_Node));
        } while (
            (self->_pool.firstFree->_isUsed == true) //
            && (self->_pool.firstFree < endOfPool)
        );
    }
    vsk_Assert_check(vsk_Assert_(), node);
    return node;
}
