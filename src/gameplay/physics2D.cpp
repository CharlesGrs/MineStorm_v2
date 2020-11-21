#include <raylib.h>
#include <string>
#include "../../headers/gameplay/Physics2D.h"
#include "../../headers/gameplay/World.h"


Physics2D* Physics2D::_instance = nullptr;

void Physics2D::InitGrid()
{
	int CellPerRow = World::windowWidth / cellSize;
	int cellPerColumn = World::windowHeight / cellSize;

	for (int i = 0; i <= CellPerRow; i++)
	{
		for (int j = 0; j <= cellPerColumn; j++)
		{
			Cell newCell = Cell{ {(float)i* cellSize, (float)j * cellSize} };
			cellGrid.push_back(newCell);
		}
	}
}

std::list<Entity*> Physics2D::GetEntityInNeighborCells(Cell c)
{
	std::list<Cell> cells;
	std::list<Entity*> list;
	std::list<Entity*> temp;

	//neighbor cells positions
	Vector2 neighborPositions[8] = { 
		//first top row
		Vector2{c.position.x - cellSize,c.position.y - cellSize},
		Vector2{c.position.x		   ,c.position.y - cellSize},
		Vector2{c.position.x + cellSize,c.position.y - cellSize},

		//second row 
		Vector2{c.position.x - cellSize,c.position.y},
		Vector2{c.position.x + cellSize,c.position.y},
		
		//third row
		Vector2{c.position.x - cellSize,c.position.y + cellSize},
		Vector2{c.position.x			,c.position.y + cellSize},
		Vector2{c.position.x + cellSize,c.position.y + cellSize},

	};

	cells.push_back(c);

	//get neighbor cells in cells
	for (Cell c : cellGrid)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((c.position.x == neighborPositions[i].x) && (c.position.y == neighborPositions[i].y))
				cells.push_back(c);
		}
	}

	//for each in cells -> add c entities in total list
	for (Cell c : cells)
	{
		temp = c.GetEntities();
		for (Entity* e : temp)
		{
			list.push_back(e);
		}
	}


	return list;
}


Cell Physics2D::FindCellAtPos(Vector2 position)
{
	for (Cell c : cellGrid)
	{
		bool checkX = position.x >= c.position.x && position.x < c.position.x + cellSize;
		bool checkY = position.y >= c.position.y && position.y < c.position.y + cellSize;

		if (checkX && checkY)
			return c;
	}

	return Cell();
}

void Physics2D::DrawGrid()
{
	int i = 0;
	for (Cell c : cellGrid)
	{
		if (i % 3 == 0)
			DrawRectangleLines(c.position.x, c.position.y, cellSize, cellSize, WHITE);
		else if (i % 3 == 1)
			DrawRectangleLines(c.position.x, c.position.y, cellSize, cellSize, RED);
		else 
			DrawRectangleLines(c.position.x, c.position.y, cellSize, cellSize, BLUE);

		i++;
	}
}


