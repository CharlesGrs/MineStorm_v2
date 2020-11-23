#pragma once
#include "Cell.h"
#include "../helpers/PolygonHelper.h"

class Physics2D
{
	static Physics2D* _instance;

public:

	static Physics2D* instance()
	{
		if (!_instance)
		{
			_instance = new Physics2D();
		}
		return _instance;
	}

	~Physics2D()
	{
		delete _instance;
	}

	Physics2D()
	{
		InitGrid();
	}

	Cell cellGrid[7][5];
	static int const cellSize = 160;

	void InitGrid();
	std::list<Entity*> GetEntityInNeighborCells(Cell c);
	Cell FindCellAtPos(Vector2 position);

};

bool CollisionSAT(Polygon p1, Polygon p2);