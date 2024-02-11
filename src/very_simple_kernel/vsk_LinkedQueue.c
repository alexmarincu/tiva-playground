/*----------------------------------------------------------------------------*/
#include "vsk_LinkedQueue.h"
/*----------------------------------------------------------------------------*/
vsk_LinkedQueue * vsk_LinkedQueue_init(vsk_LinkedQueue * const self) {
    vsk_LinkedList_init(&self->_linkedList);
    return self;
}
/*----------------------------------------------------------------------------*/
bool vsk_LinkedQueue_isEmpty(vsk_LinkedQueue * const self) {
    return vsk_LinkedList_isEmpty(&self->_linkedList);
}
/*----------------------------------------------------------------------------*/
void vsk_LinkedQueue_enqueue(vsk_LinkedQueue * const self, void * const obj) {
    vsk_LinkedList_addLast(&self->_linkedList, obj);
}
/*----------------------------------------------------------------------------*/
void * vsk_LinkedQueue_dequeue(vsk_LinkedQueue * const self) {
    return vsk_LinkedList_removeFirst(&self->_linkedList);
}
/*----------------------------------------------------------------------------*/
void vsk_LinkedQueue_clear(vsk_LinkedQueue * const self) {
    vsk_LinkedList_clear(&self->_linkedList);
}
