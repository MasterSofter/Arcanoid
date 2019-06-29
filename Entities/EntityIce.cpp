#include "EntityIce.h"
#include "../Game.h"

EntityIce::EntityIce(Game& game, const Vector2f& pos, const Vector2f& size)
    : Entity(game, pos, size, EnumTexture::Ice1)
{
}

void EntityIce::attack()
{
    if(_health <= 0) return;

    _health--;

    if(_health > 0) {

    }
}
