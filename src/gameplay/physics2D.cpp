#include <raylib.h>
#include <string>
#include "../../headers/gameplay/Physics2D.h"
#include "../../headers/gameplay/Vector2.h"
#include "../../headers/gameplay/Range.h"
#include "../../headers/core/Master.h"
#include "../../headers/core/Game.h"


Physics2D::Physics2D()
{
	InitGrid();
}

Physics2D::~Physics2D()
{
	FreeGrid();
}

void Physics2D::InitGrid()
{
	for (int i = 0; i <= Master::windowWidth; i += cellSize)
	{
		for (int j = 0; j <= Master::windowHeight; j += cellSize)
		{
			Cell* newCell = new Cell{ {(float)i, (float)j} };
			cellGrid[i / cellSize][j / cellSize] = newCell;
		}
	}
}

void Physics2D::FreeGrid()
{
	for (int i = 0; i <= Master::windowWidth; i += cellSize)
	{
		for (int j = 0; j <= Master::windowHeight; j += cellSize)
		{
			delete cellGrid[i / cellSize][j / cellSize];
		}
	}
}

std::list<Entity*> Physics2D::GetEntityInNeighborCells(Cell* c)
{
	std::list<Entity*> entityList;

	int indexX = c->position.x / cellSize;
	int indexY = c->position.y / cellSize;

	//neighbor cells positions
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (indexX + i >= 0 && indexY + j >= 0 && indexX + i < 7 && indexY + j < 5)
				for (Entity* e : cellGrid[indexX + i][indexY + j]->entities)
				{
					entityList.push_back(e);
				}
		}
	}

	return entityList;
}


Cell* Physics2D::FindCellAtPos(Vector2 position)
{
	int indexX = position.x / cellSize;
	int indexY = position.y / cellSize;

	return cellGrid[indexX][indexY];
}

//Collision

bool IsSeparatorAxe(Polygon p1, Polygon p2)
{
	Vector2 temp = p1.vertices.back();

	for (Vector2 v : p1.vertices)
	{
		Vector2 normal = (Soustraction(v, temp));
		normal = NormalVector(normal);

		Range p1Range = { DotProduct(p1.vertices.front(),normal), DotProduct(p1.vertices.front(),normal) };
		Range p2Range = { DotProduct(p2.vertices.front(),normal), DotProduct(p2.vertices.front(),normal) };

		for (Vector2 v1 : p1.vertices)
		{
			p1Range = WidenRange(p1Range, DotProduct(v1, normal));
		}

		for (Vector2 v2 : p2.vertices)
		{
			p2Range = WidenRange(p2Range, DotProduct(v2, normal));
		}

		if (!RangeInterference(p1Range, p2Range))
			return false;

		temp = v;

	}

	return true;
}

bool CollisionSAT(Polygon p1, Polygon p2)
{
	return (IsSeparatorAxe(p1, p2) && IsSeparatorAxe(p2, p1));
}

