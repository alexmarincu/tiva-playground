#ifndef LBUTTONPRESSEVENT_H
#define LBUTTONPRESSEVENT_H
#include "../vsk/vsk_Event.h"

typedef struct LButtonPressEvent LButtonPressEvent;

LButtonPressEvent * LButtonPressEvent_(void);
LButtonPressEvent * LButtonPressEvent_init(LButtonPressEvent * const self);

#endif // LBUTTONPRESSEVENT_H
