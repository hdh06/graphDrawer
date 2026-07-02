#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


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

            drawNode(&node1);

        EndDrawing();

    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
    
    return 0;
}
