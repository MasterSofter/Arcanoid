#include "GameBuilder.h"
#include "ObjectBuilder.h"

GameBuilder::GameBuilder(Vector2f origin, Vector2f size)
    : _origin(origin),
      _size(size)
{

}

void GameBuilder::BuildObjectList(list<Entity*>& list)
{
    ObjectBuilder objectBuilder;

    float deltaX = _size.x / 8;
    float deltaY = _size.y / 8;

    // размер ячейки сетки
    float dx = deltaX - 10;
    float dy = deltaY - 10;

    Vector2f position = _origin;

    for(int i = 0 ; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Vector2f pos = position + Vector2f(5,5);
            Vector2f size = Vector2f(dx-10, dy-10);

            switch (GameField_01[j][i])
            {
                case 1:
                    list.push_back(objectBuilder.createIce(pos, size));
                    break;

                case 2:
                    list.push_back(objectBuilder.createIceWithGnom(pos, size));
                    break;
            }

            position.x += deltaX;
        }

        position.x = _origin.x;
        position.y += deltaY;
    }
}

