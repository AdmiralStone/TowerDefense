#include "raylib.h"

int main(){
    // Initialize the window
    InitWindow(800,600,"Tower Defense");

    // Main game loop
    while(!WindowShouldClose()){
        // Start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw some text
        DrawText("Welcome to Tower Defense!", 190,200,20, LIGHTGRAY);

        // Finishing drawing
        EndDrawing();
    }

    // CLose the window deinitialize
    CloseWindow();

    return 0;

}