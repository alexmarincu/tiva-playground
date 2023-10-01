#ifndef VSK_MESSAGE_H
#define VSK_MESSAGE_H

typedef struct vsk_Message vsk_Message;
typedef void (*vsk_MessageHandler)(void * const self);
struct vsk_Message {
    void * _recipient;
    vsk_MessageHandler _handler;
};

vsk_Message * vsk_Message_init(
    vsk_Message * const self,
    void * const recipient,
    vsk_MessageHandler const handler
);

void vsk_Message_dispatch(vsk_Message * const self);

#endif // VSK_MESSAGE_H
