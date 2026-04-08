#include <stdio.h>
#include "graph.h" 
#include "raylib.h"

#define NODE_SIZE 23
#define NODE_THICKNESS 3

void drawNode(Node* node) {
    DrawCircle(node->x, node->y, NODE_SIZE, node->clr);
    DrawCircle(node->x, node->y, NODE_SIZE - NODE_THICKNESS, WHITE);

    DrawText(node->c, node->x, node->y, 5, BLACK);
}

void drawLine(Line* line) {
    Node* x = line->x;
    Node* y = line->y;

    DrawLine(x->x, x->y, y->x, y->y, line->clr);
}
