#include "EntityBall.h"
#include "../Game.h"
#include "../Utils.h"
#include "../RectSide.h"

EntityBall::EntityBall(Game& game, const Vector2f& pos, const Vector2f& size)
        : Entity(game, pos, size, EnumTexture::Ball)
{
}

void EntityBall::attack()
{
    if(_health <= 0) return;

    _health--;

    if(_health > 0) {

    }
}

void EntityBall::update(sf::Time dt)
{
    RectSide rectSide;
    Vector2u wndSize = _game.getWindow().getSize();

    move(_velocity * dt.asSeconds());

    /// найдем пересечение мяча и какого-либо объекта
    const list<Entity*>& ents = _game.getEntities();

    Entity* collisionEntity = nullptr;
    for (list<Entity*>::const_iterator it = ents.begin(); it != ents.end(); it++)
    {
        if ((*it)->collision(this))
        {
            collisionEntity = *it;
            break;
        }
    }

    if(collisionEntity == nullptr)
    {
        EntityPlayer* player = _game.getPlayer();
        if(player->collision(this))
            collisionEntity = player;
    }


    //Если пересечение есть
    if(collisionEntity != nullptr)
    {
        collisionEntity->attack();

        /// расчитываем отскок
        Vector2f start = getPosition() + size()/2.f;
        Vector2f pt;
        if(Utils::IntersectRect(start, Utils::normalize(getVelocity()), collisionEntity->getRect(), rectSide))
        {
            if(rectSide.side == Left)
            {
                _velocity = Vector2f(-_velocity.x,_velocity.y);
            }
            if(rectSide.side == Right)
            {
                _velocity = Vector2f(-_velocity.x,_velocity.y);
            }
            if(rectSide.side == Top)
            {
                _velocity = Vector2f(_velocity.x,-_velocity.y);
            }
            if(rectSide.side == Bottom)
            {
                _velocity = Vector2f(_velocity.x,-_velocity.y);
            }
        }
    }


    ///Расчитываем удар о стены
    if(getPosition().x < 0 || getPosition().x + size().x > wndSize.x)
        setVelocity(-_velocity.x, _velocity.y);
    else if(getPosition().y < 0 || getPosition().y + size().y > wndSize.y)
        setVelocity(_velocity.x, -_velocity.y);

}
