#include <raylib.h>
#include <string>
#include "../../headers/gameplay/Cell.h"

void Cell::AddEntity(Entity* e)
{
	entities.push_back(e);
}

void Cell::RemoveEntity(Entity* entity)
{
	entities.remove(entity);
}

std::list<Entity*> Cell::GetEntities()
{
	return entities;
}

