#include <math.h>
#include <stdio.h>
#include "../../headers/gameplay/Range.h"


Range::Range(float min, float max)
{
    this -> min = min;
    this -> max = max;
}

Range GetRange(Range r1, Range r2)
{
    Range r;

    if (r1.min < r2.min)
        r.min = r1.min;
    else
        r.min = r2.min;

    if (r1.max > r2.max)
        r.max = r1.max;
    else
        r.max = r2.max;

    return r;
    
}

Range WidenRange(Range r, float val)
{
    Range res;
    if (r.min > val)
        res.min = val;
    else
        res.min = r.min;

    if (r.max < val)
        res.max = val;
    else
        res.max = r.max;

    return res;
}

bool RangeInterference(Range r1, Range r2)
{
    if (r1.min > r2.max || r2.min > r1.max)
        return false;
    else 
        return true;
}

bool IsValueInRange(Range r, float val)
{
    if (val >= r.min && val <= r.max)
        return true;
    else 
        return false;
}

//projections

Range PointToAxes(Vector2 directeur, Vector2 pointPosition)
{
    Range r;
    float projectionVal = Vector2Helper::DotProduct(directeur,pointPosition);
    r = {projectionVal, projectionVal};

    return r;

}