//
// Created by Павел on 2019-06-22.
//
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "ObjectBuilder.h"
#include "Object.h"

Object* ObjectBuilder::createBackground() {
    Object* background = new Object();
    background->image.loadFromFile("textures/char_sex.png");
    background->texture.loadFromImage(background->image);
    background->sprite.setTexture(background->texture);
    background->sprite.setScale(0.6,0.7);
    return background;
}

Object* ObjectBuilder::createIce() {
    Object* ice = new Object;
    ice->image.loadFromFile("textures/ice_01.png");
    ice->texture.loadFromImage(ice->image);
    ice->sprite.setTexture(ice->texture);
    return ice;
}