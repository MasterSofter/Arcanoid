#ifndef ARCANOID_ENTITYDESTROYEDSTATE_H
#define ARCANOID_ENTITYDESTROYEDSTATE_H

#include "BaseEntityState.h"


class EntityDestroyedState : public BaseEntityState {
public:
    EntityDestroyedState(Entity* parent);
    virtual void draw(RenderWindow& wnd);
    virtual void update(sf::Time dt);
    virtual bool exist() const;
};


#endif //ARCANOID_ENTITYDESTROYEDSTATE_H
