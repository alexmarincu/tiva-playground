#include "utils_Queue.h"

utils_Queue * utils_Queue_init(
    utils_Queue * const self,
    utils_Array * const array
) {
    self->array = array;
    self->front = -1;
    self->rear = -1;
    return self;
}

bool utils_Queue_isEmpty(utils_Queue * const self) {
    return ((self->front == -1) && (self->rear == -1));
}

bool utils_Queue_isFull(utils_Queue * const self) {
    return (((self->rear + 1) % utils_Array_length(self->array)) == self->front);
}

void utils_Queue_enqueue(utils_Queue * const self, void * const item) {
    if (utils_Queue_isFull(self) == false) {
        if (utils_Queue_isEmpty(self) == true) {
            self->front = 0;
        }
        self->rear = (self->rear + 1) % utils_Array_length(self->array);
        utils_Array_insert(self->array, item, self->rear);
    }
}

void * utils_Queue_dequeue(utils_Queue * const self) {
    void * item = 0;
    if (utils_Queue_isEmpty(self) == false) {
        item = utils_Array_remove(self->array, self->front);
        if (self->front == self->rear) {
            self->front = -1;
            self->rear = -1;
        } else {
            self->front = (self->front + 1) % utils_Array_length(self->array);
        }
    }
    return item;
}

void utils_Queue_clear(utils_Queue * const self) {
    utils_Array_clear(self->array);
    self->front = -1;
    self->rear = -1;
}
