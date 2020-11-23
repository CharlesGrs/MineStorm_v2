#pragma once
#include <stdbool.h>
#include "Geometry.h"

class Range
{
public :
    float min = 0,max = 0;

    Range(){}
    Range(float, float);

};

Range widenRange(Range r, float val);
Range getRange(Range r1, Range r2);
bool rangeInterference(Range r1, Range r2);
bool valueInRange(Range r, float val);

//projections
Range pointToAxes(Vector2 directeur, Vector2 pointPosition);
Range segmentToAxes(Vector2 directeur, Segment s);
Range boxToAxes(Vector2 directeur, Box b);