#ifndef UTL_ARRAY_H
#define UTL_ARRAY_H
#include <stddef.h>
#include <stdint.h>

typedef struct {
    void ** items;
    size_t length;
} utl_Array;

utl_Array * utl_Array_init(
    utl_Array * const self,
    void ** const items,
    size_t const length
);
void utl_Array_insert(utl_Array * const self, void * const item, size_t const index);
void * utl_Array_get(utl_Array * const self, uint8_t const index);
void * utl_Array_remove(utl_Array * const self, uint8_t const index);
void utl_Array_clear(utl_Array * const self);
size_t utl_Array_length(utl_Array * const self);

#endif // UTL_ARRAY_H
