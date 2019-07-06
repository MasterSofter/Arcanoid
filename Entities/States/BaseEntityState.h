//
// Created by Павел on 2019-07-06.
//

#ifndef ARCANOID_BASEENTITYSTATE_H
#define ARCANOID_BASEENTITYSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "../../EnumTexture.h"
#include "EnumStates.h"

using namespace sf;

class Entity;

class BaseEntityState {
    EnumStates _nextState;

public:
    BaseEntityState(Entity* parent, EnumTexture enumTexture, EnumStates nextState);
    virtual void draw(RenderWindow& wnd);
    virtual void update(sf::Time dt) = 0;
    virtual bool exist() const;
    virtual void setPosition(Vector2f pos);
    virtual Vector2f getPosition() const;
    virtual void attack();

protected:
    Entity* _parent;
    Sprite _sprite;
    int _health;
};


#endif //ARCANOID_BASEENTITYSTATE_H
