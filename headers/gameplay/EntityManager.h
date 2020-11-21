#pragma once
#include <list>
#include <iostream>
#include <raylib.h>
#include "../entities/Entity.h"

class EntityManager
{
public:

	EntityManager() ;
	~EntityManager();


	void LoadEntitiesReferences();

	Entity* InstantiateEntity(EntityType index, Vector2 position);
	Entity* InstantiateEntity(EntityType index, Vector2 position, float rotation);

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