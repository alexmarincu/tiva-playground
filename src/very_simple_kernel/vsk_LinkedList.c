/*............................................................................*/
#include "vsk_LinkedList.h"
/*............................................................................*/
#include "../utils/ut.h"
#include "vsk_Assert.h"
#include "vsk_LinkedListIterator.h"
/*............................................................................*/
static vsk_Node * vsk_LinkedList_getNodeByIndex(
    vsk_LinkedList * const self, size_t index
);
/*............................................................................*/
vsk_LinkedList * vsk_LinkedList_init(vsk_LinkedList * const self) {
    self->_first = NULL;
    self->_last = NULL;
    self->_size = 0;
    return self;
}
/*............................................................................*/
static vsk_Node * vsk_LinkedList_getNodeByIndex(
    vsk_LinkedList * const self, size_t index
) {
    vsk_Assert_true(vsk_Assert_(), index < self->_size);
    vsk_Node * node;
    if (index <= self->_size / 2) {
        node = self->_first;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = self->_last;
        for (size_t i = self->_size - 1; i > index; i--) {
            node = node->prev;
        }
    }
    return node;
}
/*............................................................................*/
void vsk_LinkedList_addByIndex(
    vsk_LinkedList * const self, void * const obj, size_t const index
) {
    vsk_Assert_true(vsk_Assert_(), index <= self->_size);
    vsk_Node * newNode =
        vsk_Node_init(vsk_NodeClass_acquireNode(vsk_NodeClass_()), obj);
    if (self->_size == 0) {
        self->_first = newNode;
        self->_last = newNode;
    } else {
        if (index == self->_size) {
            vsk_Node * node = self->_last;
            node->next = newNode;
            newNode->prev = node;
            self->_last = newNode;
        } else if (index == 0) {
            vsk_Node * node = self->_first;
            newNode->next = node;
            node->prev = newNode;
            self->_first = newNode;
        } else {
            vsk_Node * node = vsk_LinkedList_getNodeByIndex(self, index);
            node->prev->next = newNode;
            newNode->prev = node->prev;
            newNode->next = node;
            node->prev = newNode;
        }
    }
    self->_size++;
}
/*............................................................................*/
void vsk_LinkedList_addFirst(vsk_LinkedList * const self, void * const obj) {
    vsk_LinkedList_addByIndex(self, obj, 0);
}
/*............................................................................*/
void vsk_LinkedList_addLast(vsk_LinkedList * const self, void * const obj) {
    vsk_LinkedList_addByIndex(self, obj, self->_size);
}
/*............................................................................*/
void * vsk_LinkedList_getByIndex(vsk_LinkedList * const self, size_t index) {
    return vsk_LinkedList_getNodeByIndex(self, index)->obj;
}
/*............................................................................*/
void * vsk_LinkedList_getFirst(vsk_LinkedList * const self) {
    return self->_first->obj;
}
/*............................................................................*/
void * vsk_LinkedList_getLast(vsk_LinkedList * const self) {
    return self->_last->obj;
}
/*............................................................................*/
void * vsk_LinkedList_removeByIndex(
    vsk_LinkedList * const self, size_t const index
) {
    vsk_Assert_true(vsk_Assert_(), index < self->_size);
    vsk_Node * node;
    void * obj;
    if (self->_size == 1) {
        node = self->_first;
        self->_first = NULL;
        self->_last = NULL;
    } else {
        if (index == self->_size - 1) {
            node = self->_last;
            self->_last = node->prev;
            self->_last->next = NULL;
        } else if (index == 0) {
            node = self->_first;
            self->_first = node->next;
            self->_first->prev = NULL;
        } else {
            node = vsk_LinkedList_getNodeByIndex(self, index);
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    obj = node->obj;
    vsk_Node_release(node);
    self->_size--;
    return obj;
}
/*............................................................................*/
void * vsk_LinkedList_removeFirst(vsk_LinkedList * const self) {
    return vsk_LinkedList_removeByIndex(self, 0);
}
/*............................................................................*/
void * vsk_LinkedList_removeLast(vsk_LinkedList * const self) {
    return vsk_LinkedList_removeByIndex(self, self->_size - 1);
}
/*............................................................................*/
void * vsk_LinkedList_remove(
    vsk_LinkedList * const self, void * const obj
) {
    // TODO
    return NULL;
}
/*............................................................................*/
size_t vsk_LinkedList_getIndexOf(
    vsk_LinkedList * const self, void * const obj
) {
    size_t index = -1;
    bool objFound = false;
    vsk_LinkedListIterator * iter =
        vsk_LinkedListIterator_init(ut_stkObj(vsk_LinkedListIterator), self);
    void * _obj;
    while ((_obj = vsk_LinkedListIterator_next(iter)) && !objFound) {
        index++;
        if (obj == _obj) {
            objFound = true;
        }
    }
    if (!objFound) {
        index = -1;
    }
    return index;
}
/*............................................................................*/
bool vsk_LinkedList_isEmpty(vsk_LinkedList * const self) {
    return (self->_size == 0);
}
/*............................................................................*/
size_t vsk_LinkedList_getSize(vsk_LinkedList * const self) {
    return self->_size;
}
/*............................................................................*/
void vsk_LinkedList_clear(vsk_LinkedList * const self) {
    while (self->_size > 0) {
        vsk_LinkedList_removeLast(self);
    }
}
/*............................................................................*/
void vsk_LinkedList_forEach(
    vsk_LinkedList * const self, vsk_LinkedListForEachOperation const operation
) {
    vsk_LinkedListIterator * iter =
        vsk_LinkedListIterator_init(ut_stkObj(vsk_LinkedListIterator), self);
    vsk_LinkedListIterator_forEach(iter, operation);
}
/*............................................................................*/
void * vsk_LinkedList_find(
    vsk_LinkedList * const self, vsk_LinkedListFindPredicate const predicate
) {
    bool objFound = false;
    vsk_LinkedListIterator * iter =
        vsk_LinkedListIterator_init(ut_stkObj(vsk_LinkedListIterator), self);
    void * obj;
    while (vsk_LinkedListIterator_hasNext(iter) && !objFound) {
        obj = vsk_LinkedListIterator_next(iter);
        if (predicate(obj)) {
            objFound = true;
        }
    }
    if (!objFound) {
        obj = NULL;
    }
    return obj;
}
