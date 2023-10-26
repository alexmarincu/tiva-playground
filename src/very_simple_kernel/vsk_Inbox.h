/*............................................................................*/
#ifndef VSK_INBOX_H
#define VSK_INBOX_H
/*............................................................................*/
typedef struct vsk_Inbox vsk_Inbox;
/*............................................................................*/
#include "vsk_LinkedQueue.h"
#include "vsk_Message.h"
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_Inbox {
    vsk_Task * task;
    vsk_LinkedQueue _messageQueue;
};
/*............................................................................*/
vsk_Inbox * vsk_Inbox_init(vsk_Inbox * const self, vsk_Task * const task);
bool vsk_Inbox_isEmpty(vsk_Inbox * const self);
void vsk_Inbox_postMessage(vsk_Inbox * const self, vsk_Message * const message);
vsk_Message * vsk_Inbox_readMessage(vsk_Inbox * const self);
void vsk_Inbox_clear(vsk_Inbox * const self);
#endif // VSK_INBOX_H
