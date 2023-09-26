#ifndef UT_H
#define UT_H
#include "ut_Array.h"
#include "ut_Queue.h"

#define ut_stkArr(itemType, length) \
    ((itemType[length]){ 0 })

#define ut_stkObj(type) \
    (&(type){ 0 })

#define ut_lengthOf(arr) \
    (sizeof(arr) / sizeof(arr[0]))

#endif // UT_H
