#include "EntityIce.h"
#include "../Game.h"
#include "../RecourceMng.h"
#include "../EnumTexture.h"


EntityIce::EntityIce(Game& game, const Vector2f& pos, const Vector2f& size)
    : Entity(game, pos, size, EnumTexture::Ice1)
{
}

void EntityIce::attack() {

    _game.play(SoundIceKnock);

    _health--;

    switch(_health){
        case 2:
            _sprite.setTexture(RecourceMng::Instance().GetTexture(Ice2));
        break;
        case 1:
            _sprite.setTexture(RecourceMng::Instance().GetTexture(Ice3));
        break;

    }
    if(_health <= 0)
    {
        _destroyed = true;
    }
}

