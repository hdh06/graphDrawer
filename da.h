/*
 * This is the header for dynamic arrays
 */
#include <stdlib.h>
#include "graph.h"
#ifndef DA_H
#define DA_H

typedef struct { 
    int *items;
    size_t count;
    size_t capacity;
} Ints;

typedef struct { 
    float *items;
    size_t count;
    size_t capacity;
} Floats;

typedef struct {
    Node *items;
    size_t count;
    size_t capacity;
} Nodes;

#define da_append(arr, x)                                                      \
    do {                                                                       \
        if (arr.count >= arr.capacity) {                                       \
            if (arr.capacity == 0) arr.capacity = 256;                         \
            else arr.capacity *= 2;                                            \
            arr.items = realloc(arr.items, arr.capacity * sizeof(*arr.items)); \
        }                                                                      \
        arr.items[arr.count++] = x;                                            \
    } while(0)                                                                 

#define da_foreach(Type, it, arr) for (Type *it = (arr)->items; it < (arr)->items + (arr)->count; ++it)

#endif // DA_H
