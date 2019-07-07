//
// Created by Павел on 2019-07-06.
//

#include "BaseEntityState.h"
#include "../../RecourceMng.h"
#include "../Entity.h"

BaseEntityState::BaseEntityState(Entity* parent, EnumTexture enumTexture, EnumStates nextState):
    _parent(parent), _health(1), _nextState(nextState)
{
    if(enumTexture != None) {
        const Texture &texture = RecourceMng::Instance().GetTexture(enumTexture);
        _sprite.setTexture(texture);

        Vector2u ts = texture.getSize();
        _sprite.setScale(_parent->size().x / ts.x, _parent->size().y / ts.y);
        _sprite.setPosition(_parent->getPosition());
    }
}

void BaseEntityState::draw(RenderWindow& wnd) {
    wnd.draw(_sprite);

//#ifdef DEBUG
    sf::RectangleShape rect;
    rect.setSize(_parent->size());
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(4);
    rect.setOrigin(_sprite.getOrigin());
    rect.setPosition(_parent->getPosition());
    rect.setFillColor(Color(0, 0, 0, 256));
    //wnd.draw(rect);
//#endif
}

bool BaseEntityState::exist() const
{
    return true;
}

void BaseEntityState::setPosition(Vector2f pos){
    _sprite.setPosition(pos);
}

Vector2f BaseEntityState::getPosition() const {
    return _sprite.getPosition();
}

void BaseEntityState::attack()
{
    _parent->switchToState(_nextState);
}
