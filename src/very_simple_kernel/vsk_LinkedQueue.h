/*----------------------------------------------------------------------------*/
#ifndef VSK_LINKEDQUEUE_H
#define VSK_LINKEDQUEUE_H
/*----------------------------------------------------------------------------*/
typedef struct vsk_LinkedQueue vsk_LinkedQueue;
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
/*----------------------------------------------------------------------------*/
#include "vsk_LinkedList.h"
/*----------------------------------------------------------------------------*/
struct vsk_LinkedQueue {
    vsk_LinkedList _linkedList;
};
/*----------------------------------------------------------------------------*/
vsk_LinkedQueue * vsk_LinkedQueue_init(vsk_LinkedQueue * const self);
bool vsk_LinkedQueue_isEmpty(vsk_LinkedQueue * const self);
void vsk_LinkedQueue_enqueue(vsk_LinkedQueue * const self, void * const obj);
void * vsk_LinkedQueue_dequeue(vsk_LinkedQueue * const self);
void vsk_LinkedQueue_clear(vsk_LinkedQueue * const self);
#endif // VSK_LINKEDQUEUE_H
