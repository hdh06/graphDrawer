#include <stdio.h>
#include <stdlib.h>

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
    } while(0)                                                                 \

int main() {
    Ints arr = {0}; 

    for (int i = 0; i < 10; i++) {
        da_append(arr, i);

        printf("%d\n", arr.items[i]);
    }
    return 0;
}
