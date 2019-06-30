#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>
#include "Entities/Entity.h"
#include "ObjectBuilder.h"
#include "Game.h"
#include <iostream>
#include <time.h>
#include "SFML/System/Clock.hpp"
#include "RecourceMng.h"

using namespace sf;
int main() {
    srand(time(0));

    float dt;

    RenderWindow wnd(VideoMode(1600, 1000), "Ackanoid!");
    RecourceMng::Instance().Init();

    Game game(wnd);
    game.createGameField();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f/60.f);

    while (wnd.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        while (timeSinceLastUpdate >= timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            game.processInput();
            game.update(timePerFrame);
        }

        game.draw();
    }

    return 0;
}