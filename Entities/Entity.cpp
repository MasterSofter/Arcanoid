//
// Created by Павел on 2019-06-22.
//

#include "Entity.h"
#include "../RecourceMng.h"
#include "../Game.h"

Entity::Entity(Game& game, const Vector2f& pos, const Vector2f& size, EnumTexture enumTexture)
    : _game(game), _pos(pos), _size(size), _health(1)
{
    const Texture& texture = RecourceMng::Instance().GetTexture(enumTexture);
    _sprite.setTexture(texture);

    Vector2u ts = texture.getSize();
    _sprite.setScale(size.x/ts.x, size.y/ts.y);
}

bool Entity::exist() const {
    return _health > 0;
}

Sound* Entity::sound() {
    //Todo: Не забыть реальзацию звука
    return nullptr;
}

void Entity::animation() {
    //Todo: Не забыть про анимацию обьектов
}

void Entity::setPosition(Vector2f pos){
    _pos = pos;
    _sprite.setPosition(_pos);
}

Vector2f Entity::getPosition() const {
    return _pos;
}

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

void Entity::accelerate(sf::Vector2f velocity)
{
    _velocity += velocity;
}

void Entity::move(Vector2f offset)
{
    setPosition(getPosition() + offset);
}

void Entity::update(sf::Time dt)
{
    move(_velocity * dt.asSeconds());
}

const Vector2f& Entity::size() const {
    return _size;
}
/*
void Entity::setScale(Vector2f scale)
{
    _sprite.setScale(scale);
    _size = Vector2f(_texture.getSize().x * scale.x, _texture.getSize().y * scale.y);
}
*/
void Entity::draw(RenderWindow &app) {
    app.draw(_sprite);
}

void Entity::setOrigin(Vector2f pos) {
    _sprite.setOrigin(pos);
}

FloatRect Entity::getRect() const
{
    return FloatRect(_pos.x, _pos.y, _size.x, _size.y);
}
/*
Sprite* Entity::getSprite() {
    return &_sprite;
}
*/
int Entity::getHealth() {
    return _health;
}
void Entity::setHealth(int id) {
    _health = id;
}

int Entity::getName() {
    return _name;
}

void Entity::setName(int id) {
    _name = id;
}

bool Entity::collision(Entity *ent) {
    if(!exist())
        return false;
    return getRect().intersects(ent->getRect());
}

void Entity::attack()
{
}