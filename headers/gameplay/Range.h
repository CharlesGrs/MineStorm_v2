#pragma once
#include <stdbool.h>
#include "../helpers/Geometry.h"
#include "../helpers/Vector2Helper.h"

class Range
{
public :
    float min = 0,max = 0;

    Range(){}
    Range(float, float);

};

Range WidenRange(Range r, float val);
Range GetRange(Range r1, Range r2);
bool RangeInterference(Range r1, Range r2);
bool IsValueInRange(Range r, float val);

//projections
Range PointToAxes(Vector2 directeur, Vector2 pointPosition);
