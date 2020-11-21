#pragma once
#include "Cell.h"

class Physics2D
{
	static Physics2D* _instance;

public :

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
	
	std::list<Cell> cellGrid;
	static int const cellSize = 160;

	void InitGrid();
	void DrawGrid();
	std::list<Entity*> GetEntityInNeighborCells(Cell c);
	Cell FindCellAtPos(Vector2 position);

};