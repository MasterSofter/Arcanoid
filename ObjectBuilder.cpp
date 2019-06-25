//
// Created by Павел on 2019-06-22.
//
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "ObjectBuilder.h"
#include "Entity.h"

Entity* ObjectBuilder::createBackground() {
    Entity* background = new Entity("textures/char_sex.png");
    background->setScale(Vector2f(0.6, 0.7));
    return background;
}

Entity* ObjectBuilder::createIce() {
    Entity* ice = new Entity("textures/ice_01.png");
    return ice;
}

Entity* ObjectBuilder::createRoad(){
    Entity* road = new Entity("textures/char_road.png");
    road->setScale(Vector2f(0.5, 2.6));
    return road;
}

Entity* ObjectBuilder::createPlayer() {
    Entity* player = new Entity("textures/char_hero.png");
    player->setOrigin(player->size()/2.f);
    player->setScale(Vector2f(0.5, 0.5));
    return player;

}

Entity* ObjectBuilder::createBall() {
    Entity* ball = new Entity("textures/ball.png");
    ball->setScale(Vector2f(0.68, 0.68));
    return ball;
}