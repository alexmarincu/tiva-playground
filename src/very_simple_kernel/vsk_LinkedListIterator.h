/*............................................................................*/
#ifndef VSK_LINKEDLISTITERATOR_H
#define VSK_LINKEDLISTITERATOR_H
/*............................................................................*/
typedef struct vsk_LinkedListIterator vsk_LinkedListIterator;
/*............................................................................*/
#include <stdbool.h>
/*............................................................................*/
#include "vsk_LinkedList.h"
#include "vsk_Node.h"
/*............................................................................*/
typedef void (*vsk_LinkedListIteratorForEachOperation)(void * const obj);
/*............................................................................*/
struct vsk_LinkedListIterator {
    vsk_LinkedList * _linkedList;
    vsk_Node * _current;
};
/*............................................................................*/
vsk_LinkedListIterator * vsk_LinkedListIterator_init(
    vsk_LinkedListIterator * const self, vsk_LinkedList * const linkedList
);
bool vsk_LinkedListIterator_hasNext(vsk_LinkedListIterator * const self);
bool vsk_LinkedListIterator_hasPrevious(vsk_LinkedListIterator * const self);
void * vsk_LinkedListIterator_next(vsk_LinkedListIterator * const self);
void * vsk_LinkedListIterator_previous(vsk_LinkedListIterator * const self);
void vsk_LinkedListIterator_forEach(
    vsk_LinkedListIterator * const self,
    vsk_LinkedListIteratorForEachOperation const operation
);
#endif // VSK_LINKEDLISTITERATOR_H
