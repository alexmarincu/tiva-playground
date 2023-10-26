/*............................................................................*/
#ifndef VSK_NODE_H
#define VSK_NODE_H
/*............................................................................*/
typedef struct vsk_Node vsk_Node;
/*............................................................................*/
#include <stdbool.h>
/*............................................................................*/
#include "vsk_NodeClass.h"
/*............................................................................*/
struct vsk_Node {
    vsk_NodeClass * _klass;
    bool _isUsed;
    void * obj;
    vsk_Node * next;
    vsk_Node * prev;
};
/*............................................................................*/
vsk_Node * vsk_Node_init(vsk_Node * const self, void * const obj);
vsk_Node * vsk_Node_release(vsk_Node * const self);
#endif // VSK_NODE_H
