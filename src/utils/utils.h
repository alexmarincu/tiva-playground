#ifndef UTILS_H
#define UTILS_H

#define utils_salloca(type, length) \
    ((type[length]){ 0 })

#define utils_salloc(type) \
    (&(type){ 0 })

#endif // UTILS_H
