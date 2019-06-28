//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_OBJECT_H
#define ARCANOID_OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Rect.hpp>

using namespace sf;

class Entity {

private:
    Image _image;
    Texture _texture;
    Sprite _sprite;
    int _name;

    Vector2f _size;
    Vector2f _pos;
    int _health;
public:
    bool exist = true;
    Entity(const char* imageName);
    Sound sound();
    void animation();
    void setPosition(Vector2f pos);
    Vector2f getPosition() const;
    Vector2f size() const;

    Sprite* getSprite();
    FloatRect getRect() const;
    void setSize(Vector2f size);
    void move(Vector2f offset);
    void setScale(Vector2f scale);
    void setOrigin(Vector2f pos);
    void draw(RenderWindow& app);
    Texture* getTexture();
    void setTexture(Texture& texture);
    int getHealth();
    void setHealth(int id);
    int getName();
    void setName(int id);
};


#endif //ARCANOID_OBJECT_H
