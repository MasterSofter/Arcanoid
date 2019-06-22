#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include "ObjectBuilder.h"
#include "GameField.h"
#include <iostream>
#include <time.h>
using namespace sf;
int main() {
    srand(time(0));

    float dt;
    int countIce = 80;
    RenderWindow app(VideoMode(1240, 720), "Ackanoid!");

    GameField gameField(app);
    gameField.createGameField(countIce);

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }



        gameField.update(dt);
        gameField.draw();

    }

    return 0;
}