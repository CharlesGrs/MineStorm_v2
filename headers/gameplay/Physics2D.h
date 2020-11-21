#pragma once
#include "Cell.h"

class Physics2D
{
public :

	std::list<Cell> cellGrid;
	static int const cellSize = 20;

	void InitGrid();
	std::list<Entity*> GetEntityInNeighborCells(Cell c);

};