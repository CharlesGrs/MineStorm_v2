
#include <raylib.h>
#include "../headers/World.h"

int main(int argc, char* argv[])
{
    int screenWidth = 1080;
    int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "MineStorm");

    World currentWorld;

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        currentWorld.Update();
    }

    //don't forget to delete allocated pointers
    currentWorld.entityManager.FreeBuffers();

    CloseWindow();

    return 0;
}