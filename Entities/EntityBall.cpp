#include "iostream"
#include "EntityBall.h"
#include "../Game.h"
#include "../Utils.h"
#include "../RectSide.h"
#include <math.h>

using  namespace std;

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
    attacks = false;
    RectSide rectSide;
    Vector2u wndSize = _game.getWindow().getSize();

    cout << wndSize.y << endl;


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


    //Если пересечение есть
    if(collisionEntity != nullptr)
    {
        collisionEntity->attack();

        /// расчитываем отскок от льдышек
        Vector2f start = getPosition() + size()/2.f;
        Vector2f pt;
        if(Utils::IntersectRect(start, Utils::normalize(getVelocity()), collisionEntity->getRect(), rectSide))
        {
            Vector2f pos = getPosition();

            if(rectSide.side == Left)
            {
                _velocity.x = -_velocity.x;
            }
            if(rectSide.side == Right)
            {
                _velocity.x = -_velocity.x;
            }

            if(rectSide.side == Top)
            {
                _velocity.y =  -_velocity.y;
            }
            if(rectSide.side == Bottom)
            {
                _velocity.y =  -_velocity.y;
            }
        }
    }


    EntityPlayer* player = _game.getPlayer();
    ///Расчитываем удар о тележку

    if(getPosition().x < player->getPosition().x + player->size().x)
    {
        ///Расчет удара о тележку сбоку
        if(getPosition().y > player->getPosition().y && getPosition().y < player->getPosition().y + player->size().y ||
        getPosition().y + size().y > player->getPosition().y && getPosition().y + size().y < player->getPosition().y + player->size().y)
        {
            if(_velocity.x < 0)
                _velocity.x = -_velocity.x;
        }
        _velocity.y = _velocity.y + player->getVelocity().y;
    }

    if(_velocity.y > 200)
        _velocity.y = 200;
    if(_velocity.y < -200)
        _velocity.y = -200;

    ///Расчитываем удар о стены
    if(getPosition().x < 0 || getPosition().x + size().x > wndSize.x)
        setVelocity(-_velocity.x, _velocity.y);
    else if(getPosition().y < 0 || getPosition().y + size().y > wndSize.y)
        setVelocity(_velocity.x, -_velocity.y);



}
