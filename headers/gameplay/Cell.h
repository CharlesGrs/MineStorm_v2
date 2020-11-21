#pragma once
#include "../entities/Entity.h"

struct Cell
{
private :
	std::list<Entity*> entities;
	

public :

	Vector2 position;
	Cell(Vector2 _position) : position(_position) {}

	void AddEntity(Entity*);
	void RemoveEntity(Entity*);
	std::list<Entity*> GetEntities();

};