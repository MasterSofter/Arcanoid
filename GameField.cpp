//
// Created by Павел on 2019-06-22.
//

#include "GameField.h"
#include "ObjectBuilder.h"
#include "Cell.h"

GameField::GameField(RenderWindow& _app)
    : app(_app)
{

}

void GameField::createGameField(int countIce) {

    Cell cell[8][7];
    _countIce = countIce;

    ObjectBuilder objectBuilder;

    background = objectBuilder.createBackground();

    for(int j = 0 ; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
            ice[j][i] = objectBuilder.createIce();
    }



    Vector2u sizeWindow = app.getSize();



    ice[0][0]->posx = sizeWindow.x/2 - 130;
    ice[0][0]->posy = 53;

    float deltaX = 83 + 10;
    float deltaY = 68 + 10;
    float pos_x = ice[0][0]->posx;
    float pos_y = ice[0][0]->posy;

    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 7; i++)
        {
            ice[j][i]->posx = pos_x + deltaX;
            cell[j][i].pointX = pos_x + deltaX;
            pos_x = pos_x + deltaX;
            if(j == 0){deltaY = 0;}
            else
                deltaY = 68 + 10;
            ice[j][i]->posy = pos_y + deltaY;
            cell[j][i].pointY = pos_y + deltaY;
        }
        pos_x = sizeWindow.x/2 - 130;
        pos_y = pos_y + deltaY;
    }





    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 7; i++)
            ice[j][i]->sprite.setPosition(ice[j][i]->posx,ice[j][i]->posy);
    }



}

void GameField::update(float dt) {

}

void GameField::draw() {
    app.clear();
    app.draw(background->sprite);

    for(int j = 0; j < 8; j++) {
        for (int i = 0; i < 7; i++)
            app.draw(ice[j][i]->sprite);
    }
    app.display();
}

GameField::~GameField(){
    delete background;
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 7; i++)
        delete ice[j][i];
    }
}