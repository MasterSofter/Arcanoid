//
// Created by Павел on 2019-06-23.
//

#ifndef ARCANOID_GAMEBUILDER_H
#define ARCANOID_GAMEBUILDER_H

#include <list>
#include "Entity.h"

using namespace std;

class GameBuilder {
    Vector2f _origin;
    Vector2f _size;

public:
    GameBuilder(Vector2f origin, Vector2f size);
    void  BuildObjectList(list<Entity*>& list);

};


#endif //ARCANOID_GAMEBUILDER_H
