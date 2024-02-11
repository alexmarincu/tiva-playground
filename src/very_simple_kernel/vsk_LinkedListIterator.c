/*----------------------------------------------------------------------------*/
#include "vsk_LinkedListIterator.h"
/*----------------------------------------------------------------------------*/
vsk_LinkedListIterator * vsk_LinkedListIterator_init(
    vsk_LinkedListIterator * const self, vsk_LinkedList * const linkedList
) {
    self->_linkedList = linkedList;
    self->_current = linkedList->_first;
    return self;
}
/*----------------------------------------------------------------------------*/
bool vsk_LinkedListIterator_hasNext(vsk_LinkedListIterator * const self) {
    return (self->_current != NULL);
}
/*----------------------------------------------------------------------------*/
bool vsk_LinkedListIterator_hasPrevious(vsk_LinkedListIterator * const self) {
    // TODO
    return false;
}
/*----------------------------------------------------------------------------*/
void * vsk_LinkedListIterator_next(vsk_LinkedListIterator * const self) {
    void * obj = NULL;
    if (vsk_LinkedListIterator_hasNext(self)) {
        obj = self->_current->obj;
        self->_current = self->_current->next;
    }
    return obj;
}
/*----------------------------------------------------------------------------*/
void * vsk_LinkedListIterator_previous(vsk_LinkedListIterator * const self) {
    // TODO
    return NULL;
}
/*----------------------------------------------------------------------------*/
void vsk_LinkedListIterator_forEach(
    vsk_LinkedListIterator * const self,
    vsk_LinkedListIteratorForEachOperation const operation
) {
    void * obj;
    while ((obj = vsk_LinkedListIterator_next(self))) {
        operation(obj);
    }
}
/*----------------------------------------------------------------------------*/
void * vsk_LinkedListIterator_find(
    vsk_LinkedListIterator * const self,
    vsk_LinkedListIteratorFindPredicate const predicate
) {
    bool objFound = false;
    void * obj;
    while (vsk_LinkedListIterator_hasNext(self) && !objFound) {
        obj = vsk_LinkedListIterator_next(self);
        if (predicate(obj)) {
            objFound = true;
        }
    }
    if (!objFound) {
        obj = NULL;
    }
    return obj;
}
