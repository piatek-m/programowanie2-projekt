#include "Enemy.h"
#include "Interface.h"
#include <random> // std::mt19937

const StatusEffectType &Enemy::getSelfWeakness() const
{
    return weakness;
}
const StatusEffectType &Enemy::getOnHitDebuffType() const
{
    return debuffType;
}

void Enemy::takeDamage(int damage)
{
    return Entity::takeDamage(damage);
    Interface::updateEnemySection(*this);
}
