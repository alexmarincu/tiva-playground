#ifndef UTILS_QUEUE_H
#define UTILS_QUEUE_H
#include "utils_Array.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    utils_Array * array;
    size_t front;
    size_t rear;
} utils_Queue;

utils_Queue * utils_Queue_init(
    utils_Queue * const self,
    utils_Array * const array
);

bool utils_Queue_isEmpty(utils_Queue * const self);
bool utils_Queue_isFull(utils_Queue * const self);
void utils_Queue_enqueue(utils_Queue * const self, void * const item);
void * utils_Queue_dequeue(utils_Queue * const self);
void utils_Queue_clear(utils_Queue * const self);

#endif // UTILS_QUEUE_H
