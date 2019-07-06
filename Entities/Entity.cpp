//
// Created by Павел on 2019-06-22.
//

#include "Entity.h"
#include "../RecourceMng.h"
#include "../Game.h"
#include "../Entities/States/EntityAliveState.h"

Entity::Entity(Game& game, const Vector2f& pos, const Vector2f& size, EnumTexture texture, EnumStates nextState)
    : _game(game), _size(size), _destroyed(false)
{
    _state = new EntityAliveState(this, texture, nextState);
}

void Entity::switchToState(EnumStates state)
{
}

bool Entity::exist() const {
    return _state->exist();
}

bool Entity::destroyed() const
{
    return _destroyed;
}
/*
Sound* Entity::sound() {
    //Todo: Не забыть реальзацию звука
    return nullptr;
}

void Entity::animation() {
    //Todo: Не забыть про анимацию обьектов
}
*/
void Entity::setVelocity(sf::Vector2f velocity)
{
    _velocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
    _velocity.x = x;
    _velocity.y = y;
}

sf::Vector2f Entity::getVelocity() const
{
    return _velocity;
}
/*
void Entity::accelerate(sf::Vector2f velocity)
{
    _velocity += velocity;
}
*/
void Entity::move(Vector2f offset)
{
    setPosition(getPosition() + offset);
}

void Entity::setPosition(Vector2f pos){
    _position = pos;
    _state->setPosition(pos);
}

Vector2f Entity::getPosition() const {
    return _position;
}

void Entity::update(sf::Time dt)
{
    _state->update(dt);
}

const Vector2f& Entity::size() const {
    return _size;
}
/*
void Entity::setScale(Vector2f scale)
{
    _sprite.setScale(scale);
    _size = Vector2f(_sprite.getTexture()->getSize().x * scale.x, _sprite.getTexture()->getSize().y * scale.y);
}
*/
void Entity::draw(RenderWindow &wnd) {
    _state->draw(wnd);
}
/*
void Entity::setOrigin(Vector2f pos) {
    _sprite.setOrigin(pos);
}
*/
FloatRect Entity::getRect() const
{
    return FloatRect(_position.x, _position.y, _size.x, _size.y);
}
/*
Sprite* Entity::getSprite() {
    return &_sprite;
}
*/
/*
int Entity::getName() {
    return _name;
}

void Entity::setName(int id) {
    _name = id;
}
*/
bool Entity::collision(Entity *ent) {
    if(!exist())
        return false;
    return getRect().intersects(ent->getRect());
}

void Entity::attack()
{
}