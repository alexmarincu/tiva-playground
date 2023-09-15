#ifndef VSOS_OS_H
#define VSOS_OS_H
#include "vsos_Scheduler.h"
#include "vsos_SysTime.h"

typedef struct vsos_Os vsos_Os;

vsos_Os * vsos_Os_(void);
vsos_Os * vsos_Os_init(vsos_Os * const self);

#endif // VSOS_OS_H
