#ifndef UT_ARRAY_H
#define UT_ARRAY_H
/*............................................................................*/
typedef struct ut_Array ut_Array;
#include <stddef.h>
#include <stdint.h>
/*............................................................................*/
struct ut_Array {
    void ** _items;
    size_t _length;
};
/*............................................................................*/
ut_Array * ut_Array_init(
    ut_Array * const self,
    void ** const items,
    size_t const length
);
void ut_Array_insert(
    ut_Array * const self,
    void * const item,
    size_t const index
);
void * ut_Array_get(
    ut_Array * const self,
    uint8_t const index
);
void * ut_Array_remove(
    ut_Array * const self,
    uint8_t const index
);
void ut_Array_clear(
    ut_Array * const self
);
size_t ut_Array_length(
    ut_Array * const self
);
#endif // UT_ARRAY_H
