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
    int GameField_01[8][8]{
            2,1,1,1,1,1,1,1,
            2,1,0,0,0,0,1,1,
            2,0,1,2,2,1,0,1,
            2,0,2,1,1,2,0,1,
            2,0,2,1,1,2,0,1,
            2,0,1,2,2,1,0,1,
            2,1,0,0,0,0,1,1,
            2,1,1,1,1,1,1,1
    };

    int GameField_02[8][8]{
            1,1,1,1,1,1,1,1,
            1,1,2,2,2,2,1,1,
            0,0,0,0,0,0,0,1,
            1,0,2,1,1,2,0,1,
            1,0,2,1,1,2,0,1,
            0,0,0,0,0,0,0,1,
            1,1,2,2,2,2,1,1,
            1,1,1,1,1,1,1,1
    };

    const int iceObj = 0;
    const int gnomIceObj = 1;

public:
    GameBuilder(Vector2f origin, Vector2f size);
    void  BuildObjectList(list<Entity*>& list);
    void DeleteObject(list<Entity*>::iterator& it);
    void PlaceEntitys(list<Entity*>& list, Entity* ice[8][8],Entity* gnomIce[8][8], int gamefield[8][8]);


};


#endif //ARCANOID_GAMEBUILDER_H
