//
// Created by Павел on 2019-07-06.
//

#include "EntityAliveState.h"
#include "../Entity.h"

EntityAliveState::EntityAliveState(Entity* parent, EnumTexture enumTexture, EnumStates nextState)
        : BaseEntityState(parent, enumTexture, nextState)
{

}

void EntityAliveState::update(sf::Time dt)
{
    _parent->move(_parent->getVelocity() * dt.asSeconds());
}


