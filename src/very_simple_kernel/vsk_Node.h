#ifndef VSK_NODE_H
#define VSK_NODE_H
/*............................................................................*/
typedef struct vsk_Node vsk_Node;
#include "vsk_NodeClass.h"
#include <stdbool.h>
/*............................................................................*/
struct vsk_Node {
    vsk_NodeClass * _klass;
    bool _isUsed;
    void * item;
    vsk_Node * next;
    vsk_Node * prev;
};
/*............................................................................*/
vsk_Node * vsk_Node_init(vsk_Node * const self, void * const item);
vsk_Node * vsk_Node_release(vsk_Node * const self);
#endif // VSK_NODE_H
