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


    float dx =_velocity.x * dt.asSeconds();
    float dy =_velocity.y * dt.asSeconds();

    move(Vector2f(dx, 0));
    for (list<Entity*>::const_iterator it = ents.begin(); it != ents.end(); it++)
    {


        if ( getRect().intersects((*it)->getRect()) && attacks == false)
        {
            (*it)->attack();
            attacks = true;

            dx = -dx;
            float old_dy = dy;

            dy = rand()%2;
            if(old_dy > 0 && dy < 0)
                dy = -dy;
            else if(old_dy < 0 && dy > 0)
                dy = -dy;


            break;
        }
    }




    move(Vector2f(0, dy));
    for (list<Entity*>::const_iterator it = ents.begin(); it != ents.end(); it++)
    {


        if ( getRect().intersects((*it)->getRect()) && attacks == false)
        {
            (*it)->attack();
            attacks = true;

            dy = -dy;
            float old_dx = dx;

            dx = rand()%2;
            if(old_dx > 0 && dx < 0)
                dx = -dx;
            else if(old_dx < 0 && dx > 0)
                dx = -dx;



            break;
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
/*
    if(_velocity.y > 0 && _velocity.y < 400 || _velocity.y > 600)
        _velocity.y = 600;
    if(_velocity.y < 0 && _velocity.y > -400 || _velocity.y < -600)
        _velocity.y = -600;
    if(_velocity.x > 0 && _velocity.x < 400 || _velocity.x > 600)
        _velocity.x = 600;
    if(_velocity.x < 0 && _velocity.x > -400 ||  _velocity.x < -600)
        _velocity.x = -600;
*/
    ///Расчитываем удар о стены
    if(getPosition().x < 0 || getPosition().x + size().x > wndSize.x)
        setVelocity(-_velocity.x, _velocity.y + rand()%400);
    else if(getPosition().y < 0 || getPosition().y + size().y > wndSize.y)
        setVelocity(_velocity.x + rand()%400, -_velocity.y);



}
