#include "Utils.h"
#include <cmath>
#include <vector>
#include <cassert>
#include "RectSideEnum.h"

using namespace std;

bool Utils::IntersectLines(Vector2f start1, Vector2f end1, Vector2f start2, Vector2f end2, Vector2f& res)
{
    double a1 = end1.y - start1.y;
    double b1 = start1.x - end1.x;
    double c1 = a1 * start1.x + b1 * start1.y;

    double a2 = end2.y - start2.y;
    double b2 = start2.x - end2.x;
    double c2 = a2 * start2.x + b2 * start2.y;

    double det = a1 * b2 - a2 * b1;
    if (det == 0)  // lines are parallel
        return false;

    double x = (b2 * c1 - b1 * c2) / det;
    double y = (a1 * c2 - a2 * c1) / det;

    res = Vector2f(x, y);
    return true;
}

bool Utils::IntersectRect(Vector2f start, Vector2f dir, FloatRect rect, RectSide& rectSide)
{
    Vector2f end = start + dir * 2000.f;


    Vector2f a = Vector2f(rect.left, rect.top);
    Vector2f b = Vector2f(rect.left + rect.width, rect.top);
    Vector2f c = Vector2f(rect.left, rect.top + rect.height);
    Vector2f d = Vector2f(rect.left + rect.width, rect.top + rect.height);

    Vector2f zero = Vector2f(0.f,0.f);

    Vector2f pt1 = zero;
    Vector2f pt2  = zero;
    Vector2f pt3  = zero;
    Vector2f pt4  = zero;

    IntersectLines(start, end, a, b, pt1);
    IntersectLines(start, end, a, c, pt2);
    IntersectLines(start, end, b, d, pt3);
    IntersectLines(start, end, c, d, pt4);

    vector<Vector2f> points;

    if(pt1 != zero)
        points.push_back(pt1);

    if(pt2 != zero)
        points.push_back(pt2);

    if(pt3 != zero)
        points.push_back(pt3);

    if(pt4 != zero)
        points.push_back(pt4);

    if(points.size() == 0)
        return false;

    //assert(points.size() == 2);

    Vector2f v1 = points[0] - start;
    Vector2f v2 = points[1] - start;

    if(length(v1) < length(v2))
        rectSide.pt = points[0];
    else
        rectSide.pt = points[1];

    if(rectSide.pt == pt1)
        rectSide.side = RectSideEnum::Top;
    if(rectSide.pt == pt2)
        rectSide.side = RectSideEnum::Left;
    if(rectSide.pt == pt3)
        rectSide.side = RectSideEnum::Right;
    if(rectSide.pt == pt4)
        rectSide.side = RectSideEnum::Bottom;

    return true;
}

float Utils::length(Vector2f vector)
{
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

Vector2f Utils::normalize(Vector2f vector)
{
    return vector / length(vector);
}


