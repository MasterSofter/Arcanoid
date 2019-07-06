//
// Created by Павел on 2019-07-06.
//

#ifndef ARCANOID_BASEENTITYSTATE_H
#define ARCANOID_BASEENTITYSTATE_H

class Entity;

class BaseEntityState {
public:
    BaseEntityState(Entity* parent);
    virtual void draw() = 0;
    virtual void update(sf::Time dt) = 0;

protected:
    Entity* _parent;
};


#endif //ARCANOID_BASEENTITYSTATE_H
