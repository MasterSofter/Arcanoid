//
// Created by Павел on 2019-06-30.
//

#ifndef ARCANOID_RECTSIDE_H
#define ARCANOID_RECTSIDE_H

#include <SFML/Graphics.hpp"
#include "RectSideEnum.h"

using namespace sf;

struct RectSide{
    Vector2f pt;
    RectSideEnum side;
};

#endif //ARCANOID_RECTSIDE_H
