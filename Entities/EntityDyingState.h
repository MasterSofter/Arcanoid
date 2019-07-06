//
// Created by Павел on 2019-07-06.
//

#ifndef ARCANOID_ENTITYDYINGSTATE_H
#define ARCANOID_ENTITYDYINGSTATE_H

#include "BaseEntityState.h"

class EntityDyingState : public BaseEntityState {
public:
    EntityDyingState(Entity* parent);
    virtual void draw();
    virtual void update(sf::Time dt);
};


#endif //ARCANOID_ENTITYDYINGSTATE_H
