#pragma once
#include <stdbool.h>
#include <raylib.h>

void printV(Vector2 v);
float Norm(Vector2 v);
float SquaredNorm(Vector2 v);
float Distance(Vector2 v1, Vector2 v2);
Vector2 Addition(Vector2 v1, Vector2 v2);
Vector2 Soustraction(Vector2 v1, Vector2 v2);
Vector2 Multiplication(Vector2 v, float scale);
Vector2 Negate(Vector2 v);
float DotProduct (Vector2 v1, Vector2 v2);
Vector2 Rotate(Vector2 v, float angle);
Vector2 Rotate(float angle, Vector2 v, Vector2 origin);
Vector2 Rotate90(Vector2 v);
Vector2 NormalVector(Vector2 v);

Vector2 Normalize (Vector2 v);
Vector2 vector_null();
bool Vector2_Compare(Vector2 v1, Vector2 v2, float epsilon);
float GetPhase(Vector2 v1,Vector2 v2);