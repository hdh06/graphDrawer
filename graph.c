#include <stdio.h>
#include "graph.h" 
#include "raylib.h"

void drawNode(struct Node* node) {
    DrawCircle(node->x, node->y, 23, node->clr);
}
