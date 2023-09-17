#ifndef UTILS_PRIMITIVEARRAY_H
#define UTILS_PRIMITIVEARRAY_H

#define utl_PrimitiveArray_length(self) \
    (sizeof(self) / sizeof(self[0]))

#endif // UTILS_PRIMITIVEARRAY_H
