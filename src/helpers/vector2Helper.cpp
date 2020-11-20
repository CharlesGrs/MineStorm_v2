#include "..\..\headers\helpers\Vector2Helper.h"
#include <math.h>

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
