#include "../headers/EntityManager.h"
#include "../headers/SpriteHelper.h"
#include <raylib.h>


EntityManager::EntityManager(Texture _spriteSheet) : spriteSheet(_spriteSheet) 
{
	LoadEntitiesReferences();
}

void EntityManager::LoadEntitiesReferences()
{
	Vector2 defaultPosition;
	defaultPosition.x = 0;
	defaultPosition.y = 0;

	Rectangle playerSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 0);
	Entity player(defaultPosition, 10, playerSpriteRect, spriteSheet);
	prefabs[0] = player;

	Rectangle spawnPointSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 1);
	Entity spawnPoint(defaultPosition, 10, spawnPointSpriteRect, spriteSheet);
	prefabs[1] = spawnPoint;

	Rectangle MineLayerSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 2);
	Entity mineLayer(defaultPosition, 10, MineLayerSpriteRect, spriteSheet);
	prefabs[2] = mineLayer;

	Rectangle bulletSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 3);
	Entity bullet(defaultPosition, 10, bulletSpriteRect, spriteSheet);
	prefabs[3] = bullet;

	Rectangle floatingMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 4);
	Entity floatingMine(defaultPosition, 10, floatingMineSpriteRect, spriteSheet);
	prefabs[4] = floatingMine;

	Rectangle fireballMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 5);
	Entity fireballMine(defaultPosition, 10, fireballMineSpriteRect, spriteSheet);
	prefabs[5] = fireballMine;

	Rectangle magneticMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 6);
	Entity magneticMine(defaultPosition, 10, magneticMineSpriteRect, spriteSheet);
	prefabs[6] = magneticMine;

	Rectangle magneticFireballMineSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 4, 2, 7);
	Entity magneticFireballMine(defaultPosition, 10, magneticFireballMineSpriteRect, spriteSheet);
	prefabs[7] = magneticFireballMine;
}

void EntityManager::InstantiateEntity(EntityIndexes index, Vector2 position)
{
	int entityIndex = (int)index;

	Entity newEntity(prefabs[entityIndex]);
	newEntity.position = position;

	loadedEntities.push_back(newEntity);
}

void EntityManager::InstantiateEntity(EntityIndexes index, Vector2 position, float rotation)
{
	int entityIndex = (int)index;

	Entity newEntity(prefabs[entityIndex]);
	newEntity.position = position;
	newEntity.rotation = rotation;

	loadedEntities.push_back(newEntity);
}

void EntityManager::DestroyEntity(Entity entity) {}
void EntityManager::UpdateEntities() {} // forEach loop on loadedEntities -> Entity.Update
void EntityManager::DrawEntities() 
{
	for (Entity i : loadedEntities)
	{
		i.Draw();
	}
	
} // forEach loop on loadedEntities -> Entity.Draw