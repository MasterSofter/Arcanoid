#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "ObjectBuilder.h"
#include "Game.h"
#include <iostream>
#include <time.h>
#include <SFML/Window/Mouse.hpp>
#include "SFML/System/Clock.hpp"

using namespace sf;
int main() {
    srand(time(0));

    float dt;

    RenderWindow wnd(VideoMode(1240, 720), "Ackanoid!");

    Game game(wnd);
    game.createGameField();
    Mouse mouse;
    Clock clock;

    while (wnd.isOpen())
    {
        Event e;
        while (wnd.pollEvent(e))
        {
            if (e.type == Event::Closed)
                wnd.close();
        }

        game.update(dt, mouse.getPosition(wnd), mouse.isButtonPressed(Mouse::Button::Left));
        game.draw();
        clock.restart();
    }

    return 0;
}