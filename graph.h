#ifndef GRAPH_H
#define GRAPH_H 

#include "raylib.h"

typedef struct Node {
    int x;
    int y;
    char* c;
    Color clr;  
} Node;

typedef struct Line {
    struct Node* x;
    struct Node* y;
    char* label;
    bool isDirectional; 
    int dir; // -1: x <- y, 0: x <-> y, 1: x -> y
    Color clr;
} Line;

void drawNode(Node* node);
void drawLine(Line* line);

#endif
