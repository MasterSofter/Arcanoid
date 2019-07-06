#include "iostream"
#include "EntityBall.h"
#include "../Game.h"
#include "../Utils.h"
#include "../RectSide.h"
#include <math.h>

using  namespace std;

EntityBall::EntityBall(Game& game, const Vector2f& pos, const Vector2f& size)
        : Entity(game, pos, size, Ball)
{
}
/*
void EntityBall::attack()
{
}
*/
void EntityBall::update(sf::Time dt)
{
    EntityPlayer* player = _game.getPlayer();
    //player->setHealth(1);
    attacks = false;
    //RectSide rectSide;
    Vector2u wndSize = _game.getWindow().getSize();

    move(_velocity * dt.asSeconds());

    /// найдем пересечение мяча и какого-либо объекта
    const list<Entity*>& ents = _game.getEntities();

    float dx =_velocity.x * dt.asSeconds();
    float dy =_velocity.y * dt.asSeconds();

    move(Vector2f(dx, 0));
    for (list<Entity*>::const_iterator it = ents.begin(); it != ents.end(); it++)
    {
        if ( (*it)->collision(this) && attacks == false && (*it)->exist())
        {
            (*it)->attack();
            attacks = true;

            _velocity.x = -_velocity.x;
            float old_dy = dy;

            //_velocity.y = rand()%50;
            dy = _velocity.y * dt.asSeconds();
            if(old_dy > 0 && dy < 0)
                _velocity.y = -_velocity.y;
            else if(old_dy < 0 && dy > 0)
                _velocity.y = -_velocity.y;

            break;
        }
    }

    move(Vector2f(0, dy));

    for (list<Entity*>::const_iterator it = ents.begin(); it != ents.end(); it++)
    {
        if ( (*it)->collision(this) && attacks == false && (*it)->exist())
        {
            (*it)->attack();
            attacks = true;

            _velocity.y = -_velocity.y;
            float old_dx = dx;

            //_velocity.x = rand()%50;
            dx = _velocity.y * dt.asSeconds();
            if(old_dx > 0 && dx < 0)
                _velocity.x = -_velocity.x;
            else if(old_dx < 0 && dx > 0)
                _velocity.x = -_velocity.x;
            break;
        }
    }

    ///Расчитываем удар о тележку
    if(player->collision(this))
    {
        if(getPosition().x < player->getPosition().x + player->size().x)
        {
            ///Расчет удара о тележку сбоку
            if(getPosition().y > player->getPosition().y && getPosition().y < player->getPosition().y + player->size().y ||
               getPosition().y + size().y > player->getPosition().y && getPosition().y + size().y < player->getPosition().y + player->size().y)
            {
                if(_velocity.x < 0)
                    _velocity.x = -_velocity.x;
                _velocity.y = _velocity.y + player->getVelocity().y;
            }
        }
    }

    if(player->getPosition().y < 0)
        player->setPosition(Vector2f(player->getPosition().x,0));
    if(player->getPosition().y + player->size().y > wndSize.y)
        player->setPosition(Vector2f(player->getPosition().x,wndSize.y - player->size().y));

    if(_velocity.y > 0 && _velocity.y < 200 || _velocity.y > 600)
        _velocity.y = 200;
    if(_velocity.y < 0 && _velocity.y > -200 || _velocity.y < -600)
        _velocity.y = -200;
    if(_velocity.x > 0 && _velocity.x < 200 || _velocity.x > 600)
        _velocity.x = 200;
    if(_velocity.x < 0 && _velocity.x > -200 ||  _velocity.x < -600)
        _velocity.x = -200;

    ///Расчитываем удар о стены
    if(getPosition().x < 0 || getPosition().x + size().x > wndSize.x)
        setVelocity(-_velocity.x, _velocity.y);
    else if(getPosition().y < 0 || getPosition().y + size().y > wndSize.y)
        setVelocity(_velocity.x, -_velocity.y);
}
