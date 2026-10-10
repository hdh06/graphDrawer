#include <stdio.h>
#include <math.h>
#include "graph.h" 
#include "raylib.h"
#include "raymath.h"

//double nodeDistance(Node* node1, Node* node2) {
//    double dx = node1->x - node2->x;
//    double dy = node1->y - node2->y;
//    return sqrt(dx * dx + dy * dy);
//}

void drawNode(Node* node) {
    DrawCircleV(node->pos, NODE_SIZE, node->clr);
    DrawCircleV(node->pos, NODE_SIZE - NODE_THICKNESS, WHITE);

    DrawText(node->c, node->pos.x - 2, node->pos.y - 2, 5, BLACK);
}

void drawLine(Line* line) {
    Node* x = line->x;
    Node* y = line->y;

    DrawLineV(x->pos, y->pos, line->clr);
}

void drawLineN(Node* node1, Node* node2) {
    DrawLineV(node1->pos, node2->pos, BLACK);
}

/* -----------------------------------
 * Force Directed Calculation 
 * -----------------------------------
 */

// calcualte distance between two nodes
double nodeDistance(Node* node1, Node* node2) {
    return Vector2Distance(node1->pos, node2->pos);
}

// calcualte squared distance between two nodes
double nodeDistanceSqr(Node* node1, Node* node2) {
    return Vector2DistanceSqr(node1->pos, node2->pos);
}

// calculate attractive force between two nodes
double f_att(Node* x, Node* y) {
    return nodeDistanceSqr(x, y) / K_SPRING;
}
// calculate repulsive force between two nodes
double f_rep(Node* x, Node* y) {
    return K_SPRING * K_SPRING / nodeDistance(x, y);
}
