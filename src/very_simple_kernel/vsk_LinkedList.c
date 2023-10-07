/*............................................................................*/
#include "vsk_LinkedList.h"
#include "vsk_Assert.h"
/*............................................................................*/
static vsk_Node * createNode(
    vsk_LinkedList * const self,
    void * const item
);
/*............................................................................*/
vsk_LinkedList * vsk_LinkedList_init(
    vsk_LinkedList * const self
) {
    self->_first = NULL;
    self->_last = NULL;
    self->_size = 0;
    return self;
}
/*............................................................................*/
bool vsk_LinkedList_isEmpty(
    vsk_LinkedList * const self
) {
    return (self->_size == 0);
}
/*............................................................................*/
static vsk_Node * createNode(
    vsk_LinkedList * const self,
    void * const item
) {
    return vsk_Node_init(vsk_NodeClass_acquireNode(vsk_NodeClass_()), item);
}
/*............................................................................*/
static vsk_Node * getNode(
    vsk_LinkedList * const self,
    size_t index
) {
    vsk_Assert_check(vsk_Assert_(), index < self->_size);
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
void vsk_LinkedList_add(
    vsk_LinkedList * const self,
    size_t const index,
    void * const item
) {
    vsk_Assert_check(vsk_Assert_(), index <= self->_size);
    vsk_Node * newNode = createNode(self, item);
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
            vsk_Node * node = getNode(self, index);
            node->prev->next = newNode;
            newNode->prev = node->prev;
            newNode->next = node;
            node->prev = newNode;
        }
    }
    self->_size++;
}
/*............................................................................*/
void vsk_LinkedList_addFirst(
    vsk_LinkedList * const self,
    void * const item
) {
    vsk_LinkedList_add(self, 0, item);
}
/*............................................................................*/
void vsk_LinkedList_addLast(
    vsk_LinkedList * const self,
    void * const item
) {
    vsk_LinkedList_add(self, self->_size, item);
}
/*............................................................................*/
void vsk_LinkedList_remove(
    vsk_LinkedList * const self,
    size_t const index
) {
    vsk_Assert_check(vsk_Assert_(), index < self->_size);
    vsk_Node * node;
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
            node = getNode(self, index);
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    vsk_Node_release(node);
    self->_size--;
} /*............................................................................*/
bool static checkItem(
    void * const item,
    void * const data
) {
    struct {
        void * item;
        size_t index;
    } * _data = data;
    bool breakCondition = false;
    _data->index++;
    if (item == _data->item) {
        breakCondition = true;
    }
    return breakCondition;
}
/*............................................................................*/
size_t vsk_LinkedList_getIndex(
    vsk_LinkedList * const self,
    void * const item
) {
    struct {
        void * item;
        size_t index;
    } data = {
        .item = item,
        .index = -1,
    };
    vsk_LinkedList_forEach(self, checkItem, &data);
    if (data.index == self->_size) {
        data.index = -1;
    }
    return data.index;
}
/*............................................................................*/
void vsk_LinkedList_removeItem(
    vsk_LinkedList * const self,
    void * const item
) {
    // todo: improve removal to not parse the list twice
    vsk_LinkedList_remove(self, vsk_LinkedList_getIndex(self, item));
}
/*............................................................................*/
void vsk_LinkedList_removeFirst(
    vsk_LinkedList * const self
) {
    vsk_LinkedList_remove(self, 0);
}
/*............................................................................*/
void vsk_LinkedList_removeLast(
    vsk_LinkedList * const self
) {
    vsk_LinkedList_remove(self, self->_size - 1);
}
/*............................................................................*/
void vsk_LinkedList_clear(
    vsk_LinkedList * const self
) {
    while (self->_size > 0) {
        vsk_LinkedList_removeLast(self);
    }
}
/*............................................................................*/
void * vsk_LinkedList_getFirst(
    vsk_LinkedList * const self
) {
    return self->_first->item;
}
/*............................................................................*/
void * vsk_LinkedList_getLast(
    vsk_LinkedList * const self
) {
    return self->_last->item;
}
/*............................................................................*/
void * vsk_LinkedList_get(
    vsk_LinkedList * const self,
    size_t index
) {
    return getNode(self, index)->item;
}
/*............................................................................*/
size_t vsk_LinkedList_getSize(
    vsk_LinkedList * const self
) {
    return self->_size;
}
/*............................................................................*/
void vsk_LinkedList_forEach(
    vsk_LinkedList * const self,
    vsk_LinkedListForEachAction const action,
    void * const data
) {
    vsk_Assert_check(vsk_Assert_(), action);
    bool breakCondition = false;
    for (
        vsk_Node * node = self->_first;
        ((breakCondition == false) && (node != NULL));
        node = node->next
    ) {
        breakCondition = action(node->item, data);
    }
}
