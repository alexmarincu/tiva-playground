/*----------------------------------------------------------------------------*/
#ifndef VSK_NODECLASS_H
#define VSK_NODECLASS_H
/*----------------------------------------------------------------------------*/
typedef struct vsk_NodeClass vsk_NodeClass;
/*----------------------------------------------------------------------------*/
#include <stddef.h>
/*----------------------------------------------------------------------------*/
#include "vsk_Node.h"
/*----------------------------------------------------------------------------*/
struct vsk_NodeClass {
    struct {
        vsk_Node * nodes;
        size_t capacity;
        vsk_Node * firstFree;
    } _pool;
};
/*----------------------------------------------------------------------------*/
vsk_NodeClass * vsk_NodeClass_(void);
vsk_NodeClass * vsk_NodeClass_init(
    vsk_NodeClass * const self, vsk_Node * const nodes, size_t const capacity
);
vsk_Node * vsk_NodeClass_acquireNode(vsk_NodeClass * const self);
#endif // VSK_NODECLASS_H
