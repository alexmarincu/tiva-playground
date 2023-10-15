#ifndef VSK_LINKEDLIST_H
#define VSK_LINKEDLIST_H
/*............................................................................*/
typedef struct vsk_LinkedList vsk_LinkedList;
#include <stdbool.h>
typedef void (*vsk_LinkedListForEachOperation)(
    void * const item
);
typedef bool (*vsk_LinkedListFindPredicate)(
    void * const item
);
#include "vsk_Node.h"
#include <stdbool.h>
#include <stddef.h>
/*............................................................................*/
struct vsk_LinkedList {
    vsk_Node * _first;
    vsk_Node * _last;
    size_t _size;
};
/*............................................................................*/
vsk_LinkedList * vsk_LinkedList_init(
    vsk_LinkedList * const self
);
bool vsk_LinkedList_isEmpty(
    vsk_LinkedList * const self
);
void vsk_LinkedList_add(
    vsk_LinkedList * const self,
    size_t const index,
    void * const item
);
void vsk_LinkedList_addLast(
    vsk_LinkedList * const self,
    void * const item
);
void vsk_LinkedList_addFirst(
    vsk_LinkedList * const self,
    void * const item
);
void * vsk_LinkedList_remove(
    vsk_LinkedList * const self,
    size_t const index
);
void * vsk_LinkedList_removeItem(
    vsk_LinkedList * const self,
    void * const item
);
void * vsk_LinkedList_removeFirst(
    vsk_LinkedList * const self
);
void * vsk_LinkedList_removeLast(
    vsk_LinkedList * const self
);
void vsk_LinkedList_clear(
    vsk_LinkedList * const self
);
void * vsk_LinkedList_get(
    vsk_LinkedList * const self,
    size_t index
);
void * vsk_LinkedList_getFirst(
    vsk_LinkedList * const self
);
void * vsk_LinkedList_getLast(
    vsk_LinkedList * const self
);
size_t vsk_LinkedList_getSize(
    vsk_LinkedList * const self
);
void vsk_LinkedList_forEach(
    vsk_LinkedList * const self,
    vsk_LinkedListForEachOperation const operation
);
void * vsk_LinkedList_find(
    vsk_LinkedList * const self,
    vsk_LinkedListFindPredicate const predicate
);
#endif // VSK_LINKEDLIST_H
