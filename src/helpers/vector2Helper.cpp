#include "..\..\headers\helpers\Vector2Helper.h"
#include <math.h>
#include <cmath>

Vector2 Vector2Helper::Normalize(Vector2 v)
{
	float norm = v.x * v.x + v.y * v.y;
	norm = sqrt(norm);

	if (norm != 0)
	{
		v.x /= norm;
		v.y /= norm;
	}
	else
	{
		v.x = 0;
		v.y = 0;
	}

	return v;
}

Vector2 Vector2Helper::Substract(Vector2 v1, Vector2 v2)
{
	Vector2 result = Vector2{ v1.x - v2.x, v1.y - v2.y };
	return result;
}

Vector2 Vector2Helper::Add(Vector2 v1, Vector2 v2)
{
	return Vector2{ v1.x + v2.x, v1.y + v2.y };
}

Vector2 Vector2Helper::Multiply(Vector2 v, float f)
{
	return Vector2{ v.x * f, v.y * f };
}

Vector2 Vector2Helper::RotatePoint(float cx, float cy, float angle, Vector2 p)
{
	float s = sin(angle);
	float c = cos(angle);

	p.x -= cx;
	p.y -= cy;

	float xnew = p.x * c - p.y * s;
	float ynew = p.x * s + p.y * c;

	p.x = xnew + cx;
	p.y = ynew + cy;
	return p;
}

float Vector2Helper::Magnitude(Vector2 v)
{
	return sqrtf(v.x * v.x + v.y * v.y);
}

Vector2 Vector2Helper::Lerp(Vector2 v1, Vector2 v2, float t)
{
	Vector2 result;
	result.x = v1.x + t * (v2.x - v1.x);
	result.y = v1.y + t * (v2.y - v1.y);
	return result;
}

Vector2 Vector2Helper::AngleToVector2(float angle)
{
	Vector2 result;
	result.x = sin((double)angle * DEG2RAD);
	result.y = cos((double)angle * DEG2RAD);
	return result;
}
