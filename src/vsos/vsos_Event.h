#ifndef VSOS_EVENT_H
#define VSOS_EVENT_H

typedef struct vsos_Event vsos_Event;
typedef void (*vsos_Event_dispatchFun)(vsos_Event * const self);
struct vsos_Event {
    vsos_Event_dispatchFun dispatch;
};

vsos_Event * vsos_Event_init(vsos_Event * const self, vsos_Event_dispatchFun const dispatch);
void vsos_Event_dispatch(vsos_Event * const self);

#endif // VSOS_EVENT_H
