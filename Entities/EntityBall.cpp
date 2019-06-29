#include "EntityBall.h"
#include "../Game.h"
#include "../Utils.h"

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

void Entity::update(sf::Time dt)
{
    move(_velocity * dt.asSeconds());

    Vector2u wndSize = _game.getWindow().getSize();

    if(_pos.x < 0 || _pos.x + size().x > wndSize.x)
        setVelocity(-getVelocity().x, getVelocity().y);
    else if(_pos.y < 0 || _pos.y + size().y > wndSize.y)
        setVelocity(getVelocity().x, -getVelocity().y);

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
        return;

    collisionEntity->attack();

    /// расчитываем отскок


    Vector2f start = getPosition() + size()/2.f;
    Vector2f pt;
    if(Utils::IntersectRect(start, Utils::normalize(getVelocity()), collisionEntity->getRect(), pt))
    {

    }

}
