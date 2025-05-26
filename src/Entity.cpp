#include "Entity.h"

const std::string &Entity::getClassName() const
{
    return m_className;
}

int Entity::getHealthPoints() const
{
    return healthPoints;
}

const int Entity::getMaxHEALTH() const
{
    return MAX_HEALTH_POINTS;
}

double Entity::getMoveSpeed() const
{
    return moveSpeed;
}

void Entity::takeDamage(int damage)
{
    healthPoints = healthPoints - damage;
}