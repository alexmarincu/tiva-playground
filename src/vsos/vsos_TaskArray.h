#ifndef VSOS_TASKARRAY_H
#define VSOS_TASKARRAY_H
#include "vsos_Task.h"
#include <stdint.h>

typedef struct {
    vsos_Task ** elements;
    uint8_t length;
} vsos_TaskArray;

#endif // VSOS_TASKARRAY_H
