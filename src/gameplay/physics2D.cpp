#include <raylib.h>
#include <string>
#include "../../headers/gameplay/Physics2D.h"
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
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cellGrid[i][j]->neighborCells = GetNeighborCells(cellGrid[i][j]);
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

void Physics2D::Update()
{
	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			cellGrid[i][j]->entities.clear();
		}
	}

	for (Entity* e : Game::entityManager()->loadedEntities)
	{
		FindCellAtPos(e->position)->AddEntity(e);
	}
}

std::list<Cell*> Physics2D::GetNeighborCells(Cell* c)
{
	std::list<Cell*> cellList;

	int indexX = c->position.x / cellSize;
	int indexY = c->position.y / cellSize;

	//neighbor cells positions
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (indexX + i >= 0 && indexY + j >= 0 && indexX + i < 7 && indexY + j < 5)
				cellList.push_back(cellGrid[indexX + i][indexY + j]);
		}
	}

	return cellList;
}

Cell* Physics2D::FindCellAtPos(Vector2 position)
{
	int indexX = position.x / cellSize;
	int indexY = position.y / cellSize;

	return cellGrid[indexX][indexY];
}

bool IsSeparatorAxe(Polygon p1, Polygon p2)
{
	Vector2 temp = p1.vertices.back();

	for (Vector2 v : p1.vertices)
	{
		Vector2 normal = (Vector2Helper::Substract(v, temp));
		normal = Vector2Helper::NormalVector(normal);

		Range p1Range = { Vector2Helper::DotProduct(p1.vertices.front(),normal), Vector2Helper::DotProduct(p1.vertices.front(),normal) };
		Range p2Range = { Vector2Helper::DotProduct(p2.vertices.front(),normal), Vector2Helper::DotProduct(p2.vertices.front(),normal) };

		for (Vector2 v1 : p1.vertices)
		{
			p1Range = WidenRange(p1Range, Vector2Helper::DotProduct(v1, normal));
		}

		for (Vector2 v2 : p2.vertices)
		{
			p2Range = WidenRange(p2Range, Vector2Helper::DotProduct(v2, normal));
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

