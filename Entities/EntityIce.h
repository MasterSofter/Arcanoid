#ifndef ARCANOID_ENTITYICE_H
#define ARCANOID_ENTITYICE_H

#include "Entity.h"

class Game;

class EntityIce : public Entity{
public:
    EntityIce(Game& game, const Vector2f& pos, const Vector2f& size);
    virtual void attack();
    virtual void switchToState(EnumStates state);
};


#endif //ARCANOID_ENTITYICE_H
