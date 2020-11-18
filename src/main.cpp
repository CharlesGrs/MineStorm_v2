
#include <raylib.h>
#include "../headers/World.h"

int main(int argc, char* argv[])
{
    int screenWidth = 1080;
    int screenHeight = 720;
    World currentWorld;

    InitWindow(screenWidth, screenHeight, "MineStorm");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        currentWorld.Update();
    }

    CloseWindow();

    return 0;
}