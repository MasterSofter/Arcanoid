#include "EntityIceWithGnom.h"
#include "../Game.h"
#include "../RecourceMng.h"

EntityIceWithGnom::EntityIceWithGnom(Game& game, const Vector2f& pos, const Vector2f& size)
        : Entity(game, pos, size, EnumTexture::IceWithGnom1)
{
}

void EntityIceWithGnom::attack()
{
    _game.play(SoundIceKnock);

    _health--;

    switch(_health){
        case 2:
            _sprite.setTexture(RecourceMng::Instance().GetTexture(IceWithGnom2));
            break;
        case 1:
            _sprite.setTexture(RecourceMng::Instance().GetTexture(IceWithGnom3));
            break;

    }
    if(_health <= 0)
    {
        _destroyed = true;
    }
}
