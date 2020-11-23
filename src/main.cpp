
#include <raylib.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "../../headers/core/Master.h"


//#define MAX_BATCH_ELEMENTS  8192

int main(int argc, char* argv[])
{
    int screenWidth = 1080;
    int screenHeight = 720;

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "MineStorm");
    InitAudioDevice();

    Master master;

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        master.Update();
    }



    CloseWindow();

    return 0;
}