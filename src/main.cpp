
#include <raylib.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "../../headers/gameplay/World.h"

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

    //free heap used
    currentWorld.UnloadResources();
    currentWorld.entityManager.FreeBuffers();

    CloseWindow();
    _CrtDumpMemoryLeaks();

    return 0;
}