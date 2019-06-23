//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_CELL_H
#define ARCANOID_CELL_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "Entity.h"
struct Cell{
    float pointX;
    float pointY;
    Entity object;
};
#endif //ARCANOID_CELL_H
