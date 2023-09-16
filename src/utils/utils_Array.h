#ifndef UTILS_ARRAY_H
#define UTILS_ARRAY_H
#include <stddef.h>
#include <stdint.h>

typedef struct {
    void ** items;
    size_t length;
} utils_Array;

utils_Array * utils_Array_init(
    utils_Array * const self,
    void ** const items,
    size_t const length
);
void utils_Array_insert(utils_Array * const self, void * const item, size_t const index);
void * utils_Array_get(utils_Array * const self, uint8_t const index);
void * utils_Array_remove(utils_Array * const self, uint8_t const index);
void utils_Array_clear(utils_Array * const self);
size_t utils_Array_length(utils_Array * const self);

#endif // UTILS_ARRAY_H
