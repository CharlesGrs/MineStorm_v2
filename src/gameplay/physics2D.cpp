#include <raylib.h>
#include <string>
#include <limits>
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


bool Physics2D::IsSeparatorAxe(Polygon* p1, Polygon* p2, Vector2 o1, Vector2 o2)
{
	Vector2 temp = Vector2Helper::Add(p1->vertices.back(), o1);

	for (Vector2 v : p1->vertices)
	{
		v = Vector2Helper::Add(v, o1);
		Vector2 normal = (Vector2Helper::Substract(temp, v));
		normal = Vector2Helper::NormalVector(normal);

		Range p1Range = { std::numeric_limits<float>::max(), std::numeric_limits<float>::min() };
		Range p2Range = { std::numeric_limits<float>::max(), std::numeric_limits<float>::min() };

		for (Vector2 v1 : p1->vertices)
		{
			v1 = Vector2Helper::Add(v1, o1);
			p1Range = WidenRange(p1Range, Vector2Helper::DotProduct(normal, v1));
		}

		for (Vector2 v2 : p2->vertices)
		{
			v2 = Vector2Helper::Add(v2, o2);
			p2Range = WidenRange(p2Range, Vector2Helper::DotProduct(normal, v2));
		}

		if (!RangeInterference(p1Range, p2Range))
			return false;

		temp = v;
	}

	return true;
}

bool Physics2D::CollisionSAT(Polygon* p1, Polygon* p2, Vector2 o1, Vector2 o2)
{
	return (IsSeparatorAxe(p1, p2, o1, o2) && IsSeparatorAxe(p2, p1, o1, o2));
}

bool Physics2D::CollisionSAT(Circle c, Polygon p, Vector2 offSet)
{

	//Vector2 summit = cp.pointsList[0];
	//Vector2 normCircle;
	//Vector2 scaleNorm;
	//Range    circleRange;
	//Range    cpRange;
	//
	//Vector2 temp = Vector2Helper::Add(p.vertices.back(), offSet);
	//
	//for (Vector2 v : p.vertices)
	//{
	//	Vector2 normal = (Vector2Helper::Substract(temp, v));
	//	normal = Vector2Helper::NormalVector(normal);
	//
	//	scaleNorm = Vector2Helper::Multiply(normal, c.radius);
	//
	//	circleRange = { Vector2Helper::DotProduct(Vector2Helper::Substract(c.center,scaleNorm), normal),
	//					Vector2Helper::DotProduct(Vector2Helper::Add(c.center,scaleNorm), normal) };
	//
	//	cpRange = { cp.pointsList[0].dotProduct(norm), cp.pointsList[0].dotProduct(norm) };
	//
	//	for (int j = 1; j < cp.nbPoint; j++)
	//	{
	//		cpRange = cpRange.valueInRange(cp.pointsList[j].dotProduct(norm));
	//
	//		if ((cp.pointsList[j] - circle.center).squareLength() < (summit - circle.center).squareLength())
	//			summit = cp.pointsList[j];
	//	}
	//
	//	if (!cpRange.intersectRange(circleRange))
	//		return false;
	//}
	//
	//normCircle = (circle.center - summit).normalized();
	//scaleNorm = normCircle * circle.radius;
	//circleRange = { (circle.center - scaleNorm).dotProduct(normCircle), (circle.center + scaleNorm).dotProduct(normCircle) };
	//cpRange = { cp.pointsList[0].dotProduct(normCircle), cp.pointsList[0].dotProduct(normCircle) };
	//
	//for (int i = 1; i < cp.nbPoint; i++)
	//{
	//	cpRange = cpRange.valueInRange(cp.pointsList[i].dotProduct(normCircle));
	//}
	//
	//if (!cpRange.intersectRange(circleRange))
	//	return false;
	//
	return true;
	
}