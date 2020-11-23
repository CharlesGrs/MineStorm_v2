#pragma once
#include <stdbool.h>
#include <raylib.h>
#include <list>

struct Shape {
	virtual void f() {}
};

struct Circle : Shape
{
	Vector2 center;
	float radius;
	Circle(float _radius, Vector2 _center) : radius(_radius), center(_center) {}
};

struct Polygon : Shape
{
	std::list<Vector2> vertices;

	Polygon(std::list<Vector2> _vertices)
	{
		if (_vertices.size() == 0)
			throw "Polygon vertices is empty";
		vertices = _vertices;
	}
};