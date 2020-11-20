#include "../../headers/gameplay/EntityManager.h"
#include "../../headers/helpers/SpriteHelper.h"
#include "../../headers/entities/Player.h"
//#include "../../headers/entities/Mine.h"
//#include "../../headers/entities/SpawnPoint.h"
#include "../../headers/entities/Bullet.h"
//#include "../../headers/entities/MineLayer.h"
#include <stdlib.h>
#include <raylib.h>

EntityManager::EntityManager(Texture _spriteSheet) : spriteSheet(_spriteSheet)
{
	LoadEntitiesReferences();
}

EntityManager::~EntityManager()
{
	FreeBuffers();
}

void EntityManager::LoadEntitiesReferences()
{
	Vector2 defaultPosition;
	defaultPosition.x = 0;
	defaultPosition.y = 0;

	Rectangle playerSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 0);
	prefabs[0] = new Player(defaultPosition, 5, 0.25, playerSpriteRect, spriteSheet);


	#pragma region LATER

	//Rectangle spawnPointSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 1);
	//prefabs[1] = new SpawnPoint(defaultPosition, 10, 1, spawnPointSpriteRect, spriteSheet);

	//Rectangle MineLayerSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 2);
	//prefabs[2] = new MineLayer(defaultPosition, 10, 1, MineLayerSpriteRect, spriteSheet);

	Rectangle bulletSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 3);
	prefabs[3] = new Bullet(defaultPosition, 15, 0.25, bulletSpriteRect, spriteSheet);

	//Rectangle floatingMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 4);
	//prefabs[4] = new Floating_Mine(defaultPosition, 10, 1, floatingMineSpriteRect, spriteSheet);

	//Rectangle fireballMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 5);
	//prefabs[5] = new Fireball_Mine(defaultPosition, 10, 1, fireballMineSpriteRect, spriteSheet);

	//Rectangle magneticMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 6);
	//prefabs[6] = new Magnetic_Mine(defaultPosition, 10, 1, magneticMineSpriteRect, spriteSheet);

	//Rectangle magneticFireballMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 7);
	//prefabs[7] = new Magnetic_Fireball_Mine(defaultPosition, 10, 1, magneticFireballMineSpriteRect, spriteSheet);

#pragma endregion
}

Entity* EntityManager::InstantiateEntity(EntityIndexes index, Vector2 position)
{
	int entityIndex = (int)index;

	Entity* newEntity = prefabs[entityIndex]->Clone();
	newEntity->position = position;

	loadedEntities.push_back(newEntity);
	return newEntity;
}

Entity* EntityManager::InstantiateEntity(EntityIndexes index, Vector2 position, float rotation)
{
	int entityIndex = (int)index;

	Entity* newEntity = prefabs[entityIndex]->Clone();
	newEntity->position = position;
	newEntity->rotation = rotation;

	loadedEntities.push_back(newEntity);

	return newEntity;
}

void EntityManager::DestroyEntity(Entity* entity) {}

void EntityManager::UpdateEntities()
{
	for (Entity* i : loadedEntities)
		i->Update();
}

void EntityManager::DrawEntities()
{
	for (Entity* i : loadedEntities)
		i->Draw();
}

void EntityManager::FreeBuffers()
{
	UnloadTexture(spriteSheet);
	while (!loadedEntities.empty()) delete loadedEntities.front(), loadedEntities.pop_front();

	for (int i = 0; i < 8; i++)
		delete prefabs[i];
}
