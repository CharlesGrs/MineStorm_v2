#pragma once
#include <raylib.h>


class Vector2Helper
{
public:
	static Vector2 Normalize(Vector2 v);
	static Vector2 Substract(Vector2 v1, Vector2 v2);

	static Vector2 RotatePoint(float cx, float cy, float angle, Vector2 p);

};