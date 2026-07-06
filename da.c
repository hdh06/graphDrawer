#include <stdio.h>
#include "da.h"

int main() {
    Floats arr = {0}; 

    for (int i = 0; i < 10; i++) {
        da_append(arr, i);
    }
    return 0;
}
