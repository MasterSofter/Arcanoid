#include "EntityPlayer.h"
#include "../Game.h"

EntityPlayer::EntityPlayer(Game& game, const Vector2f& pos, const Vector2f& size)
        : Entity(game, pos, size, EnumTexture::Player)
{
    //Vector2f sz = Vector2f(_sprite.getTexture()->getSize().x * _sprite.getScale().x,
            //_sprite.getTexture()->getSize().y * _sprite.getScale().y);

    //_sprite.setPosition(pos);
    //_sprite.setOrigin(Vector2f(0, (size/2.f).y));
}

void EntityPlayer::attack()
{
    _game.play(SoundKnock);
}



