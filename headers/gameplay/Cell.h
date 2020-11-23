#pragma once
#include <raylib.h>
#include <list>
class Entity;

struct Cell
{
private :
	

public :

	std::list<Entity*> entities;
	std::list<Cell*> neighborCells;
	Vector2 position;
	Cell() = default;
	Cell(Vector2 _position) : position(_position) {}

	void AddEntity(Entity*);
	void RemoveEntity(Entity*);


};