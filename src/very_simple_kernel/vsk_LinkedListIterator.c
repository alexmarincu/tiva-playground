/*............................................................................*/
#include "vsk_LinkedListIterator.h"
#include "vsk_Assert.h"
/*............................................................................*/
vsk_LinkedListIterator * vsk_LinkedListIterator_init(
    vsk_LinkedListIterator * const self,
    vsk_LinkedList * const linkedList
) {
    self->_linkedList = linkedList;
    self->_current = linkedList->_first;
    return self;
}
/*............................................................................*/
bool vsk_LinkedListIterator_hasNext(
    vsk_LinkedListIterator * const self
) {
    return (self->_current != NULL);
}
/*............................................................................*/
bool vsk_LinkedListIterator_hasPrevious(
    vsk_LinkedListIterator * const self
) {
    // TODO
    return false;
}
/*............................................................................*/
void * vsk_LinkedListIterator_next(
    vsk_LinkedListIterator * const self
) {
    void * item = NULL;
    if (vsk_LinkedListIterator_hasNext(self)) {
        item = self->_current->item;
        self->_current = self->_current->next;
    }
    return item;
}
/*............................................................................*/
void * vsk_LinkedListIterator_previous(
    vsk_LinkedListIterator * const self
);
/*............................................................................*/
void vsk_LinkedListIterator_forEach(
    vsk_LinkedListIterator * const self,
    vsk_LinkedListIteratorForEachOperation const operation
) {
    vsk_Assert_check(vsk_Assert_(), operation);
    void * item;
    while ((item = vsk_LinkedListIterator_next(self))) {
        operation(item);
    }
}
