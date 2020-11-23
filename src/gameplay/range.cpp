#include <math.h>
#include <stdio.h>
#include "../../headers/gameplay/Range.h"


Range::Range(float min, float max)
{
    this -> min = min;
    this -> max = max;
}

Range getRange(Range r1, Range r2)
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

Range widenRange(Range r, float val)
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

bool rangeInterference(Range r1, Range r2)
{
    if (r1.min > r2.max || r2.min > r1.max)
        return false;
    else 
        return true;
}

bool valueInRange(Range r, float val)
{
    if (val >= r.min && val <= r.max)
        return true;
    else 
        return false;
}

//projections

Range pointToAxes(Vector2 directeur, Vector2 pointPosition)
{
    Range r;
    float projectionVal = Vector2Helper::DotProduct(directeur,pointPosition);
    r = {projectionVal, projectionVal};

    return r;

}

Range segmentToAxes(Vector2 directeur, Segment s)
{
    Range r;
    float val1 = Vector2Helper::DotProduct(directeur, s.p1);
    float val2 = Vector2Helper::DotProduct(directeur,s.p2);

    widenRange(r, val1);
    widenRange(r, val2);

    return r;
}

Range boxToAxes(Vector2 directeur, Box b)
{
    Range r;
    float val1, val2, val3, val4;
    Vector2 currentPoint = b.position;

    val1 = Vector2Helper::DotProduct(directeur, currentPoint);

    currentPoint.x += b.width;
    val2 = Vector2Helper::DotProduct(directeur, currentPoint);

    currentPoint.y += b.height;
    val3 = Vector2Helper::DotProduct(directeur, currentPoint);

    currentPoint.x -= b.width;
    val4 = Vector2Helper::DotProduct(directeur, currentPoint);

    widenRange(r, val1);
    widenRange(r, val2);
    widenRange(r, val3);
    widenRange(r, val4);

    return r;
}
