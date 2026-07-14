#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "graph.h"
#include "da.h"


int rrange(int l, int r) {
    return 1.0L * (r - l + 1) * rand() / RAND_MAX + l;
}

int main(void)
{
    srand(time(NULL));
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "test");

    SetWindowState(FLAG_WINDOW_TOPMOST);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
                        
    Node cursorNode = {0, 0, "", BLANK};

    Nodes nodeArr = {0};

    for (int i = 0; i < 10; i++) {
        Node tmp = {rrange(100, 700), rrange(100, 700), "a", BLACK};
        da_append(nodeArr, tmp);
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            da_foreach(Node, x, &nodeArr) {
                if (CheckCollisionPointCircle(GetMousePosition(), x->pos, 23)){ 
                    x->pos = GetMousePosition();
                    break;
                }
            }
        }
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            da_foreach(Node, x, &nodeArr) {
                drawNode(x);
                da_foreach(Node, y, &nodeArr) {
                    drawLineN(x, y);
                }
            }

        EndDrawing();

    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
    
    return 0;
}
