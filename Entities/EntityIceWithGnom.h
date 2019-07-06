#ifndef ARCANOID_ENTITYICEWITHGNOM_H
#define ARCANOID_ENTITYICEWITHGNOM_H

#include "Entity.h"

class Game;

class EntityIceWithGnom : public Entity{
public:
    EntityIceWithGnom(Game& game, const Vector2f& pos, const Vector2f& size);
    virtual void attack();
    virtual void switchToState(EnumStates state);
};

#endif //ARCANOID_ENTITYICEWITHGNOM_H
