#ifndef ARCANOID_OBJECTBUILDER_H
#define ARCANOID_OBJECTBUILDER_H

#include "Entities/EntityIce.h"
#include "Entities/EntityIce.h"
#include "Entities/EntityIceWithGnom.h"
#include "Entities/EntityBall.h"
#include "Entities/EntityPlayer.h"

class Game;

class ObjectBuilder{
    Game& _game;
public:
    ObjectBuilder(Game& game);
    EntityIce* createIce(const Vector2f& pos, const Vector2f& size);
    EntityIceWithGnom* createIceWithGnom(const Vector2f& pos, const Vector2f& size);
    EntityBall* createBall(const Vector2f& pos, const Vector2f& size);
    EntityPlayer* createPlayer(const Vector2f& pos, const Vector2f& size);
    Entity* createRoad(const Vector2f& pos, const Vector2f& size);
    Entity* createBackground(const Vector2f& size);

};
#endif //ARCANOID_OBJECTBUILDER_H
