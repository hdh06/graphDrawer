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
                                    //
    Node node1 = {.x = 100, .y = 200, .c = "a", .clr = BLACK}; 
    Node node2 = {.x = 200, .y = 200, .c = "a", .clr = BLACK}; 
    Node node3 = {.x = 100, .y = 100, .c = "a", .clr = BLACK};

    Line line1; 
    line1.x = &node1;
    line1.y = &node2;
    line1.clr = BLACK;


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw a node 
            drawNode(&node2);
            drawNode(&node1);
            drawNode(&node3); 

            drawLine(&line1);
            drawLineN(&node2, &node3);
            drawLineN(&node3, &node1);

        EndDrawing();

    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
    
    return 0;
}
