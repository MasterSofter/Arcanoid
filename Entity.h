//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_OBJECT_H
#define ARCANOID_OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Entity {

private:
    Image _image;
    Texture _texture;
    Sprite _sprite;

    Vector2f _size;
    Vector2f _pos;
public:
    Entity(const char* imageName);
    Sound sound();
    void animation();
    void setPosition(Vector2f pos);
    Vector2f getPosition() const;
    Vector2f size() const;
    void setSize(Vector2f size);
    void move(Vector2f offset);
    void setScale(Vector2f scale);
    void setOrigin(Vector2f pos);
    void draw(RenderWindow& app);
};


#endif //ARCANOID_OBJECT_H
