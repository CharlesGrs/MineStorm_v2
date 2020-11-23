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
	void Update();
	std::list<Cell*> GetNeighborCells(Cell* c);
	Cell* FindCellAtPos(Vector2 position);
	
	static bool CollisionSAT(Entity* p1, Entity* p2);
	static bool IsSeparatorAxe(Entity* p1, Entity* p2);
	static Polygon OffsetPolygon(Polygon p, Vector2 pos);

};

