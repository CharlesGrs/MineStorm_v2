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

	if (enableShader)
	{
		BeginTextureMode(renderTexture);
	}
	ClearBackground(BLACK);


	entityManager.UpdateEntities();
	entityManager.DrawEntities();

	if (enableShader)
	{
		EndTextureMode();

		BeginShaderMode(bloom);
		Rectangle renderTextureRect = { 0,0, renderTexture.texture.width, -renderTexture.texture.height };
		Vector2 zero = { 0, 0 };
		DrawTextureRec(renderTexture.texture, renderTextureRect, zero, WHITE);
		EndShaderMode();

		DrawRectangle(0, 0, 50, 50, BLACK);
		DrawRectangle(windowWidth - 50, 0, 50, 50, BLACK);
		DrawRectangle(windowWidth - 50, windowHeight - 50, 50, 50, BLACK);
		DrawRectangle(0, windowHeight - 50, 50, 50, BLACK);
	}







	Debug();

	EndDrawing();
}

void World::LoadResources()
{
	bloom = LoadShader(0, "assets/shaders/bloom.fs");
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

	if (IsKeyReleased(KEY_F1))
	{
		enableShader = !enableShader;
	}

	if(enableShader)
		DrawText("Press F1 to disable shaders", 5, windowHeight-15, 12, WHITE);
	else
		DrawText("Press F1 to enable shaders", 5, windowHeight - 15, 12, WHITE);


	int size = (int)entityManager.loadedEntities.size();
	std::string s = "Entity count: " + std::to_string(size);
	char const* pChar = s.c_str();
	DrawText( pChar, 5, 10, 12, WHITE);
}