#pragma once
#include "../helpers/PolygonHelper.h"

enum class HitboxType 
{
	Circle,
	Polygon
};

struct Hitbox 
{
	Hitbox(HitboxType _hitbox, Shape* _shape)
	{
		type = _hitbox;
		shape = _shape;
		offset = Vector2{ 0,0 };
	}
	Vector2 offset;
	HitboxType type;
	Shape* shape;
};