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
#include <stdlib.h>

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

    Vector2u size = app.getSize();
    Vector2f gameSize(size.x/2 + 50, size.y - 50);

    GameBuilder gameBuilder(Vector2f(size.x/2-75, 25), gameSize);
    gameBuilder.BuildObjectList(ice);

    road->setPosition(Vector2f(20, 0));
    player->setPosition(Vector2f(road->getPosition().x + road->size().x/2.f, size.y/2));
}

void GameField::update(float dt, Vector2i pos, bool pressed) {

    //player->setPosition(Vector2f(0, pos.y));
    player->move(Vector2f(player->getPosition().x, pos.y) - player->getPosition());

    if(!gameStarted)
    {

    } else{

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