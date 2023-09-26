#ifndef UT_QUEUE_H
#define UT_QUEUE_H
#include "ut_Array.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    ut_Array * array;
    size_t front;
    size_t rear;
} ut_Queue;

ut_Queue * ut_Queue_init(
    ut_Queue * const self,
    ut_Array * const array
);

bool ut_Queue_isEmpty(ut_Queue * const self);
bool ut_Queue_isFull(ut_Queue * const self);
void ut_Queue_enqueue(ut_Queue * const self, void * const item);
void * ut_Queue_dequeue(ut_Queue * const self);
void ut_Queue_clear(ut_Queue * const self);

#endif // UT_QUEUE_H
