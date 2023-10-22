#ifndef VSK_QUEUE_H
#define VSK_QUEUE_H
/*............................................................................*/
typedef struct vsk_Queue vsk_Queue;
#include "vsk_LinkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/*............................................................................*/
struct vsk_Queue {
    vsk_LinkedList _linkedList;
};
/*............................................................................*/
vsk_Queue * vsk_Queue_init(vsk_Queue * const self);
bool vsk_Queue_isEmpty(vsk_Queue * const self);
void vsk_Queue_enqueue(vsk_Queue * const self, void * const obj);
void * vsk_Queue_dequeue(vsk_Queue * const self);
void vsk_Queue_clear(vsk_Queue * const self);
#endif // UT_QUEUE_H
