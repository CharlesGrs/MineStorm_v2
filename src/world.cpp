#include <raylib.h>
#include "../headers/World.h"
#include "../headers/EntityManager.h"

// Debug
#include <string>

World::World()
{
    EntityManager _entityManager;
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
        entityManager.InstantiateEntity(EntityIndexes::Player);
        DrawText("PRESSED", 100, 350, 20, LIGHTGRAY);
    }

    int size = entityManager.loadedEntities.size();
    std::string s = std::to_string(size);
    char const* pChar = s.c_str();
    DrawText(pChar, 100, 450, 20, LIGHTGRAY);

    #pragma endregion

    EndDrawing();

    // Implement Post-Process Shader here
}