#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "ObjectBuilder.h"
#include "GameField.h"
#include <iostream>
#include <time.h>
#include <SFML/Window/Mouse.hpp>

using namespace sf;
int main() {
    srand(time(0));

    float dt;
    int countIce = 80;
    RenderWindow app(VideoMode(1240, 720), "Ackanoid!");

    GameField gameField(app);
    gameField.createGameField(countIce);
    Mouse mouse;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        gameField.update(dt, mouse.getPosition(app), mouse.isButtonPressed(Mouse::Button::Left));
        gameField.draw();

    }

    return 0;
}