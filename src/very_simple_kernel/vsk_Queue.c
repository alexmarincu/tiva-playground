/*............................................................................*/
#include "vsk_Queue.h"
/*............................................................................*/
vsk_Queue * vsk_Queue_init(vsk_Queue * const self) {
    vsk_LinkedList_init(&self->_linkedList);
    return self;
}
/*............................................................................*/
bool vsk_Queue_isEmpty(vsk_Queue * const self) {
    return vsk_LinkedList_isEmpty(&self->_linkedList);
}
/*............................................................................*/
void vsk_Queue_enqueue(vsk_Queue * const self, void * const obj) {
    vsk_LinkedList_addLast(&self->_linkedList, obj);
}
/*............................................................................*/
void * vsk_Queue_dequeue(vsk_Queue * const self) {
    return vsk_LinkedList_removeFirst(&self->_linkedList);
}
/*............................................................................*/
void vsk_Queue_clear(vsk_Queue * const self) {
    vsk_LinkedList_clear(&self->_linkedList);
}
