#include <raylib.h>
#include "../headers/World.h"
#include "../headers/EntityManager.h"

// Debug
#include <string>

World::World()
{
    Texture spriteSheet = LoadTexture("/Assets/minestorm_sprite_atlas_mine_storm.png");
    EntityManager _entityManager(spriteSheet);
    entityManager = _entityManager;
}

void World::Update()
{
    BeginDrawing();
    ClearBackground(BLACK);

    entityManager.UpdateEntities();

    // Probably solve collisions here

    entityManager.DrawEntities();

    #pragma region DEBUG

    if (IsKeyDown(KEY_A))
    {
        Vector2 playerPos;
        playerPos.x = 350;
        playerPos.y = 350;
        entityManager.InstantiateEntity(EntityIndexes::Player, playerPos);
        DrawText("PRESSED", 100, 350, 20, LIGHTGRAY);
    }

    int size = (int)entityManager.loadedEntities.size();
    std::string s = std::to_string(size);
    char const* pChar = s.c_str();
    DrawText(pChar, 100, 450, 20, LIGHTGRAY);

    #pragma endregion

    EndDrawing();

    // Implement Post-Process Shader here
}