#include "utils_Array.h"

utils_Array * utils_Array_init(
    utils_Array * const self,
    void ** const items,
    size_t const length
) {
    self->items = items;
    self->length = length;
    utils_Array_clear(self);
    return self;
}

void utils_Array_insert(utils_Array * const self, void * const item, size_t const index) {
    self->items[index] = item;
}

void * utils_Array_get(utils_Array * const self, uint8_t const index) {
    return self->items[index];
}

void * utils_Array_remove(utils_Array * const self, uint8_t const index) {
    void * item = self->items[index];
    self->items[index] = 0;
    return item;
}

void utils_Array_clear(utils_Array * const self) {
    for (size_t i = 0; i < self->length; i++) {
        self->items[i] = 0;
    }
}

size_t utils_Array_length(utils_Array * const self) {
    return self->length;
}
