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

class Game {
    RenderWindow& wnd;
    Entity* background;
    Entity* road;
    Entity* player;
    Entity* ball;
    float dx = 2, dy = 0;

    bool gameStarted = false;
    Vector2i mousepos;
    Vector2u _size = wnd.getSize();
    list<Entity*> ice;
    list<Entity*> _listObj;

    Vector2i mousePosition;
    bool leftButtonPressed;

    const int iceObj = 0;
    const int gnomIceObj = 1;
    int _countAnimation = 0;

public:
    void createGameField();
    void processInput();
    void update(sf::Time dt);
    void draw();
    void animation(Entity* it);
    void randomGanerate();

public:
    Game(RenderWindow& app);
    ~Game();

};



#endif //ARCANOID_GAMEFIELDBUILDER_H
