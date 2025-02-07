// Even though it didn't work as expected, it was so painful.

#include "raylib.h"

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(screenWidth, screenHeight, "Lenz");
    SetTargetFPS(60);

    float circleRadius = 50;
    float circleSpeed = 5;
    Vector2 circlePosition = {(float)screenWidth/2, (float)screenHeight/2};

    while (!WindowShouldClose()) {
        circleRadius += circleSpeed;
        if (circleRadius > 200 || circleRadius < 50) circleSpeed *= -1;

        BeginDrawing();
        ClearBackground(RED); 

        DrawCircleV(circlePosition, circleRadius, Fade(SKYBLUE, 0.5f));
        DrawRectangle(screenWidth - 300, 100, 200, 200, Fade(GOLD, 0.3f));

        EndDrawing();
    }

    CloseWindow();
    return 0;
}