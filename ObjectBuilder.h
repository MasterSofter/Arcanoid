//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_OBJECTBUILDER_H
#define ARCANOID_OBJECTBUILDER_H

#include "Object.h"
class ObjectBuilder{
public:
    Object* createBackground();
    Object* createIce();
    Object* createBall();
    Object* createPlatform();
};
#endif //ARCANOID_OBJECTBUILDER_H
