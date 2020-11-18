#include "../headers/EntityManager.h"
#include <raylib.h>

void EntityManager::LoadEntitiesReferences()
{
	// Calculate rectSize
	// Give them all the correct rect
	// Populate the prefabs array accordingly to the EntityIndexes order
	// Done.
}

void EntityManager::InstantiateEntity(EntityIndexes index)
{
	// Copy Entity from Entity Array "Prefabs" according to the EntityIndex given.
	// Then push_back the Entity in the loadedEntities

#pragma region Debug
	Vector2 position;
	position.x = 0;
	position.y = 0;
	Rectangle spriteRect;
	spriteRect.width = 100;
	spriteRect.height = 100;

	Entity newEntity = Entity(position, 10, spriteRect, spriteSheet);

#pragma endregion

	loadedEntities.push_back(newEntity);
}

void EntityManager::DestroyEntity(Entity entity) {}
void EntityManager::UpdateEntities() {} // forEach loop on loadedEntities -> Entity.Update
void EntityManager::DrawEntities() {} // forEach loop on loadedEntities -> Entity.Draw