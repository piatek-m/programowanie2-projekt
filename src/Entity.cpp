#include "Entity.h"

const std::string &Entity::getClassName() const
{
    return m_className;
}

int Entity::getHealthPoints() const
{
    return healthPoints;
}

double Entity::getMoveSpeed() const
{
    return moveSpeed;
}

void Entity::setHealthPoints(int damage)
{
    healthPoints = healthPoints - damage;
}