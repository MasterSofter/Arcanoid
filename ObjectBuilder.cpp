#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "ObjectBuilder.h"
#include "Entities/Entity.h"
#include "Entities/EntityIce.h"
#include "Game.h"

ObjectBuilder::ObjectBuilder(Game& game)
    : _game(game)
{

}

Entity* ObjectBuilder::createBackground(const Vector2f& size)
{
    Entity* background = new Entity(_game, Vector2f(0,0), size, EnumTexture::Background);
    //background->setScale(Vector2f(0.6, 0.7));
    return background;
}

EntityIce* ObjectBuilder::createIce(const Vector2f& pos, const Vector2f& size) {
    EntityIce* ent = new EntityIce(_game, pos, size);
    ent->setHealth(3);
    return ent;
}

EntityIceWithGnom* ObjectBuilder::createIceWithGnom(const Vector2f& pos, const Vector2f& size)
{
    EntityIceWithGnom* ent = new EntityIceWithGnom(_game, pos, size);
    ent->setHealth(3);
    return ent;
}

Entity* ObjectBuilder::createRoad(const Vector2f& pos, const Vector2f& size)
{
    Entity* road = new Entity(_game, pos, size, EnumTexture::Road);
    //road->setScale(Vector2f(0.5, 2.6));
    return road;
}

EntityPlayer* ObjectBuilder::createPlayer(const Vector2f& pos, const Vector2f& size)
{
    EntityPlayer* player = new EntityPlayer(_game, pos, size);
    return player;

}

EntityBall* ObjectBuilder::createBall(const Vector2f& pos, const Vector2f& size) {
    EntityBall* ball = new EntityBall(_game, pos, size);
    ball->setOrigin(ball->size()/2.f);
    //ball->setScale(Vector2f(0.68, 0.68));
    ball->setVelocity(Vector2f(400, 0));
    return ball;
}
/*
Entity* ObjectBuilder::CreateObject(int object, int id, Vector2f pos, Vector2f size)
{
    Entity* ent;
    ObjectBuilder objectBuilder;

    if(object == 0)
        ent = objectBuilder.createIce(id);
    else if(object == 1)
        ent = objectBuilder.createGnomIce(id);

    ent->setName(object);
    ent->setSize(size);
    ent->setPosition(pos);
    return ent;
}
*/
/*
Entity* ObjectBuilder::createGnomIce(int id)
{
    Entity* gnomice;
    //gnomice->setName(1);
    if(id == 0)
        gnomice = new Entity("textures/gnom_ice_01.png");
    else if(id == 1)
        gnomice = new Entity("textures/gnom_ice_02.png");
    else if(id == 2)
        gnomice = new Entity("textures/gnom_ice_03.png");
    else if(id == 3)
        gnomice = new Entity("textures/gnom_ice_04.png");
    else if(id == 4)
        gnomice = new Entity("textures/gnom_ice_05.png");
    else if(id == 5)
        gnomice = new Entity("textures/gnom_ice_06.png");

    return gnomice;
}
 */