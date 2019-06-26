//
// Created by Павел on 2019-06-22.
//

#include "Entity.h"




Sound Entity::sound() {
    //Todo: Не забыть реальзацию звука
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

void Entity::move(Vector2f offset)
{
    setPosition(getPosition() + offset);
}

Entity::Entity(const char* imageName)
    : _pos(0,0), _health(0)
{
    _image.loadFromFile(imageName);
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);

    _size.x = _texture.getSize().x;
    _size.y = _texture.getSize().y;
}

Vector2f Entity::size() const {
    return _size;
}

void Entity::setSize(Vector2f size)
{
    setScale(Vector2f(size.x/_texture.getSize().x, size.y/_texture.getSize().y));
}

void Entity::setScale(Vector2f scale)
{
    _sprite.setScale(scale);
    _size = Vector2f(_texture.getSize().x * scale.x, _texture.getSize().y * scale.y);
}

void Entity::draw(RenderWindow &app) {
    app.draw(_sprite);
}

void Entity::setOrigin(Vector2f pos) {
    _sprite.setOrigin(pos);
}

FloatRect Entity::getRect() const
{
    return FloatRect(_pos, _size);
}

Sprite* Entity::getSprite() {
    return &_sprite;
}

int Entity::getHealth() {
    return _health;
}
void Entity::setHealth(int id) {
    _health = id;
}

void Entity::setTexture(Texture &texture) {
    _texture = texture;
}

Texture* Entity::getTexture() {
    return &_texture;
}