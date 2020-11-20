#pragma once
#include <list>
#include <iostream>
#include <raylib.h>
#include "../entities/Entity.h"


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
	~EntityManager();
	EntityManager(Texture);// Load Sprite Atlas in cTor

	void LoadEntitiesReferences();

	Entity* InstantiateEntity(EntityIndexes index, Vector2 position);
	Entity* InstantiateEntity(EntityIndexes index, Vector2 position, float rotation);

	int entityAmount() 
	{
		return loadedEntities.size();
	}

	void DestroyEntity(Entity* entity);
	void UpdateEntities();
	void DrawEntities();
	void FreeBuffers();

private:
	std::list<Entity*>  loadedEntities;
	std::list<Entity*> entitiesToDestroy;
	Entity* prefabs[8];
	Texture spriteSheet;

};