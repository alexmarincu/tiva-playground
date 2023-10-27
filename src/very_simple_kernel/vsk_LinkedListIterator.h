/*............................................................................*/
#ifndef VSK_LINKEDLISTITERATOR_H
#define VSK_LINKEDLISTITERATOR_H
/*............................................................................*/
typedef struct vsk_LinkedListIterator vsk_LinkedListIterator;
/*............................................................................*/
#include <stdbool.h>
/*............................................................................*/
typedef bool (*vsk_LinkedListIteratorFindPredicate)(void * const obj);
typedef void (*vsk_LinkedListIteratorForEachOperation)(void * const obj);
#include "vsk_LinkedList.h"
#include "vsk_Node.h"
/*............................................................................*/
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
void * vsk_LinkedListIterator_find(
    vsk_LinkedListIterator * const self,
    vsk_LinkedListIteratorFindPredicate const predicate
);
#endif // VSK_LINKEDLISTITERATOR_H
