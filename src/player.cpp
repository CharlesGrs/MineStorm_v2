#include <raylib.h>
#include "../headers/Player.h"

// Debug
#include <string>


void Player::Update()
{
    if (IsKeyReleased(KEY_B))
    {
        DrawText("PRESSED B", 100, 300, 20, LIGHTGRAY);
    }
}
