//
// Created by Павел on 2019-07-06.
//

#ifndef ARCANOID_ENTITYDYINGSTATE_H
#define ARCANOID_ENTITYDYINGSTATE_H

#include "BaseEntityState.h"
#include <vector>

using namespace std;

class EntityDyingState : public BaseEntityState {
private:
    vector<EnumTexture> _enumTextures;

public:
    EntityDyingState(Entity* parent, EnumTexture enumTextures[], int count, EnumStates nextState);
    virtual void draw(RenderWindow& wnd);
    virtual void update(sf::Time dt);
    virtual bool exist() const;
};


#endif //ARCANOID_ENTITYDYINGSTATE_H
