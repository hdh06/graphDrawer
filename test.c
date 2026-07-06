#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "da.h"


int rrange(int l, int r) {
    return 1.0L * (r - l + 1) * rand() / RAND_MAX + l;
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "test");

    SetWindowState(FLAG_WINDOW_TOPMOST);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
                        
    Node cursorNode = {0, 0, "", BLANK};

    Node node1 = {100, 100, "a", BLACK};
    Node node2 = {200, 200, "a", BLACK};
    Node node3 = {300, 300, "a", BLACK};

    Nodes nodeArr = {0};

    da_append(nodeArr, node1);
    da_append(nodeArr, node2);
    da_append(nodeArr, node3);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        cursorNode.x = GetMouseX();
        cursorNode.y = GetMouseY();

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            if (nodeDistance(&cursorNode, &node1) <= 100) {
                node1.x = GetMouseX();
                node1.y = GetMouseY();
            }
        }
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            da_foreach(Node, x, &nodeArr) {
                drawNode(x);
            }

        EndDrawing();

    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
    
    return 0;
}
