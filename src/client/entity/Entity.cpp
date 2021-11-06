/*
** EPITECH PROJECT, 2021
** G-JAM-001-NCE-0-2-jam-marton.szuts
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(const sf::Texture &texture, const sf::Vector2f &pos)
{
    _texture = texture;
    _pos = pos;
    _sprite.setTexture(_texture);
    _sprite.setPosition(_pos);
    _clock.restart();
}

Entity::~Entity()
{
}

bool Entity::isMouseOnSprite(sf::RenderWindow *window) const
{
    sf::Vector2i pos = sf::Mouse::getPosition(*window);
    if (_sprite.getGlobalBounds().contains(sf::Vector2f(pos)))
        return (true);
    return (false);
}

sf::FloatRect Entity::getGlobalBounds() const
{
    return (_sprite.getGlobalBounds());
}

bool Entity::isColliding(const Entity &other) const
{
    sf::FloatRect rect1 = getGlobalBounds();
    sf::FloatRect rect2 = other.getGlobalBounds();
    if (rect1.intersects(rect2))
        return (true);
    return (false);
}

float Entity::getElapsedTime() const
{
    return (_clock.getElapsedTime().asSeconds());
}

void Entity::restartClock()
{
    _clock.restart();
}

sf::Vector2f Entity::getPos() const
{
    return (_pos);
}

sf::Vector2f Entity::getSize() const
{
    return (sf::Vector2f{getGlobalBounds().width, getGlobalBounds().height});
}

void Entity::setPos(const sf::Vector2f &pos)
{
    _pos = pos;
    _sprite.setPosition(_pos);
}

void Entity::setColor(const sf::Color &color)
{
    _sprite.setColor(color);
}

void Entity::setRotation(const float &angle)
{
    _sprite.rotate(angle);
}

void Entity::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}