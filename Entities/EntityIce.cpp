#include "EntityIce.h"
#include "../Game.h"
#include "../RecourceMng.h"
#include "../EnumTexture.h"
#include "../Entities/States/EntityAliveState.h"
#include "States/EntityAliveState.h"
#include "States/EntityDyingState.h"
#include "States/EntityDestroyedState.h"


EntityIce::EntityIce(Game& game, const Vector2f& pos, const Vector2f& size)
    : Entity(game, pos, size, Ice1, StateIce2)
{
}

void EntityIce::attack()
{
    _state->attack();
    _game.play(SoundIceKnock);
/*
    _health--;

    switch(_health){
        case 2:
            _sprite.setTexture(RecourceMng::Instance().GetTexture(StateIce2));
        break;
        case 1:
            _sprite.setTexture(RecourceMng::Instance().GetTexture(StateIce3));
        break;
        case 0:
            _destroyed = true;

    }
    if(_health < -5 )
    {
        _destroyed = true;
    }
    */
}

void EntityIce::switchToState(EnumStates state)
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
            _state = new EntityAliveState(this, Ice2, StateIce3);
            break;

        case StateIce3:
            _state = new EntityAliveState(this, Ice3, StateDying);
            break;

        case StateDying:
            EnumTexture textures[] = { IceDestroyed1, IceDestroyed2, IceDestroyed3, IceDestroyed4, IceDestroyed5 };
            _state = new EntityDyingState(this, textures, 5, StateDestroyed);
            break;
    }
}
