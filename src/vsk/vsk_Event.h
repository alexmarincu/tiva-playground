#ifndef VSK_EVENT_H
#define VSK_EVENT_H

typedef struct vsk_Event vsk_Event;
typedef void (*vsk_Event_dispatchFun)(vsk_Event * const self);
struct vsk_Event {
    vsk_Event_dispatchFun dispatch;
};

vsk_Event * vsk_Event_init(vsk_Event * const self, vsk_Event_dispatchFun const dispatch);
void vsk_Event_dispatch(vsk_Event * const self);

#endif // VSK_EVENT_H
