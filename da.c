#include <stdio.h>
#include <stdlib.h>
#include "da.h"


int main() {
    Ints arr = {0}; 

    for (int i = 0; i < 10; i++) {
        da_append(arr, i);

        printf("%d\n", arr.items[i]);
    }
    return 0;
}
