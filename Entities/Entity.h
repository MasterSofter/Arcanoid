//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_OBJECT_H
#define ARCANOID_OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "../EnumTexture.h"

using namespace sf;

class Game;

class Entity {
protected:
    Sprite _sprite;
    int _name;

    Vector2f _size;
    Vector2f _pos;
    int _health;
    sf::Vector2f _velocity;
    Game& _game;

public:
    Entity(Game& game, const Vector2f& pos, const Vector2f& size, EnumTexture enumTexture);

    Sound* sound();
    void animation();
    void setPosition(Vector2f pos);
    Vector2f getPosition() const;
    const Vector2f& size() const;

    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float x, float y);
    void accelerate(sf::Vector2f velocity);
    sf::Vector2f getVelocity() const;
    bool collision(Entity* ent);

    //Sprite* getSprite();
    FloatRect getRect() const;
    void move(Vector2f offset);
    //void setScale(Vector2f scale);
    void setOrigin(Vector2f pos);
    void draw(RenderWindow& app);
    int getHealth();
    void setHealth(int id);
    int getName();
    void setName(int id);
    bool exist() const;

    virtual void update(sf::Time dt);
    virtual void attack();
};


#endif //ARCANOID_OBJECT_H
