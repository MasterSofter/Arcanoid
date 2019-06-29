#include "EntityIceWithGnom.h"
#include "../Game.h"

EntityIceWithGnom::EntityIceWithGnom(Game& game, const Vector2f& pos, const Vector2f& size)
        : Entity(game, pos, size, EnumTexture::IceWithGnom1)
{
}

void EntityIceWithGnom::attack()
{
    if(_health <= 0) return;

    _health--;

    if(_health > 0) {

    }
}
