#ifndef RBUTTONPRESSEVENT_H
#define RBUTTONPRESSEVENT_H
#include "../vsk/vsk_Event.h"

typedef struct RButtonPressEvent RButtonPressEvent;

RButtonPressEvent * RButtonPressEvent_(void);
RButtonPressEvent * RButtonPressEvent_init(RButtonPressEvent * const self);

#endif // RBUTTONPRESSEVENT_H
