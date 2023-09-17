#ifndef UTILS_QUEUE_H
#define UTILS_QUEUE_H
#include "utl_Array.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    utl_Array * array;
    size_t front;
    size_t rear;
} utl_Queue;

utl_Queue * utl_Queue_init(
    utl_Queue * const self,
    utl_Array * const array
);

bool utl_Queue_isEmpty(utl_Queue * const self);
bool utl_Queue_isFull(utl_Queue * const self);
void utl_Queue_enqueue(utl_Queue * const self, void * const item);
void * utl_Queue_dequeue(utl_Queue * const self);
void utl_Queue_clear(utl_Queue * const self);

#endif // UTILS_QUEUE_H
