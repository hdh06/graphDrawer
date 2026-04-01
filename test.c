#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "test");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    int i = 0;
    int dir = 1;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            if (i >= 700 || i < 0)
                dir = -dir;

            DrawRectangle( i+= dir * 10, 400, 100, 100, BLACK);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
