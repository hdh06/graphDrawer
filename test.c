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

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
                                    //
    Node node1; 
    node1.x = 100; 
    node1.c = "a";
    node1.y = 100;
    node1.clr = BLACK;

    Node node2; 
    node2.x = 200; 
    node2.c = "a";
    node2.y = 200;
    node2.clr = BLACK;

    Line line1; 
    line1.x = &node1;
    line1.y = &node2;
    line1.clr = BLACK;

    int dir1x = 1;
    int dir1y = 1;
    int dir2x = 1;
    int dir2y = 1;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (node1.x < screenWidth && node1.x > 0)
                node1.x += 5 * dir1x;
            else {
                dir1x = -dir1x;
                node1.x += 5 * dir1x;
            }


            if (node1.y < screenHeight && node1.y > 0)
                node1.y += 10 * dir1y;
            else {
                dir1y = -dir1y;
                node1.y += 10 * dir1y;
            }

            if (node2.x < screenWidth && node2.x > 0)
                node2.x += 5 * dir2x;
            else {
                dir2x = -dir2x;
                node2.x += 5 * dir2x;
            }


            if (node2.y < screenHeight && node2.y > 0)
                node2.y += 20 * dir2y;
            else {
                dir2y = -dir2y;
                node2.y += 20 * dir2y;
            }
            // Draw a node 
            drawNode(&node2);
            drawNode(&node1);

            drawLine(&line1);

        EndDrawing();

    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
    
    return 0;
}
