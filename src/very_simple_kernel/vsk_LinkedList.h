/*----------------------------------------------------------------------------*/
#ifndef VSK_LINKEDLIST_H
#define VSK_LINKEDLIST_H
/*----------------------------------------------------------------------------*/
typedef struct vsk_LinkedList vsk_LinkedList;
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
#include <stddef.h>
/*----------------------------------------------------------------------------*/
#include "vsk_LinkedListIterator.h"
#include "vsk_Node.h"
/*----------------------------------------------------------------------------*/
struct vsk_LinkedList {
    vsk_Node * _first;
    vsk_Node * _last;
    size_t _size;
};
/*----------------------------------------------------------------------------*/
vsk_LinkedList * vsk_LinkedList_init(vsk_LinkedList * const self);
void vsk_LinkedList_addByIndex(
    vsk_LinkedList * const self, void * const obj, size_t const index
);
void vsk_LinkedList_addFirst(vsk_LinkedList * const self, void * const obj);
void vsk_LinkedList_addLast(vsk_LinkedList * const self, void * const obj);
void * vsk_LinkedList_getByIndex(vsk_LinkedList * const self, size_t index);
void * vsk_LinkedList_getFirst(vsk_LinkedList * const self);
void * vsk_LinkedList_getLast(vsk_LinkedList * const self);
void * vsk_LinkedList_removeByIndex(
    vsk_LinkedList * const self, size_t const index
);
void * vsk_LinkedList_removeFirst(vsk_LinkedList * const self);
void * vsk_LinkedList_removeLast(vsk_LinkedList * const self);
void * vsk_LinkedList_remove(
    vsk_LinkedList * const self, void * const obj
);
size_t vsk_LinkedList_getIndexOf(
    vsk_LinkedList * const self, void * const obj
);
bool vsk_LinkedList_isEmpty(vsk_LinkedList * const self);
size_t vsk_LinkedList_getSize(vsk_LinkedList * const self);
void vsk_LinkedList_clear(vsk_LinkedList * const self);
void vsk_LinkedList_forEach(
    vsk_LinkedList * const self,
    vsk_LinkedListIteratorForEachOperation const operation
);
void * vsk_LinkedList_find(
    vsk_LinkedList * const self,
    vsk_LinkedListIteratorFindPredicate const predicate
);
#endif // VSK_LINKEDLIST_H
