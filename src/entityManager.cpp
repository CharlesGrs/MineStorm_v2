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

	Rectangle playerSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 2, 8, 1);
	Entity Player(defaultPosition, 10, playerSpriteRect, spriteSheet);
	prefabs[0] = Player;

	Rectangle bulletSpriteRect = SpriteHelper::GetSpriteRectangle(spriteSheet, 2, 8, 2);
	Entity Bullet(defaultPosition, 10, bulletSpriteRect, spriteSheet);
	prefabs[1] = Bullet;
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