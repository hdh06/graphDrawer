#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>


int rrange(int l, int r) {
    return 1.0L * (r - l + 1) * rand() / RAND_MAX + l;
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "test");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    int x = rrange(100, 700);
    int y = rrange(100, 700);
    printf("%d, %d\n", x, y);
    int dir = 1;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            if (x >= 700 || x < 0)
                dir = -dir;

            DrawRectangle(x += dir * 10, y, 100, 100, BLACK);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
