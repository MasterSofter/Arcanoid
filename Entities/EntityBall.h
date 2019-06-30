#ifndef ARCANOID_ENTITYBALL_H
#define ARCANOID_ENTITYBALL_H

#include "Entity.h"

class Game;

class EntityBall : public Entity{
    bool attacks = false;
public:
    EntityBall(Game& game, const Vector2f& pos, const Vector2f& size);

    virtual void update(sf::Time dt);
    virtual void attack();


};


#endif //ARCANOID_ENTITYBALL_H
