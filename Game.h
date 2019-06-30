//
// Created by Павел on 2019-06-22.
//

#ifndef ARCANOID_GAMEFIELDBUILDER_H
#define ARCANOID_GAMEFIELDBUILDER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Entities/Entity.h"
#include "Entities/EntityBall.h"
#include "Entities/EntityPlayer.h"
#include <list>

using namespace sf;
using namespace std;

class Game {
    RenderWindow& wnd;
    Entity* background;
    Entity* road;
    EntityPlayer* player;
    EntityBall* ball;

    float dx = 2, dy = 0;

    bool gameStarted = false;
    Vector2u _size = wnd.getSize();
    list<Entity*> ice;
    list<Entity*> _listObj;

    Vector2i mousePosition;
    bool leftButtonPressed;

    const int iceObj = 0;
    const int gnomIceObj = 1;
    int _countAnimation = 0;

public:
    RenderWindow& getWindow() const;
    const list<Entity*>& getEntities() const;
    EntityPlayer* getPlayer();
    void createGameField();
    void processInput();
    void update(sf::Time dt);
    void draw();
    //void animation(Entity* it);
    void randomGanerate();

public:
    Game(RenderWindow& wnd);
    ~Game();

};



#endif //ARCANOID_GAMEFIELDBUILDER_H
