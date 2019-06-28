//
// Created by Павел on 2019-06-23.
//

#include "GameBuilder.h"
#include "ObjectBuilder.h"

GameBuilder::GameBuilder(Vector2f origin, Vector2f size)
    : _origin(origin),
      _size(size)
{

}

void GameBuilder::BuildObjectList(list<Entity*>& list)
{
    Entity* ice[8][8];
    Entity* gnomIce[8][8];
    ObjectBuilder objectBuilder;

    float deltaX = _size.x / 8;
    float deltaY = _size.y / 8;
    float dx = deltaX - 10;
    float dy = deltaY - 10;

    Vector2f position = _origin;

    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {

            ice[j][i] = objectBuilder.CreateObject(iceObj,0,position,Vector2f(dx, dy));
            gnomIce[j][i] = objectBuilder.CreateObject(gnomIceObj,0,position,Vector2f(dx, dy));
            ice[j][i]->move(Vector2f(5,5));
            gnomIce[j][i]->move(Vector2f(5,5));

            position.x += deltaX;
        }

        position.x = _origin.x;
        position.y += deltaY;
    }


    PlaceEntitys(list, ice, gnomIce, GameField_01);
}

void GameBuilder::PlaceEntitys(list<Entity*>& list,Entity* ice[8][8],Entity* gnomIce[8][8],int (*gamefield)[8]) {
    for(int i = 0 ; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            if(gamefield[i][j] == 1)
                list.push_back(ice[j][i]);
            else if(gamefield[i][j] == 2)
            {
                list.push_back(gnomIce[i][j]);
            }
    }
}

