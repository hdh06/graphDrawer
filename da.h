#include <stdlib.h>
#ifndef DA_H
#define DA_H

typedef struct { 
    int *items;
    size_t count;
    size_t capacity;
} Ints;

#define da_append(arr, x)                                                      \
    do {                                                                       \
        if (arr.count >= arr.capacity) {                                       \
            if (arr.capacity == 0) arr.capacity = 256;                         \
            else arr.capacity *= 2;                                            \
            arr.items = realloc(arr.items, arr.capacity * sizeof(*arr.items)); \
        }                                                                      \
        arr.items[arr.count++] = x;                                            \
    } while(0)                                                                 

#endif // DA_H
