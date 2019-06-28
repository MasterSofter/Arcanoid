//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_OBJECTBUILDER_H
#define ARCANOID_OBJECTBUILDER_H

#include "Entity.h"
class ObjectBuilder{
     int iceObj = 0;
     int gnomIceObj = 1;
public:
    Entity* createBackground();
    Entity* createIce(int id);
    Entity* createBall();
    Entity* createPlayer();
    Entity* createRoad();
    Entity* CreateObject(int object, int id,Vector2f pos, Vector2f size);
    Entity* createGnomIce(int id);


};
#endif //ARCANOID_OBJECTBUILDER_H
