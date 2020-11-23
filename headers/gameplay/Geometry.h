#pragma once
#include <stdbool.h>
#include <raylib.h>


class Segment
{
public :
    Vector2 p1,p2;
    Segment(){}
    Segment(Vector2 p1, Vector2 p2)
    {
        this->p1 = p1;
        this->p2 = p2;
    }
};

class Line
{
public :
    Vector2 point;
    Vector2 vDirecteur;

    Line(){}
    Line(Vector2 vDirecteur, Vector2 point)
    {
        this->vDirecteur = vDirecteur;
        this->point = point;
    }

};

class Circle
{
public :
    Vector2 center;
    float radius;

};

class Box
{
public :
    float width,height;
    Vector2 position; //top Left corner

};
