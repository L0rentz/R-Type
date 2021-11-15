/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCE-5-1-rtype-antonin.fille
** File description:
** EntityFactory
*/

#include "EntityFactory.hpp"

EntityFactory::EntityFactory()
{
    _cmd.emplace("player", &EntityFactory::getPlayer);
    _cmd.emplace("playerbullet", &EntityFactory::getBullet);
}

EntityFactory::~EntityFactory()
{
}

std::shared_ptr<IClientEntity> EntityFactory::getEntityByType (const std::string &type, const sf::Vector2f &pos, const sf::Color &startColor, const sf::Color &endColor)
{
    EntityFactory::factoryF func = _cmd[type];

    return ((this->*func)(pos, startColor, endColor));
}

std::shared_ptr<IClientEntity> EntityFactory::getPlayer(const sf::Vector2f &pos, const sf::Color &startColor, const sf::Color &endColor)
{
    std::shared_ptr<IClientEntity> entity(new PlayerShip(AssetManager<sf::Texture>::getAssetManager().getAsset("assets/game/ship.png"), pos, startColor, endColor));
    return (entity);
}

std::shared_ptr<IClientEntity> EntityFactory::getBullet(const sf::Vector2f &pos, const sf::Color &startColor, const sf::Color &endColor)
{
    std::shared_ptr<IClientEntity> entity(new Bullet(AssetManager<sf::Texture>::getAssetManager().getAsset("assets/menu/scroll_arrow_white.png"), pos, startColor, endColor));
    return (entity);
}
