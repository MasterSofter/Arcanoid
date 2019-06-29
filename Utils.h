#ifndef ARCANOID_UTILS_H
#define ARCANOID_UTILS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Utils {
public:
    static  bool IntersectLines(Vector2f start1, Vector2f end1, Vector2f start2, Vector2f end2, Vector2f& res);
    static  bool IntersectRect(Vector2f start, Vector2f dir, FloatRect rect, Vector2f& pt);
    static  float length(Vector2f vector);
    static  Vector2f normalize(Vector2f vector);
};


#endif //ARCANOID_UTILS_H
