/*............................................................................*/
#include "ut_Queue.h"
/*............................................................................*/
ut_Queue * ut_Queue_init(
    ut_Queue * const self,
    ut_Array * const array
) {
    self->_array = array;
    self->_front = -1;
    self->_rear = -1;
    return self;
}
/*............................................................................*/
bool ut_Queue_isEmpty(
    ut_Queue * const self
) {
    return ((self->_front == -1) && (self->_rear == -1));
}
/*............................................................................*/
bool ut_Queue_isFull(
    ut_Queue * const self
) {
    return (((self->_rear + 1) % ut_Array_length(self->_array)) == self->_front);
}
/*............................................................................*/
void ut_Queue_enqueue(
    ut_Queue * const self,
    void * const item
) {
    if (ut_Queue_isFull(self) == false) {
        if (ut_Queue_isEmpty(self) == true) {
            self->_front = 0;
        }
        self->_rear = (self->_rear + 1) % ut_Array_length(self->_array);
        ut_Array_insert(self->_array, item, self->_rear);
    }
}
/*............................................................................*/
void * ut_Queue_dequeue(
    ut_Queue * const self
) {
    void * item = NULL;
    if (ut_Queue_isEmpty(self) == false) {
        item = ut_Array_remove(self->_array, self->_front);
        if (self->_front == self->_rear) {
            self->_front = -1;
            self->_rear = -1;
        } else {
            self->_front = (self->_front + 1) % ut_Array_length(self->_array);
        }
    }
    return item;
}
/*............................................................................*/
void ut_Queue_clear(
    ut_Queue * const self
) {
    ut_Array_clear(self->_array);
    self->_front = -1;
    self->_rear = -1;
}
