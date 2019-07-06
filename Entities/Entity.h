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
#include "BaseEntityState.h"

using namespace sf;

class Game;


class Entity {
protected:
    Game& _game;
    BaseEntityState* _state;

    Sprite _sprite;
    int _name;
    bool _destroyed;
    Vector2f _size;
    int _health;
    sf::Vector2f _velocity;

public:
    Entity(Game& game, const Vector2f& pos, const Vector2f& size, EnumTexture enumTexture);

    bool exists = true;
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

    FloatRect getRect() const;
    void move(Vector2f offset);



    int getHealth();
    void setHealth(int id);

    bool exist() const;
    virtual void attack();
    bool destroyed() const;

    void draw(RenderWindow& wnd);
    virtual void update(sf::Time dt);


    void setScale(Vector2f scale);
    void setOrigin(Vector2f pos);
    int getName();
    void setName(int id);

};


#endif //ARCANOID_OBJECT_H
