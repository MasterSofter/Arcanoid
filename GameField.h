//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_GAMEFIELDBUILDER_H
#define ARCANOID_GAMEFIELDBUILDER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Entity.h"
#include <list>

using namespace sf;
using namespace std;

class GameField {
    RenderWindow& app;
    Entity* background;
    Entity* road;
    Entity* player;
    Entity* ball;
    float dx = 1.9, dy = 0;

    bool gameStarted = false;
    Vector2i mousepos;

    list<Entity*> ice;

public:
    void createGameField(int countIce);
    void update(float dt, Vector2i pos, bool pressed);
    void draw();
    void randomGanerate();

public:
    GameField(RenderWindow& app);
    ~GameField();

};

#endif //ARCANOID_GAMEFIELDBUILDER_H
