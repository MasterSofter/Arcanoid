#ifndef ARCANOID_UTILS_H
#define ARCANOID_UTILS_H

#include <SFML/Graphics.hpp>
#include "RectSide.h"

using namespace sf;

class Utils {
public:
    static  bool IntersectLines(Vector2f start1, Vector2f end1, Vector2f start2, Vector2f end2,Vector2f& res);
    static  bool IntersectRect(Vector2f start, Vector2f dir, FloatRect rect, RectSide& rectSide);
    static  float length(Vector2f vector);
    static  Vector2f normalize(Vector2f vector);

    /// Скалярное произведение векторов
    static  float ScalarProduct(Vector2f u, Vector2f v);
};


#endif //ARCANOID_UTILS_H
