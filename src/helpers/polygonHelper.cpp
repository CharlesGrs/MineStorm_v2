#include "..\..\headers\helpers\PolygonHelper.h"
#include <list>
#include <iostream>
#include <tgmath.h >
#include <raylib.h>
#include "..\..\headers\helpers\Vector2Helper.h"


struct VertexInfoComparator
{
	bool operator ()(const VertexInfo& first, const VertexInfo& second)
	{
		float firstAngle = atan2(first.dirToCenter.y, first.dirToCenter.x);
		float secondAngle = atan2(second.dirToCenter.y, second.dirToCenter.x);

		return firstAngle < secondAngle;
	}
};

bool PolygonHelper::CompareAngle(const VertexInfo& first, const VertexInfo& second)
{
	float firstAngle = atan2(first.dirToCenter.y, first.dirToCenter.x);
	float secondAngle = atan2(second.dirToCenter.y, second.dirToCenter.x);

	if (firstAngle < secondAngle) return true;
	else if (firstAngle > secondAngle) return false;
}

Polygon PolygonHelper::CalculatePolygonFromImage(Image collisionImage, Rectangle spriteRect, float scale)
{
	Vector4* rawData = GetImageDataNormalized(collisionImage);
	std::list<VertexInfo> verticesInfo;

	Vector2 spriteCenter = Vector2{ (spriteRect.x + spriteRect.width) / 2 ,(spriteRect.y + spriteRect.height) / 2 };

	for (size_t x = spriteRect.x; x < spriteRect.x + spriteRect.width; x++)
		for (size_t y = spriteRect.y; y < spriteRect.y + spriteRect.height; y++)
			if (rawData[y * collisionImage.width + x].w > 0)
			{
				Vector2 coords = Vector2{ x - spriteRect.x,y - spriteRect.y };
				Vector2 dirToCenter = Vector2Helper::Normalize(Vector2Helper::Substract(coords, spriteCenter));
				verticesInfo.push_back(VertexInfo{ coords, dirToCenter });
			}

	verticesInfo.sort(VertexInfoComparator());
	std::list<Vector2> vertices;
	for (VertexInfo v : verticesInfo)
		vertices.push_back(Vector2{ (v.coords.x ) * scale, (v.coords.y ) * scale });

	return Polygon(vertices);
}

Polygon PolygonHelper::OffsetPolygon(Polygon p, Vector2 offset)
{
	Polygon res = p;
	for (std::list<Vector2>::iterator it = res.vertices.begin(); it != res.vertices.end(); ++it)
	{
		it->x += offset.x;
		it->y += offset.y;
	}

	return res;
}
