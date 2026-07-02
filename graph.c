#include <stdio.h>
#include <math.h>
#include "graph.h" 
#include "raylib.h"

#define NODE_SIZE 23
#define NODE_THICKNESS 3

double nodeDistance(Node* node1, Node* node2) {
    double dx = node1->x - node2->x;
    double dy = node1->y - node2->y;
    return sqrt(dx * dx + dy * dy);
}

void drawNode(Node* node) {
    DrawCircle(node->x, node->y, NODE_SIZE, node->clr);
    DrawCircle(node->x, node->y, NODE_SIZE - NODE_THICKNESS, WHITE);

    DrawText(node->c - 2, node->x - 2, node->y, 5, BLACK);
}

void drawLine(Line* line) {
    Node* x = line->x;
    Node* y = line->y;

    DrawLine(x->x, x->y, y->x, y->y, line->clr);
}

void drawLineN(Node* node1, Node* node2) {
    DrawLine(node1->x, node1->y, node2->x, node2->y, BLACK);
}

