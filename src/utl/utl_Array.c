#include "utl_Array.h"

utl_Array * utl_Array_init(
    utl_Array * const self,
    void ** const items,
    size_t const length
) {
    self->items = items;
    self->length = length;
    utl_Array_clear(self);
    return self;
}

void utl_Array_insert(utl_Array * const self, void * const item, size_t const index) {
    self->items[index] = item;
}

void * utl_Array_get(utl_Array * const self, uint8_t const index) {
    return self->items[index];
}

void * utl_Array_remove(utl_Array * const self, uint8_t const index) {
    void * item = self->items[index];
    self->items[index] = 0;
    return item;
}

void utl_Array_clear(utl_Array * const self) {
    for (size_t i = 0; i < self->length; i++) {
        self->items[i] = 0;
    }
}

size_t utl_Array_length(utl_Array * const self) {
    return self->length;
}
