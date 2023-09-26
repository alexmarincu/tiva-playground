#include "ut_Queue.h"

ut_Queue * ut_Queue_init(
    ut_Queue * const self,
    ut_Array * const array
) {
    self->array = array;
    self->front = -1;
    self->rear = -1;
    return self;
}

bool ut_Queue_isEmpty(ut_Queue * const self) {
    return ((self->front == -1) && (self->rear == -1));
}

bool ut_Queue_isFull(ut_Queue * const self) {
    return (((self->rear + 1) % ut_Array_length(self->array)) == self->front);
}

void ut_Queue_enqueue(ut_Queue * const self, void * const item) {
    if (ut_Queue_isFull(self) == false) {
        if (ut_Queue_isEmpty(self) == true) {
            self->front = 0;
        }
        self->rear = (self->rear + 1) % ut_Array_length(self->array);
        ut_Array_insert(self->array, item, self->rear);
    }
}

void * ut_Queue_dequeue(ut_Queue * const self) {
    void * item = 0;
    if (ut_Queue_isEmpty(self) == false) {
        item = ut_Array_remove(self->array, self->front);
        if (self->front == self->rear) {
            self->front = -1;
            self->rear = -1;
        } else {
            self->front = (self->front + 1) % ut_Array_length(self->array);
        }
    }
    return item;
}

void ut_Queue_clear(ut_Queue * const self) {
    ut_Array_clear(self->array);
    self->front = -1;
    self->rear = -1;
}
