//
// Created by Павел on 2019-06-22.
//

#include "Game.h"
#include "ObjectBuilder.h"
#include "Cell.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameBuilder.h"
#include <SFML/Graphics/Rect.hpp>
#include "Entities/Entity.h"
#include <stdlib.h>
#include <SFML/Window/Mouse.hpp>
#include "RecourceMng.h"

using  namespace sf;
using namespace std;

Game::Game(RenderWindow& _wnd)
    : wnd(_wnd)
{
}

Game::~Game(){
    delete background;
    for(list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
        delete *it;
}

//bool contain(Vector2f object, Vector2f intersection)
//{

//}

RenderWindow& Game::getWindow() const
{
    return wnd;
}

EntityPlayer* Game::getPlayer()
{
    return player;
}

void Game::createGameField() {

    randomGanerate();

    Vector2u size = wnd.getSize();
    Vector2f gameSize(size.x/2 + 50, size.y - 50);

    ObjectBuilder objectBuilder(*this);

    background = objectBuilder.createBackground(Vector2f(size.x, size.y));
    road = objectBuilder.createRoad(Vector2f(20, 0), Vector2f(100, size.y));

    player = objectBuilder.createPlayer(Vector2f(0, size.y/2), Vector2f(160, 170));
    ball = objectBuilder.createBall(Vector2f(player->getPosition().x + player->size().x, player->getPosition().y + player->size().y/2), Vector2f(40, 40));

    GameBuilder gameBuilder(this, Vector2f(size.x/2-75, 25), gameSize);
    gameBuilder.BuildObjectList(ice);
}

void Game::play(EnumSound soundId)
{
    _sounds.push_back(new Sound(RecourceMng::Instance().GetSound(soundId)));
    _sounds.back()->play();
}

const list<Entity*>& Game::getEntities() const
{
    return ice;
}

void Game::processInput(sf::Time dt)
{
    Event e;
    while (wnd.pollEvent(e))
    {
        if (e.type == Event::Closed)
            wnd.close();
    }

    Mouse mouse;
    mouseVelocity = (mouse.getPosition(wnd) - mousePosition) * 10;
    mousePosition = mouse.getPosition(wnd);
    leftButtonPressed = mouse.isButtonPressed(Mouse::Button::Left);
}

void Game::update(sf::Time dt) {
    _countAnimation++;

    player->move(Vector2f(player->getPosition().x, mousePosition.y - player->size().y/2) - player->getPosition());
    player->setVelocity(Vector2f(mouseVelocity.x,mouseVelocity.y));

    if (leftButtonPressed == true) { gameStarted = true; }

    if (!gameStarted)
    {
        ball->setPosition(Vector2f(player->getPosition().x + player->size().x, player->getPosition().y + player->size().y/2 - ball->size().y/4));
        return;
    }

    ball->update(dt);

    /// удалить лишние объекты
    list<Entity*> destroyed;
    for(list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
    {
        if((*it)->destroyed())
            destroyed.push_back(*it);
    }

    for(list<Entity*>::iterator it = destroyed.begin(); it != destroyed.end(); it++)
    {
        delete *it;
        ice.remove(*it);
    }

    /// удалить законившиеся звуки
    list<Sound*> delsounds;
    for(list<Sound*>::iterator it = _sounds.begin(); it != _sounds.end(); it++)
    {
        if((*it)->getStatus() == sf::Sound::Stopped)
            delsounds.push_back(*it);
    }

    for(list<Sound*>::iterator it = delsounds.begin(); it != delsounds.end(); it++)
    {
        delete *it;
        _sounds.remove(*it);
    }
/*
    player->setPosition(Vector2f(player->getPosition().x - player->size().x/2,player->getPosition().y - player->size().y/2));


    if(ball->getRect().intersects(player->getRect()) && dx < 0.f)
    {
        dx = -dx;
    }


    ball->move(Vector2f(0, dy));
    for (list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
    {

        animation(*it);

        if ( ball->getRect().intersects((*it)->getRect()) && (*it)->exist)
        {

            if((*it)->getHealth() < 2)
            {(*it)->setHealth((*it)->getHealth()+1);}
            else
            {
                if((*it)->getName() == iceObj)
                    (*it)->setPosition(Vector2f(-10000,0));
                if((*it)->getName() == gnomIceObj && (*it)->getHealth() == 2) {
                    (*it)->exist = false;
                }
            }

            ObjectBuilder objectBuilder;

            if((*it)->getName() == iceObj)
                (*it)->setTexture(*(objectBuilder.CreateObject(iceObj,(*it)->getHealth(),(*it)->getPosition(),(*it)->size())->getTexture()));
            else if((*it)->getName() == gnomIceObj)
            {
                (*it)->setTexture(*(objectBuilder.CreateObject(gnomIceObj,(*it)->getHealth(),(*it)->getPosition(),(*it)->size())->getTexture()));

            }
            dy = -dy;
            float old_dx = dx;

            dx = rand()%3+1;
            if(old_dx > 0 && dx < 0)
                dx = -dx;
            else if(old_dx < 0 && dx > 0)
                dx = -dx;


            if(dx > 0 && dx < 2){dx = 2;}
            else if(dx < 0 && dx > -2){dx = -2;}

            break;
        }
    }

    if(ball->getRect().intersects(player->getRect())&& attack == false)
    {
        dy = -dy;
    }

    player->setPosition(Vector2f(player->getPosition().x + player->size().x/2,player->getPosition().y + player->size().y/2));
    */
}

void Game::draw()
{
    wnd.clear();

    background->draw(wnd);
    road->draw(wnd);
    player->draw(wnd);

    for(list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
        (*it)->draw(wnd);

    ball->draw(wnd);
    wnd.display();
}
/*
void Game::animation(Entity* it) {
    ObjectBuilder objectBuilder(*this);
    if(!(it)->exist && (it)->getHealth() < 6 && _countAnimation > 30)
    {

            (it)->setTexture(*(objectBuilder.CreateObject(gnomIceObj,(it)->getHealth(),(it)->getPosition(),(it)->size())->getTexture()));
            (it)->setHealth((it)->getHealth() + 1);
            (it)->draw(wnd);
        _countAnimation = 0;

    }
    if((it)->getHealth() >= 6)
        it->setPosition(Vector2f(-10000,0));



}
*/
void Game::randomGanerate() {
    int countIce;
    countIce = 0 + rand() % 48;
    while(countIce > 49)
    {
        countIce = 0 + rand() % 49;
    }
    cout<< countIce<<endl;
}
