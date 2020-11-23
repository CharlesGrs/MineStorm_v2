#pragma once
#include <raylib.h>


class Vector2Helper
{
public:
	static Vector2 Normalize(Vector2 v);
	static Vector2 Substract(Vector2 v1, Vector2 v2);
	static Vector2 Add(Vector2 v1, Vector2 v2);
	static Vector2 Multiply(Vector2 v, float f);
	static Vector2 RotatePoint(float cx, float cy, float angle, Vector2 p);
	static float Norm(Vector2 v);
	static float SquaredNorm(Vector2 v);
	static Vector2 Lerp(Vector2 v1, Vector2 v2, float t);
	static Vector2 AngleToVector2(float angle);
	static float Distance(Vector2 v1, Vector2 v2);
	
	//rest
	static Vector2 vector_null();
	static float DotProduct(Vector2 v1, Vector2 v2);
	static Vector2 NormalVector(Vector2 v);
};