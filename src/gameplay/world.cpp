#include <raylib.h>
#include "../../headers/gameplay/World.h"

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
	BeginTextureMode(renderTexture);
	ClearBackground(BLACK);

	Debug();

	entityManager.UpdateEntities();
	entityManager.DrawEntities();

	EndTextureMode();

	BeginShaderMode(bloom);

	Rectangle renderTextureRect = { 0,0, renderTexture.texture.width, -renderTexture.texture.height };
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

void World::UnloadResources() 
{
	UnloadShader(bloom);
	UnloadRenderTexture(renderTexture);
	UnloadTexture(entityManager.spriteSheet);
}

void World::Debug()
{
	if (IsKeyReleased(KEY_SPACE))
	{
		Vector2 playerPos;
		playerPos.x = (float)(rand() % 1080);
		playerPos.y = (float)(rand() % 720);
		entityManager.InstantiateEntity(EntityIndexes::Player, playerPos, (float)(rand() % 360));
	}

	int size = (int)entityManager.loadedEntities.size();
	std::string s = "Entity count: " + std::to_string(size);
	char const* pChar = s.c_str();
	DrawText( pChar, 10, 10, 14, LIGHTGRAY);

}