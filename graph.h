#ifndef GRAPH_H
#define GRAPH_H 

#include "raylib.h"

struct Node {
    int x;
    int y;
    char* c;
    Color clr;  
};

struct Line {
    struct Node* x;
    struct Node* y;
    char* label;
    bool isDirectional; 
    int dir; // -1: x <- y, 0: x <-> y, 1: x -> y
    Color clr;
};

void drawNode(struct Node* node);

#endif
