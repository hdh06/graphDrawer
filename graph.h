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
    Node* x;
    Node* y;
    char* label;
    bool isDirectional; 
    int dir; // -1: x <- y, 0: x <-> y, 1: x -> y
    Color clr;
};

