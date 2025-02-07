#include "x11_wrapper.h"
#include <stdio.h>
#include "raylib.h"

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(screenWidth, screenHeight, "Raylib Wallpaper");

    Window x11Window = (Window)GetWindowHandle();
    printf("X11 Window ID: %lu\n", x11Window);

    Display* display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Failed to open X display\n");
        return 1;
    }

    Window root = DefaultRootWindow(display);

    // Set window type to `_NET_WM_WINDOW_TYPE_DESKTOP` (attempt to make it behave like a wallpaper)
    Atom windowType = XInternAtom(display, "_NET_WM_WINDOW_TYPE", False);
    Atom typeDesktop = XInternAtom(display, "_NET_WM_WINDOW_TYPE_DESKTOP", False);
    XChangeProperty(display, x11Window, windowType, XA_ATOM, 32, PropModeReplace, (unsigned char*)&typeDesktop, 1);

    // Set window below all others
    Atom state = XInternAtom(display, "_NET_WM_STATE", False);
    Atom below = XInternAtom(display, "_NET_WM_STATE_BELOW", False);
    XChangeProperty(display, x11Window, state, XA_ATOM, 32, PropModeReplace, (unsigned char*)&below, 1);

    // Move the window to (0,0) and resize to cover the screen
    XMoveResizeWindow(display, x11Window, 0, 0, screenWidth, screenHeight);

    // Reparent the window to the root to make it a background
    XReparentWindow(display, x11Window, root, 0, 0);

    XFlush(display);
    XCloseDisplay(display);

    float circleRadius = 50;
    float circleSpeed = 5;
    Vector2 circlePosition = {(float)screenWidth / 2, (float)screenHeight / 2};

    while (!WindowShouldClose()) {
        circleRadius += circleSpeed;
        if (circleRadius > 200 || circleRadius < 50) circleSpeed *= -1;

        BeginDrawing();
        ClearBackground(BLANK);

        DrawCircleV(circlePosition, circleRadius, Fade(SKYBLUE, 0.5f));
        DrawRectangle(screenWidth - 300, 100, 200, 200, Fade(GOLD, 0.3f));

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
