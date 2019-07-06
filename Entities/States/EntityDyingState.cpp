//
// Created by Павел on 2019-07-06.
//

#include "EntityDyingState.h"
#include "EnumStates.h"

EntityDyingState::EntityDyingState(Entity* parent, EnumTexture enumTextures[], int count, EnumStates nextState)
    : BaseEntityState(parent, None, nextState)
{
    for(int i = 0; i < count; i++)
        _enumTextures.push_back(enumTextures[i]);
}

void EntityDyingState::update(sf::Time dt)
{
    //_parent->switchToState(EnumStates::Destroyed);
}

void EntityDyingState::draw(RenderWindow& wnd) {

}

bool EntityDyingState::exist() const
{
    return false;
}
