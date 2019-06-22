//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_GAMEFIELDBUILDER_H
#define ARCANOID_GAMEFIELDBUILDER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "Object.h"

using namespace sf;

class GameField {
    RenderWindow& app;
    Object* background;
    int _countIce;
    Object* ice[100][100];


public:
    //RenderWindow* app;
    void createGameField(int countIce);
    void update(float dt);
    void draw();

public:
    GameField(RenderWindow& app);
    ~GameField();

};

#endif //ARCANOID_GAMEFIELDBUILDER_H
