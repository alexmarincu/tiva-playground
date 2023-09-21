#ifndef UTILS_H
#define UTILS_H
#include "utl_Array.h"
#include "utl_Queue.h"

#define utl_stkArr(itemType, length) \
    ((itemType[length]){ 0 })

#define utl_stkObj(type) \
    (&(type){ 0 })

#define utl_lengthOf(arr) \
    (sizeof(arr) / sizeof(arr[0]))

#endif // UTILS_H
