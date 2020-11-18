#pragma once
#include <list>
#include <iostream>
#include <raylib.h>
#include "Entity.h"


enum class EntityIndexes : int
{
	Player = 0,
	Bullet = 1
};
class EntityManager
{
public:

	EntityManager() = default;
	EntityManager(Texture);// Load Sprite Atlas in cTor

	Texture spriteSheet;
	std::list<Entity>  loadedEntities;
	Entity prefabs[6];

	void LoadEntitiesReferences();

	void InstantiateEntity(EntityIndexes index, Vector2 position);
	void InstantiateEntity(EntityIndexes index, Vector2 position, float rotation);

	void DestroyEntity(Entity entity);

	void UpdateEntities();
	void DrawEntities();
};