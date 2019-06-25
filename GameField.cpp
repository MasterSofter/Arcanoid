//
// Created by Павел on 2019-06-22.
//

#include "GameField.h"
#include "ObjectBuilder.h"
#include "Cell.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameBuilder.h"
#include <SFML/Graphics/Rect.hpp>
#include <stdlib.h>
using  namespace sf;

using namespace std;

GameField::GameField(RenderWindow& _app)
    : app(_app)
{

}

void GameField::createGameField(int countIce) {

    randomGanerate();

    ObjectBuilder objectBuilder;

    background = objectBuilder.createBackground();
    road = objectBuilder.createRoad();
    player = objectBuilder.createPlayer();
    ball = objectBuilder.createBall();

    Vector2u size = app.getSize();
    Vector2f gameSize(size.x/2 + 50, size.y - 50);

    GameBuilder gameBuilder(Vector2f(size.x/2-75, 25), gameSize);
    gameBuilder.BuildObjectList(ice);

    road->setPosition(Vector2f(20, 0));
    player->setPosition(Vector2f(road->getPosition().x + road->size().x/2.f, size.y/2));
    ball->setPosition(Vector2f(road->getPosition().x + road->size().x/2.f + player->size().x/2, size.y/2));
}

void GameField::update(float dt, Vector2i pos, bool pressed) {

    Vector2u size = app.getSize();
    player->move(Vector2f(player->getPosition().x, pos.y) - player->getPosition());


    Vector2f positionBall;
    bool flagX = false;
    bool flagY = false;
    if (pressed == true) { gameStarted = true; }

    if (!gameStarted) {
        ball->move(Vector2f(ball->getPosition().x, pos.y - 20) - ball->getPosition());
        positionBall = ball->getPosition();

    } else {



       if(ball->getPosition().x < 0 || ball->getPosition().x + ball->size().x > size.x)
           dx = -dx;
       if(ball->getPosition().y < 0 || ball->getPosition().y + ball->size().y > size.y)
           dy = -dy;

        ball->move(Vector2f(dx, 0));
        for (list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
            if ( ball->getRect().intersects((*it)->getRect()))
            {(*it)->setPosition(Vector2f(-10000,0)); dx=-dx; dy =- rand()%5+2;}

        ball->move(Vector2f(0, dy));
        for (list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
            if ( ball->getRect().intersects((*it)->getRect()))
            {(*it)->setPosition(Vector2f(-10000,0)); dy=-dy;}



    }
}


void GameField::draw()
{
    app.clear();

    background->draw(app);
    road->draw(app);
    player->draw(app);


    for(list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
        (*it)->draw(app);

    ball->draw(app);

    app.display();
}

void GameField::randomGanerate() {
    int countIce;
    countIce = 0 + rand() % 48;
    while(countIce > 49)
    {
        countIce = 0 + rand() % 49;
    }
    cout<< countIce<<endl;
}

GameField::~GameField(){
    delete background;
    for(list<Entity*>::iterator it = ice.begin(); it != ice.end(); it++)
        delete *it;
}
