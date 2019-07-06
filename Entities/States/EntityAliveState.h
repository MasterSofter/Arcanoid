//
// Created by Павел on 2019-07-06.
//

#ifndef ARCANOID_ENTITYALIVESTATE_H
#define ARCANOID_ENTITYALIVESTATE_H

#include "BaseEntityState.h"

class EntityAliveState : public BaseEntityState  {
public:
    EntityAliveState(Entity* parent, EnumTexture enumTexture, EnumStates nextState);
    virtual void update(sf::Time dt);
};


#endif //ARCANOID_ENTITYALIVESTATE_H
