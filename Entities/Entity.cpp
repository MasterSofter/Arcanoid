//
// Created by Павел on 2019-06-22.
//

#include "Entity.h"
#include "../RecourceMng.h"
#include "../Game.h"
#include "EntityAliveState.h"

Entity::Entity(Game& game, const Vector2f& pos, const Vector2f& size, EnumTexture enumTexture)
    : _game(game), _size(size), _health(1), _destroyed(false)
{
    _state = new EntityAliveState(this);
    const Texture& texture = RecourceMng::Instance().GetTexture(enumTexture);
    _sprite.setTexture(texture);

    Vector2u ts = texture.getSize();
    _sprite.setScale(size.x/ts.x, size.y/ts.y);
    _sprite.setPosition(pos);
}

bool Entity::exist() const {
    return _health >= 1;
}

bool Entity::destroyed() const
{
    return _destroyed;
}

Sound* Entity::sound() {
    //Todo: Не забыть реальзацию звука
    return nullptr;
}

void Entity::animation() {
    //Todo: Не забыть про анимацию обьектов
}

void Entity::setPosition(Vector2f pos){
    _sprite.setPosition(pos);
}

Vector2f Entity::getPosition() const {
    return _sprite.getPosition();
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
    _state->update(dt);
    move(_velocity * dt.asSeconds());
}

const Vector2f& Entity::size() const {
    return _size;
}

void Entity::setScale(Vector2f scale)
{
    _sprite.setScale(scale);
    _size = Vector2f(_sprite.getTexture()->getSize().x * scale.x, _sprite.getTexture()->getSize().y * scale.y);
}

void Entity::draw(RenderWindow &wnd) {
    wnd.draw(_sprite);

//#ifdef DEBUG
    sf::RectangleShape rect;
    rect.setSize(size());
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(4);
    rect.setOrigin(_sprite.getOrigin());
    rect.setPosition(getPosition());
    rect.setFillColor(Color(0, 0, 0, 256));
    //wnd.draw(rect);
//#endif
}

void Entity::setOrigin(Vector2f pos) {
    _sprite.setOrigin(pos);
}

FloatRect Entity::getRect() const
{

    return FloatRect(_sprite.getPosition().x - _sprite.getOrigin().x,
            _sprite.getPosition().y  - _sprite.getOrigin().y,
            _size.x,
            _size.y);
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