#include <raylib.h>
#include <string>
#include "../../headers/gameplay/Physics2D.h"
#include "../../headers/core/Master.h"
#include "../../headers/core/Game.h"


Physics2D* Physics2D::_instance = nullptr;

void Physics2D::InitGrid()
{

	for (int i = 0; i <= Master::windowWidth; i += cellSize)
	{
		for (int j = 0; j <= Master::windowHeight; j += cellSize)
		{
			Cell newCell = Cell{ {(float)i, (float)j} };
			cellGrid[i / cellSize][j / cellSize] = newCell;
		}
	}
}

std::list<Entity*> Physics2D::GetEntityInNeighborCells(Cell c)
{
	std::list<Entity*> entityList;

	int indexX = c.position.x / cellSize;
	int indexY = c.position.y / cellSize;


	//neighbor cells positions
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (indexX + i > 0 && indexY + j > 0 && indexX + i < 7 && indexY + j < 5)
				for (Entity* e : cellGrid[indexX + i][indexY + j].entities)
				{
					entityList.push_back(e);
				}
		}
	}

	return entityList;
}


Cell Physics2D::FindCellAtPos(Vector2 position)
{

	int indexX = position.x / cellSize;
	int indexY = position.y / cellSize;

	return cellGrid[indexX][indexY];
	
}



