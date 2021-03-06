/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCE-5-1-rtype-antonin.fille
** File description:
** ServerEntity
*/

#include "ServerEntity.hpp"

ServerEntity::ServerEntity(const CustomRect &rect,
                            const std::string &type,
                            const std::string &id,
                            int speed,
                            int health)
    :   _isAlive(true),  _rect(rect), _type(type), _id(id), _speed(speed), _health(health)
{
    _maxHealth = _health;
    _direction = std::make_pair(0, 0);
    _hasAClock = false;
    _isBoss = false;
    _isMobHarmful = false;
    _isPickable = false;
    _isPlayerHarmful = false;
    _isObstacle = false;
    _isDropping = false;
}

ServerEntity::~ServerEntity()
{
}

bool ServerEntity::hasAClock() const
{
    return (_hasAClock);
}

void ServerEntity::setThreadCount(int *threadCount)
{
    _threadCount = threadCount;
}

int ServerEntity::getMaxHp() const
{
    return (_maxHealth);
}

void ServerEntity::sendData()
{
}

int ServerEntity::getHp() const
{
    return (_health);
}

bool ServerEntity::isAlive() const
{
    return (_isAlive);
}

void ServerEntity::setAlive(bool life)
{
    _isAlive = life;
}

void ServerEntity::addLifeEntity(int lifeAdded)
{
    if (_health > 0) {
        _health += lifeAdded;
        if (_health > _maxHealth)
            _health = _maxHealth;
    } else {
        _isAlive = false;
    }
}

std::string ServerEntity::getId() const
{
    return (_id);
}

void ServerEntity::setId(const std::string id)
{
    _id = id;
}

CustomRect ServerEntity::getRect() const
{
    return (_rect);
}

bool ServerEntity::isColliding(const std::shared_ptr<IEntity> &other) const
{
    return (_rect.isColliding(other->getRect()));
}

void ServerEntity::setDirection(double x, double y)
{
    _direction.first = x;
    _direction.second = y;
}

std::pair<double, double> ServerEntity::getDirection() const
{
    return (_direction);
}

std::pair<double, double> ServerEntity::getPosition() const
{
    return (_rect.getPosition());
}

double ServerEntity::getSpeed() const
{
    return (_speed);
}

void ServerEntity::setPosition(double x, double y)
{
    _rect.setPosition(x, y);
}

std::string ServerEntity::getType() const
{
    return (_type);
}

std::vector<std::shared_ptr<IEntity>> ServerEntity::getAmmos() const
{
    return (_ammos);
}

void ServerEntity::clearAmmos()
{
    _ammos.clear();
}

bool ServerEntity::isBoss() const
{
    return (_isBoss);
}

bool ServerEntity::isPickable() const
{
    return (_isPickable);
}

bool ServerEntity::isPlayerHarmful() const
{
    return (_isPlayerHarmful);
}

bool ServerEntity::isMobHarmful() const
{
    return (_isMobHarmful);
}

bool ServerEntity::isObstacle() const
{
    return (_isObstacle);
}

bool ServerEntity::isDropping() const
{
    return (_isDropping);
}