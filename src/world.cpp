#include <raylib.h>
#include "../headers/World.h"

// Debug
#include <string>

World::World()
{
    LoadResources();
    Texture spriteSheet = LoadTexture("assets/minestorm_sprite_atlas_mine_storm.png");
    EntityManager _entityManager(spriteSheet);
    entityManager = _entityManager;
}

void World::Update()
{
    BeginDrawing();
    ClearBackground(BLACK);
    BeginTextureMode(renderTexture);
    
    Debug();

    entityManager.UpdateEntities();
    entityManager.DrawEntities();

    EndTextureMode();

    BeginShaderMode(bloom);

    Rectangle renderTextureRect = { 0,0, renderTexture.texture.width, renderTexture.texture.height };
    Vector2 zero = { 0, 0 };
    DrawTextureRec(renderTexture.texture, renderTextureRect, zero, WHITE);

    EndShaderMode();

    EndDrawing();
}

void World::LoadResources() 
{
    bloom = LoadShader("assets/shaders/bloom.vs", "assets/shaders/bloom.fs");
    renderTexture = LoadRenderTexture(1080, 720);
}

void World::Debug() 
{
    if (IsKeyReleased(KEY_A))
    {
        Vector2 playerPos;
        playerPos.x = (float)(rand() % 1080);
        playerPos.y = (float)(rand() % 720);
        entityManager.InstantiateEntity(EntityIndexes::Player, playerPos, (float)(rand() % 360));
        DrawText("PRESSED", 100, 350, 20, LIGHTGRAY);
    }

    int size = (int)entityManager.loadedEntities.size();
    std::string s = std::to_string(size);
    char const* pChar = s.c_str();
    DrawText(pChar, 100, 450, 20, LIGHTGRAY);

}