#ifndef VSK_EVENT_H
#define VSK_EVENT_H

typedef struct vsk_Event vsk_Event;
typedef void (*vsk_EventDispatch)(vsk_Event * const self);
struct vsk_Event {
    vsk_EventDispatch dispatch;
};

vsk_Event * vsk_Event_init(vsk_Event * const self, vsk_EventDispatch const dispatch);
void vsk_Event_dispatch(vsk_Event * const self);

#endif // VSK_EVENT_H
