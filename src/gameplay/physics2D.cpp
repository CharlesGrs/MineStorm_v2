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

	if (Master::debugMode)
		for (size_t i = 0; i < 7; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				float t = cellGrid[i][j]->entities.size() / 10.0f;
				if (t > 1) t = 1;

				Color cellColor;
				cellColor.r = WHITE.r + t * (RED.r - WHITE.r);
				cellColor.g = WHITE.g + t * (RED.g - WHITE.g);
				cellColor.b = WHITE.b + t * (RED.b - WHITE.b);
				cellColor.a = BLACK.b + t * (WHITE.b - BLACK.b);
				DrawRectangleLines(cellGrid[i][j]->position.x, cellGrid[i][j]->position.y, Physics2D::cellSize -5, Physics2D::cellSize -5, cellColor);
			}
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
	if (p2 && p1)
		return (IsSeparatorAxe(p1, p2, o1, o2) && IsSeparatorAxe(p2, p1, o1, o2));
	else return false;
}

bool Physics2D::CollisionSAT(Circle* c, Polygon* p, Vector2 offSet)
{
	Vector2 circleNorm;
	Vector2 scaleNorm;
	Vector2 summit = Vector2Helper::Add(p->vertices.front(), offSet);

	Range    cRange;
	Range    pRange;
	
	Vector2 temp = Vector2Helper::Add(p->vertices.front(), offSet);
	
	for (Vector2 v : p->vertices)
	{
		if (v.x == temp.x && v.y == temp.y)
			continue;

		v = Vector2Helper::Add(v, offSet);

		Vector2 normal = (Vector2Helper::Substract(v, temp));
		normal = Vector2Helper::NormalVector(normal);
	
		scaleNorm = Vector2Helper::Multiply(normal, c->radius);
	
		cRange = { Vector2Helper::DotProduct(Vector2Helper::Substract(c->center,scaleNorm), normal),
						Vector2Helper::DotProduct(Vector2Helper::Add(c->center,scaleNorm), normal) };
	
		pRange = { Vector2Helper::DotProduct(p->vertices.front() ,normal), Vector2Helper::DotProduct(p->vertices.front(),normal) };
	
		for (Vector2 v1 : p->vertices)
		{
			v1 = Vector2Helper::Add(v, offSet);

			pRange = WidenRange(pRange, Vector2Helper::DotProduct(v1, normal));
	
			if (Vector2Helper::SquaredNorm(Vector2Helper::Substract(v1,c->center)) < 
				Vector2Helper::SquaredNorm(Vector2Helper::Substract(summit, c->center)))
				summit = v1;
		}
	
		if (!RangeInterference(pRange,cRange))
			return false;

		temp = v;
	}
	circleNorm = Vector2Helper::Normalize(Vector2Helper::Substract(c->center, summit));

	scaleNorm = Vector2Helper::Multiply(circleNorm, c->radius);
	cRange = { Vector2Helper::DotProduct(Vector2Helper::Substract(c->center,scaleNorm), circleNorm),
						Vector2Helper::DotProduct(Vector2Helper::Add(c->center,scaleNorm), circleNorm) };

	pRange = { Vector2Helper::DotProduct(p->vertices.front(),circleNorm), Vector2Helper::DotProduct(p->vertices.front(),circleNorm) };
	
	for (Vector2 v : p->vertices)
	{
		pRange = WidenRange(pRange, Vector2Helper::DotProduct(v, circleNorm));
	}
	
	if (!RangeInterference(pRange, cRange))
		return false;
	
	return true;
	
}

bool Physics2D::EmergencyCollisionCirclePolygon(Circle* c, Polygon* p, Vector2 offset)
{
	for (Vector2 v : p->vertices)
	{
		if (Vector2Helper::Distance(c->center, Vector2Helper::Add(v, offset)) < c->radius)
			return true;
	}

	return false;
}

bool Physics2D::CollisionCircleCircle(Circle* c1, Circle* c2)
{
	return (Vector2Helper::Distance(c1->center, c2->center) < c1->radius + c2->radius);
	
}