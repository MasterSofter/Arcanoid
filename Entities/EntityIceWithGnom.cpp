#include "EntityIceWithGnom.h"
#include "../Game.h"
#include "../RecourceMng.h"
#include "../Entities/States/EntityAliveState.h"
#include "States/EntityAliveState.h"
#include "States/EntityDyingState.h"
#include "States/EntityDestroyedState.h"

EntityIceWithGnom::EntityIceWithGnom(Game& game, const Vector2f& pos, const Vector2f& size)
        : Entity(game, pos, size, IceWithGnom1, StateIce2)
{
}

void EntityIceWithGnom::attack()
{
    _state->attack();
    _game.play(SoundIceKnock);
}

void EntityIceWithGnom::switchToState(EnumStates state)
{
    if(state == EnumStates::StateNothing) return;

    delete _state;

    switch (state)
    {
        case StateDestroyed:
            _state = new EntityDestroyedState(this);
            _destroyed = true;
            break;

        case StateIce2:
            _state = new EntityAliveState(this, IceWithGnom2, StateIce3);
            break;

        case StateIce3:
            _state = new EntityAliveState(this, IceWithGnom3, StateDying);
            break;

        case StateDying:
            EnumTexture textures[] = { IceDestroyed1, IceDestroyed2, IceDestroyed3, IceDestroyed4, IceDestroyed5 };
            _state = new EntityDyingState(this, textures, 5, StateDestroyed);
            break;
    }
}

