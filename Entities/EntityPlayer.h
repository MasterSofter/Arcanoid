#ifndef ARCANOID_ENTITYPLAYER_H
#define ARCANOID_ENTITYPLAYER_H

#include "Entity.h"

class Game;

class EntityPlayer : public Entity{
    public:
    EntityPlayer(Game& game, const Vector2f& pos, const Vector2f& size);
    virtual void attack();
};


#endif //ARCANOID_ENTITYPLAYER_H
