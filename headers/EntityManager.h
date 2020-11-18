#pragma once
#include <list>
#include <iostream>
#include <raylib.h>
#include "Entity.h"


enum class EntityIndexes : int
{
	Player = 0,
	SpawnPoint = 1,
	MineLayer = 2,
	Bullet = 3,
	FloatingMine = 4,
	FireballMine = 5,
	MagneticMine = 6,
	MagneticFireballMine = 7
};
class EntityManager
{
public:

	EntityManager() = default;
	EntityManager(Texture);// Load Sprite Atlas in cTor
	~EntityManager()
	{
		FreeBuffers();
	}
	Texture spriteSheet;
	std::list<Entity*>  loadedEntities;
	Entity* prefabs[8];

	void LoadEntitiesReferences();

	void InstantiateEntity(EntityIndexes index, Vector2 position);
	void InstantiateEntity(EntityIndexes index, Vector2 position, float rotation);

	void DestroyEntity(Entity entity);

	void UpdateEntities();
	void DrawEntities();

	void FreeBuffers();
};