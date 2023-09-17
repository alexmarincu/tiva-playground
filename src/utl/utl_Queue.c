#include "utl_Queue.h"

utl_Queue * utl_Queue_init(
    utl_Queue * const self,
    utl_Array * const array
) {
    self->array = array;
    self->front = -1;
    self->rear = -1;
    return self;
}

bool utl_Queue_isEmpty(utl_Queue * const self) {
    return ((self->front == -1) && (self->rear == -1));
}

bool utl_Queue_isFull(utl_Queue * const self) {
    return (((self->rear + 1) % utl_Array_length(self->array)) == self->front);
}

void utl_Queue_enqueue(utl_Queue * const self, void * const item) {
    if (utl_Queue_isFull(self) == false) {
        if (utl_Queue_isEmpty(self) == true) {
            self->front = 0;
        }
        self->rear = (self->rear + 1) % utl_Array_length(self->array);
        utl_Array_insert(self->array, item, self->rear);
    }
}

void * utl_Queue_dequeue(utl_Queue * const self) {
    void * item = 0;
    if (utl_Queue_isEmpty(self) == false) {
        item = utl_Array_remove(self->array, self->front);
        if (self->front == self->rear) {
            self->front = -1;
            self->rear = -1;
        } else {
            self->front = (self->front + 1) % utl_Array_length(self->array);
        }
    }
    return item;
}

void utl_Queue_clear(utl_Queue * const self) {
    utl_Array_clear(self->array);
    self->front = -1;
    self->rear = -1;
}
