#pragma once
#include "Cell.h"
#include "../helpers/PolygonHelper.h"

class Physics2D
{

public:

	Physics2D();
	~Physics2D();

	Cell* cellGrid[7][5];
	static int const cellSize = 160;

	void InitGrid();
	void FreeGrid();
	std::list<Entity*> GetEntityInNeighborCells(Cell* c);
	Cell* FindCellAtPos(Vector2 position);
	
	bool CollisionSAT(Entity* p1, Entity* p2);
	bool IsSeparatorAxe(Entity* p1, Entity* p2);
	Polygon OffsetPolygon(Polygon p, Vector2 pos);

};

