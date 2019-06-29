#include "EntityPlayer.h"
#include "../Game.h"

EntityPlayer::EntityPlayer(Game& game, const Vector2f& pos, const Vector2f& size)
        : Entity(game, pos, size, EnumTexture::Player)
{
}

void EntityPlayer::attack()
{
    if(_health <= 0) return;

    _health--;

    if(_health > 0) {

    }
}
