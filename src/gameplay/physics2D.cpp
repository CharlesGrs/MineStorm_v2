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

bool Physics2D::IsSeparatorAxe(Entity* e1, Entity* e2)
{
	Polygon p1 = Physics2D::OffsetPolygon(e1->hitbox, e1->position);
	Polygon p2 = Physics2D::OffsetPolygon(e2->hitbox, e2->position);

	Vector2 temp = p1.vertices.back();

	for (Vector2 v : p1.vertices)
	{
		Vector2 normal = (Vector2Helper::Substract(temp, v));
		normal = Vector2Helper::NormalVector(normal);

		Range p1Range = { Vector2Helper::DotProduct(p1.vertices.front(),normal), Vector2Helper::DotProduct(p1.vertices.front(),normal) };
		Range p2Range = { Vector2Helper::DotProduct(p2.vertices.front(),normal), Vector2Helper::DotProduct(p2.vertices.front(),normal) };

		for (Vector2 v1 : p1.vertices)
		{
			p1Range = WidenRange(p1Range, Vector2Helper::DotProduct(normal, v1));
		}

		for (Vector2 v2 : p2.vertices)
		{
			p2Range = WidenRange(p2Range, Vector2Helper::DotProduct(normal, v2));
		}

		if (!RangeInterference(p1Range, p2Range))
			return false;

		temp = v;

	}

	return true;
}

bool Physics2D::CollisionSAT(Entity* e1, Entity* e2)
{
	return (IsSeparatorAxe(e1, e2) && IsSeparatorAxe(e2, e1));
}

Polygon Physics2D::OffsetPolygon(Polygon p, Vector2 pos)
{
	Polygon res = p;
	for (std::list<Vector2>::iterator it = res.vertices.begin(); it != res.vertices.end(); ++it)
	{
		it->x += pos.x;
		it->y += pos.y;
	}

	return res;
}