//
// Created by Павел on 2019-06-22.
//

#include "GameField.h"
#include "ObjectBuilder.h"

GameField::GameField(RenderWindow& _app)
    : app(_app)
{

}

void GameField::createGameField(int countIce) {

    ObjectBuilder objectBuilder;

    background = objectBuilder.createBackground();

    for(int i = 0 ; i < countIce; i++)
        ice[i] = objectBuilder.createIce();


    ice[0]->posx = 1025;
    ice[1]->posx = 1025;
    ice[2]->posx = 1025;
    ice[3]->posx = 1025;

    ice[0]->posy = 80;
    ice[1]->posy = 150;
    ice[2]->posy = 220;
    ice[3]->posy = 290;


    for(int i = 0; i < countIce; i++)
    {
        ice[i]->sprite.setPosition(ice[i]->posx,ice[i]->posy);
    }



}

void GameField::update(float dt) {

}

void GameField::draw() {
    app.clear();
    app.draw(background->sprite);
    app.draw(ice[0]->sprite);
    app.draw(ice[1]->sprite);
    app.draw(ice[2]->sprite);
    app.draw(ice[3]->sprite);
    app.display();
}

GameField::~GameField(){

}