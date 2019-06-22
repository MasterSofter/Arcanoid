//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_OBJECT_H
#define ARCANOID_OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
struct Object {

    Image image;
    Texture texture;
    Sprite sprite;

    float sizeX,sizeY;
    float posx,posy;
    Sound sound();
    void animation();

};


#endif //ARCANOID_OBJECT_H
