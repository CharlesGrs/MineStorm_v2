#include <math.h>
#include <stdio.h>
#include "../../headers/gameplay/Vector2.h"



Vector2 vector_null()
{
	Vector2 vect = { 0,0 };
	return vect;
}

void printV(Vector2 v)
{
	printf("x : %f\ty : %f\n", v.x, v.y);
}

Vector2 Normalize(Vector2 v)
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

bool Vector2_Compare(Vector2 v1, Vector2 v2, float epsilon)
{
	if (v1.x >= v2.x - epsilon && v1.x <= v2.x + epsilon)
	{
		if (v1.y >= v2.y - epsilon && v1.y <= v2.y + epsilon)
			return true;
	}

	return false;
}

float Norm(Vector2 v)
{
	float norm = v.x * v.x + v.y * v.y;
	return sqrt(norm);
}

float SquaredNorm(Vector2 v)
{
	return v.x * v.x + v.y * v.y;
}

float Distance(Vector2 v1, Vector2 v2)
{
	float diffx = (v1.x - v2.x);
	float diffy = (v1.y - v2.y);

	float dist = diffx * diffx + diffy * diffy;

	return sqrt(dist);
}

Vector2 Addition(Vector2 v1, Vector2 v2)
{
	return Vector2{ v1.x + v2.x, v1.y + v2.y };
}

Vector2 Soustraction(Vector2 v1, Vector2 v2)
{
	return Vector2{ v1.x - v2.x, v1.y - v2.y };
}

Vector2 Multiplication(Vector2 v, float scale)
{
	return Vector2{ scale * v.x, scale * v.y };
}

Vector2 Negate(Vector2 v)
{
	return Vector2{ -v.x,-v.y };
}

float DotProduct(Vector2 v1, Vector2 v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

float GetPhase(Vector2 v1, Vector2 v2)
{
	float dotProduct = DotProduct(v1, v2);
	float norms = Norm(v1) * Norm(v2);

	if (norms == 0)
		return 0;

	float cosPhase = dotProduct / norms;

	return acos(cosPhase);
}

Vector2 Rotate(Vector2 v, float angle)
{
	float x2, y2;

	x2 = cos(angle) * v.x - sin(angle) * v.y;
	y2 = sin(angle) * v.x + cos(angle) * v.y;

	v.x = x2;
	v.y = y2;

	return v;
}

Vector2 Rotate(float angle, Vector2 v, Vector2 origin)
{
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	v.x -= origin.x;
	v.y -= origin.y;

	// rotate point
	float xnew = v.x * c - v.y * s;
	float ynew = v.x * s + v.y * c;

	// translate point back:
	v.x = xnew + origin.x;
	v.y = ynew + origin.y;

	return Vector2{ v.x,v.y };

}

Vector2 Rotate90(Vector2 v)
{
	return Rotate(v, 90);
}

Vector2 NormalVector(Vector2 v)
{
	float newX = -v.y;
	float newY = v.x;

	return Vector2{ newX,newY };
}