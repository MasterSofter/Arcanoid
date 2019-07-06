
#include "EntityDestroyedState.h"

EntityDestroyedState::EntityDestroyedState(Entity* parent)
        : BaseEntityState(parent, EnumTexture::None, StateNothing)
{
}

void EntityDestroyedState::update(sf::Time dt) {

}

void EntityDestroyedState::draw(RenderWindow& wnd) {

}

bool EntityDestroyedState::exist() const
{
    return false;
}
