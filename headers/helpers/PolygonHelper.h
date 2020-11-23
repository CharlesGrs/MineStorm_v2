#pragma once
#include <raylib.h>
#include <list>
#include <iostream>
#include "Geometry.h"


struct VertexInfo
{
	Vector2 coords;
	Vector2 dirToCenter;
	VertexInfo(Vector2 _coords, Vector2 _dirToCenter)
	{
		coords = _coords;
		dirToCenter = _dirToCenter;
	}
};

class PolygonHelper
{
public:
	static Polygon* CalculatePolygonFromImage(Image img, Rectangle spriteRect, float scale);
	static Polygon OffsetPolygon(Polygon p, Vector2 offset);

private:
	bool CompareAngle( const VertexInfo& first, const VertexInfo& second);
};
